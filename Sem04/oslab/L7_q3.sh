#write a shell script to find out maximum and minimum element from a given array

k=0
echo "Enter 5 array elements : "
while [ $k -lt 5 ]
do
read arr[$k]
k=`expr $k + 1`
done

min=${arr[0]}
max=${arr[0]}
for((i=0;i<5;i++))
do

if [ ${arr[$i]} -lt $min ]; 
then
min=${arr[$i]}

elif [ ${arr[$i]} -gt $max ];
then
max=${arr[$i]}
fi
done

echo "Maximum element is : $max"
echo "Minimum element is : $min"

