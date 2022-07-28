#!copy content of file1 to file2

echo "Enter the filename"
read file1
echo "Enter the second file"
read file2
if [ -f $file2 ]
then 
    echo "Appending"
    `cat $file1 >> $file2`
else    
    echo "copy"
    `cp $file1 $file2`
fi
echo `cat $file2`