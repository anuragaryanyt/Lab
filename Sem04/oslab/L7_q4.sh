echo "Enter no of elements in array : "
read n
echo "Enter array elements : "
for ((k = 0; k < $n; k++)); 
do
    read arr[$k]
done

for ((i = 0; i<$n; i++))
do
    
    for((j = 0; j<`expr $n-$i-1`; j++))
    do
    
        if [ ${arr[j]} -gt ${arr[$((j+1))]} ]
        then
            temp=${arr[j]}
            arr[$j]=${arr[$((j+1))]}  
            arr[$((j+1))]=$temp
        fi
    done
done

echo "2nd Largest Element : ${arr[`expr $n-2`]}"