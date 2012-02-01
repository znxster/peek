( cp $0 testfile && \
    compress testfile && \
    ../src/peek testfile.Z && \
    rm -f testfile.Z ) >/dev/null 2>&1 || exit 1
