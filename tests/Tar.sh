( tar -cf testfile.tar ../src/*.* && \
    ../src/peek testfile.tar && \
    rm -f testfile.tar ) >/dev/null 2>&1 || exit 1
