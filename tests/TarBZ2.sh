( tar -jcf testfile.tar.bz2 ../src/*.* 2>/dev/null && \
    cp testfile.tar.bz2 testfile.tbz2 && \
    ../src/peek testfile.tar.bz2 testfile.tbz2 >/dev/null && \
    rm -f testfile.tbz2 testfile.tar.bz2 ) || exit 1
