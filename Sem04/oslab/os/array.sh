declare -a array
i=0
# q=1
for(( i=0; i<5; i++))
do
echo -n "Enter elements $(($i+1)):"
read array[i]
done
echo "displaying: "
# echo ${array[@]}
for(( i=0; i<5; i++))
do
echo $((array[i]))
done