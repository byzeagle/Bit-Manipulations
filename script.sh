#! /bin/bash

echo deneme.{1,2,3}
echo deneme.{{1,2,3},{a,b,c},{x,y,z}}
echo {1,2,3,4,5}
echo *
echo deneme.[abc]
echo [[:upper:]]*
echo /usr/*/share
echo .[!.]* # echo hidden files.
echo .* # This is not correct
echo ~
echo $((2 + 2))
echo $(($((5 ** 2)) * 3))
echo $(((5**2) * 3))
echo Front-{A,B,C}-Back
echo Number_{1..5}
echo {01..15}
echo {001..15}
echo {Z..A}
echo a{A{1,2},B{3,4}}b
echo {2007..2009}-{01..12}
echo $USER
echo $PATH
echo $SUER # will result with an empty output
echo $(ls) # command substitution
ls -l $(which cp)
file $(ls -d /usr/bin/* | grep zip)
ls -ls `which cp` # syntax in older shell programs
ls -l ~ /usr
echo This is a      test
echo "This is a      test"
echo The total is $100.00
echo "$USER $((2 + 2)) $(cal)"
echo '$USER $((2 + 2)) $(cal)' # Supresses all expansions
echo "The balance for user $USER is \$5.00"

echo "----type examples----"
type echo
type ls
type find
type type
type cp

echo "----which examples----"
which find
which echo
which type

echo "----whatis examples----"
whatis find
whatis type
whatis ls

echo "----whereis examples----"
whereis find
whereis ls
whereis type

echo "----alias examples----"
alias foo='cd /usr; ls; cd -'
unalias foo

# help keyword only works with shell built-ins.
echo "----help examples----"
help cd

echo "---man examples----"
man passwd
man 5 passwd

echo "----apropos examples----"
apropos partition

echo "----printev examples----"
printenv

# The shell refers to stdin, stdout and stderr with file descriptors 0,1 and 2 respectively.
echo "----redirection----"
ls -l /usr/bin >  ls-output.txt # standard output redirection
ls -l /bin/usr >> ls-output.txt # standard output append
ls -l /bin/usr 2> ls-error.txt  # standard error redirection
ls -l /usr/bin >  ls-output.txt 2>&1 # the old way
ls -l /usr/bin &> ls-output.txt # newer version of redirecting both stdout and stdin
ls -l /usr/bin &>> ls-output.txt # append stdout and stdin
ls -l /usr/bin 2> /dev/null # dispose unwanted output
cat < lazy_dog.txt # redirect stdin

# Filter Examples
echo "----filters----"
ls /bin /usr/bin | sort | less
ls /bin /usr/bin | sort | uniq | less
ls /bin /usr/bin | sort | uniq | wc -l
ls /bin /usr/bin | sort | uniq | grep zip
