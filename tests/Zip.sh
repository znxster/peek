( zip -q testfile.zip ../src/*.* && \
    ../src/peek testfile.zip >/dev/null && \
    rm -f testfile.zip ) || exit 1
