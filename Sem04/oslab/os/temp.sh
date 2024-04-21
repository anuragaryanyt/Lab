echo "Enter the temp in F: "
read temp
a=$(( ($temp-32)*5/9 ))
echo "temp in C: $a"