( tar -Zcf testfile.tar.Z ../src/*.* 2>/dev/null && \
    ../src/peek testfile.tar.Z >/dev/null && \
    rm -f testfile.tar.Z ) || exit 1
