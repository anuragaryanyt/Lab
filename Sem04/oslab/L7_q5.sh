echo "Enter no of elements in array : "
read n
echo "Enter array elements : "
for ((k = 0; k < $n; k++)); 
do
    read arr[$k]
done

sum=0
for ((i = 0; i<$n; i++))
do
    sum=$[$sum+${arr[$i]}]
done

echo "Sum of elements : $sum"