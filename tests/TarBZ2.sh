( tar -jcf testfile.tar.bz2 ../src/*.* && \
    cp testfile.tar.bz2 testfile.tbz2 && \
    ../src/peek testfile.tar.bz2 testfile.tbz2 && \
    rm -f testfile.tbz2 testfile.tar.bz2 ) >/dev/null 2>&1 || exit 1
