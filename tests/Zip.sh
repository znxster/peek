( zip -q testfile.zip ../src/*.* && \
    ../src/peek testfile.zip && \
    rm -f testfile.zip ) >/dev/null 2>&1 || exit 1
