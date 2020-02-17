#!/bin/sh


echo "update MenuSystem submodules ..."
# lib/libosporting/update-submod.sh

echo "update MenuSystem ..."
#git checkout master
#git branch --set-upstream-to=remotes/yhfudev/devel-pc-ext devel-pc-ext
git checkout devel-pc-ext
git pull

#git status lib/libosporting

