( ( 7z a testfile.7z ../src/*.* || 7za a testfile.7z ../src/*.* ) && \
    ../src/peek testfile.7z && \
    rm -f testfile.7z ) >/dev/null 2>&1 || exit 1
