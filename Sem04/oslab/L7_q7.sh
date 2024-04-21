array1=(1 2 3 4 5)
array2=(3 4 5 6 7)

intersection=()
for i in "${array1[@]}"; do
  for j in "${array2[@]}"; do
    if [[ $i == $j ]]; then
      intersection+=($i)
    fi
  done
done

echo "Intersection: ${intersection[@]}"

union=("${array1[@]}")
for i in "${array2[@]}"; do
  if [[ ! " ${union[]} " == *" $i " ]]; then
    union+=($i)
  fi
done
echo "Union: ${union[@]}"