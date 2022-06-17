echo "Enter name"
read name
if [ -f $name ]
then echo "It is a file name"
elif [ -d $name ]
then echo "It is a directory"
else echo "Invalid"
fi
