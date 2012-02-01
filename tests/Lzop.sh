( cp $0 testfile && \
	lzop -U testfile && \
	../src/peek testfile.lzo && \
    rm -f testfile.lzo ) >/dev/null 2>&1 || exit 1
