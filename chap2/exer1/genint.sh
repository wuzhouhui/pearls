exec 1> nums.txt

for (( i = 0; i <= 4294967296; i++))
do
	echo $i
done

rand=$RANDOM
for ((i = 0; i < (4300000000 - 4294967296); i++))
do
	echo $rand 
done 

