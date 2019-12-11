#!/usr/bin/env bash

URL=$1

printf -v URL_ESCPACED $URL

URL_ESCPACED=$(echo $URL_ESCPACED | sed 's/\\/\\\\\\\\/g')
URL_ESCPACED=$(echo $URL_ESCPACED | sed 's/"/\\\\"/g')

#sed must escape & => \&
URL_ESCPACED=$(echo $URL_ESCPACED | sed 's/&/\\&/g')

URL_ESCPACED=$(echo $URL_ESCPACED | sed 's/@/\\@/g')

# echo $URL_ESCPACED

cat tpn.c | sed "s@::TPL__PLACEHOLDER__@$URL_ESCPACED@" > tmp.c \
&& gcc -o./tpn.out -x c ./tmp.c \
&& ./tpn.out \
&& rm -f ./tpn.out \
&& rm -f ./tmp.c