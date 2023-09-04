echo "Enter 5 array elements : "
for ((k = 0; k < 5; k++)); do
    read arr[$k]
done

for ((i = 0; i<$n; i++))
do    
    limit=`expr $n-$i-1`
    for ((j = 0; j < limit; j++));
    do
    
        if [ ${arr[j]} -gt ${arr[$((j+1))]} ]
        then
            temp=${arr[j]}
            arr[$j]=${arr[$((j+1))]}  
            arr[$((j+1))]=$temp
        fi
    done
done


count=0
for ((i = 0; i<$n; i++))
do
    if [ ${arr[$i]} -ne ${arr[`expr $i - 1`]} ]
    then
        echo "${arr[`expr $i - 1`]} : $count"
        count=0;
    
    elif
        count=`expr $count + 1`
    fi
done