echo "Enter 3 nos:"
read x
read y
read z
if [ $x -lt $y ]
then
if [ $x -lt $z ]
then
echo "$x is smallest"
else
echo "$z is smallest"
fi
else
if [ $y -lt $z ]
then
echo "$y is smallest"
else
echo "$z is smallest"
fi
fi