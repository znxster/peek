( cp $0 testfile && \
    gzip testfile && \
    ../src/peek testfile.gz && \
    rm -f testfile.gz ) >/dev/null 2>&1 || exit 1
