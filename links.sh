# /usr/bin/bash

ASMPATH=$(dirname $0)
cd "$ASMPATH"
ASMPATH=$(pwd)

cd /usr/local/bin

ln -sf "$ASMPATH/as09" as09
