exit 0

# unzoo cant make archive to test
( zoo -add testfile.zoo ../src/*.* && \
    ../src/peek testfile.zoo && \
    rm -f testfile.zoo ) >/dev/null 2>&1 || exit 1
