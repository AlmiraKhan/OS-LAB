#!Length of name and reverse

echo Enter name
read name
name2=${name// /} 
echo No of alphabets : ${#name2}
echo Reverse : `echo $name | rev`