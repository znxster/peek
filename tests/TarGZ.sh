( tar -zcf testfile.tar.gz ../src/*.* 2>/dev/null && \
    cp testfile.tar.gz testfile.tgz && \
    ../src/peek testfile.tar.gz testfile.tgz >/dev/null && \
    rm -f testfile.tgz testfile.tar.gz ) || exit 1
