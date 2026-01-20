#!/bin/bash

PIPEX=../pipex
TMP=tests

GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"

PASS() { echo -e "${GREEN}✔ PASS${NC} $1"; }
FAIL() { echo -e "${RED}✘ FAIL${NC} $1"; }

mkdir -p $TMP
cd $TMP || exit 1

########################
# Setup
########################
echo -e "hello\nworld\n42\nhello world" > infile
echo -e "apple\nbanana\napple pie" > fruits
touch empty

########################
# Helpers
########################
run_diff() {
    if diff out1 out2 >/dev/null; then
        PASS "$1"
    else
        FAIL "$1"
        echo "---- pipex ----"
        cat out1
        echo "---- bash -----"
        cat out2
    fi
}

########################
# MANDATORY TESTS
########################
echo "===== MANDATORY ====="

$PIPEX infile "cat" "wc -l" out1
< infile cat | wc -l > out2
run_diff "basic"

$PIPEX infile "grep hello" "wc -w" out1
< infile grep hello | wc -w > out2
run_diff "args"

$PIPEX infile "/bin/cat" "wc -l" out1
< infile /bin/cat | wc -l > out2
run_diff "absolute path"

$PIPEX infile "idontexist" "wc -l" out1
< infile idontexist | wc -l > out2
run_diff "invalid cmd1"

$PIPEX infile "cat" "idontexist" out1
< infile cat | idontexist > out2
run_diff "invalid cmd2"

$PIPEX nofile "cat" "wc -l" out1 2>/dev/null
< nofile cat | wc -l > out2 2>/dev/null
run_diff "nofile infile"

touch denied
chmod 000 denied
$PIPEX denied "cat" "wc -l" out1 2>/dev/null
< denied cat | wc -l > out2 2>/dev/null
run_diff "permission denied infile"
chmod 644 denied

$PIPEX empty "cat" "wc -l" out1
< empty cat | wc -l > out2
run_diff "empty infile"

env -i $PIPEX infile "cat" "wc -l" out1 2>/dev/null
env -i < infile cat | wc -l > out2 2>/dev/null
run_diff "no PATH"

########################
# BONUS TESTS
########################
echo "===== BONUS ====="

$PIPEX here_doc EOF "cat" "wc -l" out1 << EOF
hello
world
EOF

cat << EOF | wc -l > out2
hello
world
EOF
run_diff "basic heredoc"

$PIPEX here_doc END "cat" "grep hello" "wc -l" out1 << END
hello
world
hello
END

cat << END | grep hello | wc -l > out2
hello
world
hello
END
run_diff "multi cmd heredoc"

$PIPEX here_doc STOP "cat" out1 << STOP
STOPNOW
STOP
STOP
run_diff "limiter exact match"

$PIPEX here_doc EOF "cat" out1 << EOF
EOF
cat << EOF > out2
EOF
run_diff "empty heredoc"

echo "OLD" > out1
$PIPEX here_doc EOF "cat" out1 << EOF
NEW
EOF
echo -e "OLD\nNEW" > out2
run_diff "append mode"

$PIPEX here_doc EOF "idontexist" "wc -l" out1 << EOF
hello
EOF

cat << EOF | idontexist | wc -l > out2 2>/dev/null
hello
EOF
run_diff "invalid cmd heredoc"

########################
# Cleanup
########################
cd ..
rm -rf $TMP

echo "===== DONE ====="
