res="/home/artem/Desktop/Uni/ispran/homework/"
echo "doing for $res$1.c"

# make the il
/home/artem/Desktop/Uni/ispran/homework/hope/tmp/scc/bin/scc -w -m qbe -k -c $res$1.c > $res$1.il
if [[ $? != 0 ]]; then
    exit 1
fi

# make the asm
qbe $res$1.il > $res$1.asm
if [[ $? != 0 ]]; then
    exit 1
fi

# make the object from asm
gcc -c -Wall -O0 -g -x assembler $res$1.asm
if [[ $? != 0 ]]; then
    exit 1
fi

# make the object from main.c
gcc -c -Wall -O0 -g main.c -o main.o
if [[ $? != 0 ]]; then
    exit 1
fi

# link the two object files and libqbe and do it with static flag
gcc -Wall -O0 -g $res$1.o main.o /usr/lib/libqbe.a -static -o $res$1.exe
if [[ $? != 0 ]]; then
    exit 1
fi

echo "***********************************************************************"

# run once without the debugger
./$res$1.exe < $res/data.txt
if [[ $? != 0 ]]; then
    exit 1
fi

echo "======================================================================="

# start it in the debugger
gdb -ex 'set args -path /home/artem/Desktop/Uni/ispran/homework/ < data.txt' $res$1.exe
if [[ $? != 0 ]]; then
    exit 1
fi


