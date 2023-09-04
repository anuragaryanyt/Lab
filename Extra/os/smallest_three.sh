echo "ENter 3 nos:"
read a
read b
read c
if (( $a < $b ));
then
if (( $a < $c ));
then
echo "$a is smallest!!"
else
echo "$c is smallest!!"
fi
else
if (( $b < $c ));
then 
echo "$b is smallest!!"
else
echo "$c is smallest!!"
fi
fi
