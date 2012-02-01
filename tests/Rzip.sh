( rm -f testfile.rz && \
    cp $0 testfile && \
    rzip -0 testfile && \
    ../src/peek testfile.rz && \
    rm -f testfile.rz ) >/dev/null 2>&1 || exit 1
