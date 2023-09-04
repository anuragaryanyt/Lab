echo -n "Enter the year"
read y
a=$(($y % 400))
b=$(($y % 4))
c=$(($y % 100))

if (( $a == 0 || $b == 0 && $c != 0 ));
then
echo "Leap year"
else
echo "Not a leap year"
fi
