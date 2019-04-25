cat >Makefile.am <<"EOF"
bin_PROGRAMS=hello
hello_SOURCES=hello.c
EOF

autoscan

sed -e 's/FULL-PACKAGE-NAME/hello/' \
    -e 's/VERSION/1/' \
    -e 's|BUG-REPORT-ADDRESS|/dev/null|' \
    -e '/AC_PROG_CC/i AM_INIT_AUTOMAKE' \
    <configure.scan >configure.ac

touch NEWS README AUTHORS ChangeLog

autoreconf -iv

./configure CFLAGS="-include all_common.h"

make
# make distcheck
