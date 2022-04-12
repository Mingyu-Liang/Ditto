# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([mutated],[1.0.0],[dterei@cs.stanford.edu])

# Set automake options.
AM_INIT_AUTOMAKE([foreign])

# Silent build please
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([no])])

# Set sanity check for a source file.
AC_CONFIG_SRCDIR([client/client.cc])

# Set m4 directory.
AC_CONFIG_MACRO_DIR([m4])

# Set configure output header.
AC_CONFIG_HEADERS([config.h])

# Set some default CXXFLAGS
WARN_FLAGS="-pedantic -Wall -Wextra -Weffc++ -g3"
AC_SUBST([AM_CXXFLAGS], ["$WARN_FLAGS"])

# We set directly (default is 'cru' as 'u' option produces a warning since it's
# ignored when using deterministic libraries).
AC_SUBST([AR_FLAGS], ["cr"])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_LANG([C++])
AX_CXX_COMPILE_STDCXX_14([noext])
AM_PROG_AR
LT_INIT

# Check host.
AC_CANONICAL_HOST

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

# Set output files.
AC_CONFIG_FILES([
  Makefile
  client/Makefile
])

# Produce our configure script.
AC_OUTPUT
