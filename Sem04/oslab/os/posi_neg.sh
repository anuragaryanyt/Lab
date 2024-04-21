echo "Enter the no:"
read a
# if [ $a -gt 0 ]
if (( $a > 0 ))
then 
echo "Positive no"
# elif [  $a -ne 0 ]
elif (( $a < 0 ))
then 
echo "Negative no"
else
echo "The no is 0"
fi
