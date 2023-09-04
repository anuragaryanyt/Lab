echo -n "Enter 3 digit no: "
read n
a=$(( $n % 100 ))
b=$(( $n / 100 ))
c=$(( $a % 10 ))
d=$(( $a / 10 ))

sum=$(($b + $c + $d))
echo "Sum of digit is: $sum"

