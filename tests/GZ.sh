( cp $0 testfile && \
    gzip testfile && \
    ../src/peek testfile.gz >/dev/null && \
    rm -f testfile.gz ) || exit 1
