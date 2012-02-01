( shar ../src/*.* > testfile.shar && \
	../src/peek testfile.shar && \
	rm -f testfile.shar ) >/dev/null 2>&1 || exit 1
