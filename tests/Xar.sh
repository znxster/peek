( xar -cf testfile.xar ../src/*.* && \
    ../src/peek testfile.xar && \
    rm -f testfile.xar ) >/dev/null 2>&1 || exit 1
