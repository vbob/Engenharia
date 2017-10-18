#!/bin/bash
echo "Compilando "$1
arquivo=${1::-2}
objeto=$arquivo".o"
/usr/bin/as $1 -o $objeto
/usr/bin/ld $objeto -o $arquivo
./$arquivo
echo $?
