i=1
while [ $i -lt 100 ]
do
flag=0
k=2
while [ $k -lt $i ]
do
ans=`expr $i % $k`
if [ $ans -eq 0 ]
then 
flag=`expr $flag + 1`
fi
k=`expr $k + 1`
done
if [ $flag -eq 0 ]
then 
echo "prime no $i"
fi
i=`expr $i + 1`
done
