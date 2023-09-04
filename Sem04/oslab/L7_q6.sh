echo "Enter 5 array elements : "
for ((k = 0; k < 5; k++)); 
do
    read arr[$k]
done

for (( i=0; i<5; i++ )); 
do
  if [[ ${arr[i]} == "x" ]];
   then
    continue
  fi

  echo "Element ${arr[i]} found at index $i"

   for (( j=i+1; j<5; j++ )); 
   do
    if [[ ${arr[j]} == ${arr[i]} ]]; 
    then
      echo "Element ${arr[i]} found at index $j"
     arr[j]="x"
    fi
  done
done