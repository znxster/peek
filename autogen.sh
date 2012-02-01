#!/bin/sh
echo "Generating configure files... may take a while."
if [ ! -d 'm4' ]; then mkdir m4; fi
autoreconf --install --force --make
