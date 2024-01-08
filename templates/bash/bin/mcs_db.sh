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
# mcs_db.sh - Mouse's Common Shell Debug Functions
#
# Source this from your bash scripts.
#

if [ ! -n "$MCS_DB_LEVEL" ]; then
if [ -n "$MCS_DEBUG" ]; then
    echo "mcs_debug.sh: init" 1>&2
fi

declare -A MCS_DB_DATA
MCS_DB_DATA[FATAL]="-3,31;7m"
MCS_DB_DATA[ERROR]="-2,31m"
MCS_DB_DATA[WARN]="-1,33m"
MCS_DB_DATA[INFO]="0,32m"
MCS_DB_DATA[DB1]="1,2m"
MCS_DB_DATA[DB2]="2,2m"
MCS_DB_DATA[DB3]="3,2m"
MCS_DB_DATA[DB4]="4,2m"
MCS_DB_DATA[DB5]="5,2m"
declare MCS_DB_LEVEL=0
declare MCS_DB_FILE_NO=2 # default stderr
declare MCS_DB_COLOR=auto
declare MCS_DB_TS_FMT="%Y-%m-%dT%T%z"
declare MCS_DB_NAME="${BASH_SOURCE[$((${#BASH_SOURCE[@]}-1))]}"
MCS_DB_NAME="${MCS_DB_NAME##*/}"

# db_setup [-c on|off|auto] [-f fileno] [-n name] [-t fmt] [level]
db_setup () {
    local opt
    while getopts "f:c:t:" opt; do
        case "$opt" in
            c) MCS_DB_COLOR="$OPTARG" ;;
            f) MCS_DB_FILE_NO="$OPTARG" ;;
            n) MCS_DB_NAME="$OPTARG" ;;
            t) MCS_DB_TS_FMT="$OPTARG" ;;
            *) echo "db_setup WARN: bad usage" 1>&2 ;;
        esac
    done
    shift "$((OPTIND-1))"
    local col
    IFS=, read MCS_DB_LEVEL col < <(echo "${MCS_DB_DATA[${1:-INFO}]}")
    if [ "$MCS_DB_LEVEL" -ne "$MCS_DB_LEVEL" ]; then  
        # non-numeric 
        echo "db_setup: WARN '$1' not a valid debug - defaulting to INFO" 1>&2
        MCS_DB_LEVEL=0
    fi
}

db_use_color () {
    case "$MCS_DB_COLOR" in
        on)
            return 0
            ;;
        off)
            return 1
            ;;
        *)
            if [ -t "$MCS_DB_FILE_NO" ]; then
                MCS_DB_COLOR=on
                return 0
            else
                MCS_DB_COLOR=off
                return 1
            fi
            ;;
    esac
}

# db <level> <msg> ...
db () {
    local level="$1"
    shift
    local lev_num
    local col
    IFS=, read lev_num col < <(echo "${MCS_DB_DATA[$level]}")
    if [ ! -n "$lev_num" ]; then
        echo "db: bad level '$level'" 1>&2
        return 1
    fi
    [ "$MCS_DB_LEVEL" -lt "$lev_num" ] && return 0
    if db_use_color; then
        level="\e[${col}$level\e[0m"
    fi
    echo -e "$(date "+$MCS_DB_TS_FMT") $MCS_DB_NAME[$$] $level: $*" 1>&$MCS_DB_FILE_NO
    if [ "$lev_num" -eq -3 ]; then
        exit 1
    fi
}

fi
