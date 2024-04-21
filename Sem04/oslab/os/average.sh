echo "Enter the marks of the 5 subject out of 100: "
read a
read b
read c
read d
read e

sum=$(( $a + $b + $c + $d + $e ))
echo "Sum : $sum"

avg=$(( $sum / 5 ))
echo "Avg : $avg"
