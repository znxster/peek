( rm -f testfile.bz2 && \
    cp $0 testfile && \
    bzip2 testfile && \
    ../src/peek testfile.bz2 >/dev/null && \
    rm -f testfile.bz2 ) || exit 1
