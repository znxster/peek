( zoo -add testfile.zoo ../src/*.* >/dev/null 2>&1 && \
    ../src/peek testfile.zoo >/dev/null && \
    rm -f testfile.zoo ) || exit 1
