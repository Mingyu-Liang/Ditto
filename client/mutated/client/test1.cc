#include <iostream>
#include <memory>
#include <random>

#include "buffer.hh"
#include "util.hh"

using namespace std;

struct W {
    int n;

    W(void)
      : n{0}
    {
    }
    W(int n_)
      : n{n_}
    {
    }
};

void test_buffer(void)
{
    W n;
    buffer<W, 5> buf;

    buf.queue_emplace(1);
    buf.queue_emplace(2);
    buf.queue_emplace(3);
    buf.queue_emplace(4);
    buf.queue_emplace(5);

    n = buf.dequeue_one();
    cout << "1 = " << n.n << endl;

    buf.queue_emplace(6);
    n = buf.dequeue_one();
    cout << "2 = " << n.n << endl;

    buf.queue_emplace(7);
    n = buf.dequeue_one();
    cout << "3 = " << n.n << endl;

    buf.drop(0);
    buf.drop(1);
    buf.drop(2);
    buf.queue_emplace(8);
    buf.queue_emplace(9);

    for (auto &w : buf) {
        cout << "? = " << w.n << endl;
    }

    cout << "last = " << buf.last()->n << endl;
}

void test_random_share1(mt19937 &rand)
{
    exponential_distribution<double> ed1;
    cout << ed1(rand) << endl;
    cout << ed1(rand) << endl;
    cout << ed1(rand) << endl;
    cout << ed1(rand) << endl;
    cout << ed1(rand) << endl;
    cout << ed1(rand) << endl;
}

void test_random_share2(mt19937 &rand)
{
    exponential_distribution<double> ed1;
    exponential_distribution<double> ed2;
    cout << ed1(rand) << endl;
    cout << ed2(rand) << endl;
    cout << ed2(rand) << endl;
    cout << ed1(rand) << endl;
    cout << ed1(rand) << endl;
    cout << ed2(rand) << endl;
}

class AllocLog
{
  private:
    int id;

  public:
    AllocLog(void)
      : id{0}
    {
        cout << "cons (default)" << endl;
    }

    explicit AllocLog(int id_)
      : id{id_}
    {
        cout << "cons (id)" << endl;
    }

    AllocLog(const AllocLog &a)
      : id{a.id}
    {
        cout << "copy con" << endl;
    }

    AllocLog(AllocLog &&a)
      : id{a.id}
    {
        cout << "move con" << endl;
        a.id = -1;
    }

    AllocLog &operator=(const AllocLog &a)
    {
        cout << "copy =" << endl;
        id = a.id;
        return *this;
    }

    AllocLog &operator=(AllocLog &&a)
    {
        cout << "move =" << endl;
        id = a.id;
        a.id = -1;
        return *this;
    }

    ~AllocLog(void)
    {
        cout << "deconstruct" << endl;
        id = -1;
    }

    static void *operator new(size_t size) // new T
    {
        cout << "new" << endl;
        return malloc(size);
    }

    static void *operator new(size_t size, void *p) // new (p) T
    {
        UNUSED(size);
        cout << "placement-new" << endl;
        return p;
    }

    static void *operator new[](size_t size) // new T[5]
    {
        cout << "new[]" << endl;
        return malloc(size);
    }

    static void *operator new[](size_t size, void *p) // new (p) T[5]
    {
        UNUSED(size);
        cout << "placement-new[]" << endl;
        return p;
    }

    static void operator delete(void *a) // delete t
    {
        cout << "delete" << endl;
        return free(a);
    }

    static void operator delete[](void *a) // delete[] t
    {
        cout << "delete[]" << endl;
        return free(a);
    }
};

/**
 * Test playground.
 */
int main(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    // test AllocLog
    cout << "# a1" << endl; // cons
    AllocLog a1;
    cout << endl;

    cout << "# a2" << endl; // new, cons, decons, delete
    AllocLog *a2 = new AllocLog();
    delete a2;
    cout << endl;

    cout << "# a3" << endl; // copy cons
    AllocLog a3 = a1;
    cout << endl;

    cout << "# a4" << endl; // copy cons
    AllocLog a4(a1);
    cout << endl;

    cout << "# a5" << endl; // move cons
    AllocLog a5(move(a1));
    cout << endl;

    cout << "# a6" << endl; // move cons
    AllocLog a6 = move(a1);
    cout << endl;

    cout << "# a7" << endl; // cons, move =
    AllocLog a7;
    a7 = move(a1);
    cout << endl;

    cout << "# a8"
         << endl; // new[], cons, cons, copy =, decons, decons, delete[]
    AllocLog *a8 = new AllocLog[2];
    a8[0] = a1;
    delete[] a8;
    cout << endl;

    // test Buffer
    cout << "# buffer - init" << endl; // cons[5]
    size_t n = 1;
    buffer<AllocLog, 6> queue;
    cout << endl;

    cout << "# buffer - queue" << endl; // copy =
    AllocLog *b1 = queue.queue(n);
    *b1 = a1;
    cout << endl;

    cout << "# buffer - queue - new" << endl; // cons, move =, decons
    AllocLog *b2 = queue.queue(n);
    *b2 = AllocLog();
    cout << endl;

    cout << "# buffer - queue - placement new" << endl; // placement-new, cons
    AllocLog *b3 = queue.queue(n);
    new (b3) AllocLog();
    cout << endl;

    cout << "# buffer - queue - allocator cons" << endl; // cons
    AllocLog *b4 = queue.queue(n);
    allocator<AllocLog> alloc;
    alloc.construct(b4);
    cout << endl;

    cout << "# buffer - queue_emplace" << endl; // cons (default)
    queue.queue_emplace();
    cout << endl;

    cout << "# buffer - queue_emplace - args" << endl; // cons (id)
    queue.queue_emplace(11);
    cout << endl;

    mt19937 rand1;
    mt19937 rand2 = rand1;

    cout << "# rand 1" << endl;
    test_random_share1(rand1);
    cout << endl;

    cout << "# rand 2" << endl;
    test_random_share2(rand2);
    cout << endl;

    cout << "# done" << endl; // decons*

    test_buffer();
}
