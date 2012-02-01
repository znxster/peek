( lha a testfile.lha ../src/* && \
	 ../src/peek testfile.lha && \
    rm -f testfile.lha ) >/dev/null 2>&1 || exit 1
