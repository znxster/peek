( arj a testfile.arj ../src/*.* && \
    ../src/peek testfile.arj && \
    rm -f testfile.arj ) >/dev/null 2>&1 || exit 1
