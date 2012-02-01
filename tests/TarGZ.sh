( tar -zcf testfile.tar.gz ../src/*.* && \
    cp testfile.tar.gz testfile.tgz && \
    ../src/peek testfile.tar.gz testfile.tgz && \
    rm -f testfile.tgz testfile.tar.gz ) >/dev/null 2>&1 || exit 1
