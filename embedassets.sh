#!/bin/bash

# USED BY MAKEFILE, DO NOT MOVE OR RENAME
# TODO embedassets.sh: docs

ASSETS_FULL_DIR=$1
shift
ASSET_FILES=$@

> __embeddedassets.c echo '// File created by rule __embeddedassets.o'
>> __embeddedassets.c echo '#include <string.h>'
>> __embeddedassets.c echo '#include "mlx3ds.h"'
>> __embeddedassets.c echo 'const t_embeddedasset *mlx3ds_assets_get(const char *name)'
>> __embeddedassets.c echo '{'
>> __embeddedassets.c echo '    static const t_embeddedasset assets[] = {'
for file in $ASSET_FILES
do
	if [ ! -f $file ]
	then
		continue
	fi
	>> __embeddedassets.c echo -n "{\"$(echo $file | sed -e "s/^${ASSETS_FULL_DIR//\//\\\/}//")\", "
	>> __embeddedassets.c echo -n "$(stat --printf=%s $file)"', '
	>> __embeddedassets.c echo "\"$(< $file xxd -i | sed -ze 's/[, \n\t\r]\+0x/\\x/g')\"},"
done
>> __embeddedassets.c echo '    {NULL, 0, NULL}};'
>> __embeddedassets.c echo '    for (int i = 0; assets[i].name; i++)'
>> __embeddedassets.c echo '        if (!strcmp(assets[i].name, name))'
>> __embeddedassets.c echo '            return &assets[i];'
>> __embeddedassets.c echo '    return NULL;'
>> __embeddedassets.c echo '}'
