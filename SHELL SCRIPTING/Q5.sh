#!simple calculator

echo "Enter two numbers"
read a
read b
while [ $loop="1" ]
do
    echo "Enter your choice :"
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    read ch
    case $ch in
    1)res=`echo $a + $b | bc`;; 
    2)res=`echo $a - $b | bc`;;
    3)res=`echo $a \* $b | bc`;;
    4)res=`echo "scale=2; $a / $b" | bc`;;
    *) echo "Not a valid input!"
    esac
    echo "Result : $res"
    echo "Do you wish to continue(1/0)?"
    read loop
    if [ $loop != "1" ]
    then    
        exit
    fi
done