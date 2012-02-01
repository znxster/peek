( cp $0 testfile.asdasd && \
    ../src/peek testfile.asdasd >/dev/null 2>&1 ) || \
( rm -f testfile.asdasd && \
    exit 1 )
