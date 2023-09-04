#!/bin/bash

echo "Enter a number:"
read num

reverse=0
temp=$num

while (( $num > 0))
do
    digit=$(( $num % 10 ))
    reverse=$(( $reverse * 10 + $digit ))
    num=$(( $num / 10 ))
done

if (( $temp == $reverse ))
then
    echo "$temp is a palindrome number."
else
    echo "$temp is not a palindrome number."
fi




















# echo "Enter the no: "
# read num
# s=0
# rev=0
# temp=$num
# while (( $num > 0 ))
# do 
# s=$(( $num % 10 ))
# num=$(( $num / 10 ))
# rev=$(( $rev * 10 ))
# rev=$(( $rev + $s ))
# done
# if (( $temp == $rev ))
# then 
# echo "Palindrome"
# else 
# echo "Not Palindrome"
# fi