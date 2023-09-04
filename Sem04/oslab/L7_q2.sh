echo "Enter no of elements in array : "
read n
echo "Enter array elements : "
for ((k = 0; k < n; k++)); 
do
    read arr[$k]
done

limit=`expr $n / 2`
if [ `expr $n % 2` == 0 ]
then
    limit=`expr $limit-1`
fi

for ((k = 0; k <= $limit; k++)); 
do
    temp=${arr[$k]}
    index=`expr $n - $k - 1`
    arr[$k]=${arr[$index]}
    arr[$index]=$temp

done

echo "Reversed Array"
for ((k = 0; k < n; k++)) 
do
    echo -n "${arr[$k]}    "
done