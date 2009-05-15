#!/bin/sh

# Check for git and a git repo.
if head=`git rev-parse --verify HEAD 2>/dev/null`; then
	comm=`git log --pretty=oneline -n1 | awk ' { print $1 }'`
	printf "%s" ""`printf "%s" \`git describe --abbrev=4 --match bootmii-\* $comm | awk '{ sub (/bootmii-/, ""); print;}'\``

	# Are there uncommitted changes?
	git update-index --refresh --unmerged > /dev/null
	git diff-index --quiet HEAD ../mini || printf "%s" '*'
fi

echo
