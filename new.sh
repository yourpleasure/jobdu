#!/bin/bash

mkdir $1
cp 1037/Makefile $1/
cd $1
echo "#include<stdio.h>" > Main.c
echo "#include<stdlib.h>" >> Main.c
vim Main.c
