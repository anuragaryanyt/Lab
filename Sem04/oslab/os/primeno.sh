i=1
while (( $i < 100 ))
do
flag=0
k=2
while (( $k < $i ))
do
ans=$(( $i % $k ))
if (( $ans == 0 ))
then
flag=$(( $flag + 1 ))
fi
k=$(( $k + 1 ))
done
if (( $flag == 0 ))
then 
echo "Prime no $i"
fi
i=$(( $i + 1 ))
done
















































#!/bin/bash

# echo "Prime numbers between 0 and 100:"

# for (( i=2; i<=100; i++ )); do
#   is_prime=true
#   for (( j=2; j<i; j++ )); do
#     if (( i % j == 0 )); then
#       is_prime=false
#       break
#     fi
#   done
#   if $is_prime; then
#     echo $i
#   fi
# done


