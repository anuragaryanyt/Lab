echo -n "Enter the radius: "
read r
peri=$( echo "2 * 3.14 * $r" | bc)
area=$( echo "3.14 * $r * $r" | bc)
echo "Perimeter: $peri"
echo "Area: $area"