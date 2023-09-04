
echo "Enter a number:"
read num
sum=0
count=${#num}
for (( i=0; i<count; i++ ))
do
    digit=${num:$i:1}
    product=$(( $digit ** $count ))
    sum=$(( $sum + $product ))
done
if [ $num -eq $sum ]
then
    echo "$num is an Armstrong number."
else
    echo "$num is not an Armstrong number."
fi
