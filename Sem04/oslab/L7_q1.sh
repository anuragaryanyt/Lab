echo "Enter 10 array elements : "
for((k=0;k<10;k++))
do
read a[$k]
done

echo "Array elements : "
for((k=0;k<10;k++))
do
echo ${a[$k]}
done