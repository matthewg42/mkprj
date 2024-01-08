#
# Copyright 2024 Matthew Gates
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
# associated documentation files (the “Software”), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
# subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all copies or substantial
# portions of the Software.
# 
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
# LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
# NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
# WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
# mcs_prog.sh - Mouse's Common Shell Program Functions
#
# Source this from your bash scripts.
#

if [ ! -n "$MCS_PROG" ]; then
declare MCS_PROG=1
if [ -n "$MCS_DEBUG" ]; then
    echo "mcs_prog.sh: init" 1>&2
fi

[ -n "$PROG_NAME" ] || db ERROR "Your program should define PROG_NAME"
[ -n "$PROG_VERSION" ] || db ERROR "Your program should define PROG_VERSION"
[ -n "$PROG_AUTHOR" ] || db ERROR "Your program should define PROG_AUTHOR"
[ -n "$PROG_COPYRIGHT" ] || db ERROR "Your program should define PROG_COPYRIGHT"

# We have a dependency to mcs_debug.sh
if [ -z "$MCS_DB_LEVEL" ]; then source mcs_db.sh || exit; fi

usage_and_exit () {
    pod2usage -verbose 1 "$0"
    exit "${1:-0}"
}

manual_and_exit () {
    pod2man -c "User Commands" "$0" | nroff -man | "${PAGER:-more}"
    exit "${1:-0}"
}

version_and_exit () {
    echo "$PROG_NAME $PROG_VERSION"
    echo "$PROG_COPYRIGHT"
    echo "Author: $PROG_AUTHOR"
    exit "${1:-0}"
}

fi

