os=(apple banana cherry)
for i in "${!os[@]}"
do
  echo "Index $i: ${os[$i]}"
done
