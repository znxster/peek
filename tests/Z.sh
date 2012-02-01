( cp $0 testfile && \
    compress testfile && \
    ../src/peek testfile.Z >/dev/null && \
    rm -f testfile.Z ) || exit 1
