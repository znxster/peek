( tar -Zcf testfile.tar.Z ../src/*.* && \
    ../src/peek testfile.tar.Z && \
    rm -f testfile.tar.Z ) >/dev/null 2>&1 || exit 1
