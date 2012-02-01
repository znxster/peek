( ar q testfile.a ../src/*.o && \
	 ../src/peek testfile.a && \
    rm -f testfile.a ) >/dev/null 2>&1 || exit 1
