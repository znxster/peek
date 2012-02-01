( cp $0 testfile && \
    compress testfile && \
	( [ -f 'testfile.gz' ] && \
		mv testfile.gz testfile.Z ) && \
    ../src/peek testfile.Z && \
    rm -f testfile.Z ) >/dev/null 2>&1 || exit 1
