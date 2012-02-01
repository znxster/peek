( ls ../src/*.* | cpio -o > testfile.cpio && \
    ../src/peek testfile.cpio && \
    rm -f testfile.cpio ) >/dev/null 2>&1 || exit 1
