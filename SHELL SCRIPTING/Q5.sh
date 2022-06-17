if test "$2" = "+"
then echo `expr $1 + $3`
elif test "$2" = "-"
then echo `expr "$1" - "$3"`
elif test "$2" = "/"
then echo `expr "$1" / "$3"`
elif test "$2" = "%"
then echo `expr "$1" % "$3"`
elif test "$2" = "*"
then echo `expr $1 \* $3`
else echo "invalid"
fi
