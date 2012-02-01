( cp $0 testfile && \
  ( zzip -q testfile || zzip.exe -q testfile ) && \
    ../src/peek testfile.zz && \
    rm -f testfile.zz testfile ) >/dev/null 2>&1 || exit 1
