( tar -cf testfile.tar ../src/*.* 2>/dev/null && \
    ../src/peek testfile.tar >/dev/null && \
    rm -f testfile.tar ) || exit 1
