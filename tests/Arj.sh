( arj a testfile.arj ../src/*.* >/dev/null && \
    ../src/peek testfile.arj >/dev/null && \
    rm -f testfile.arj ) || exit 1
