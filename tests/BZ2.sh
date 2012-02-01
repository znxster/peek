( rm -f testfile.bz2 && \
    cp $0 testfile && \
    bzip2 testfile && \
    ../src/peek testfile.bz2 && \
    rm -f testfile.bz2 ) >/dev/null 2>&1 || exit 1
