

echo "%%% AHURATUS BASH  EX2WEEK05 %%%"
echo "%%% B19-03       OS-Fall2020 %%%"
echo " >> PRESS CTRL+C to EXIT"
sleep 2
echo "% Checking & Creating Files.... %"
if [ ! -f  "ex2.txt" ]; then
#
#else

	echo "%%% Text file does not exist! %%%"
	touch ex2.txt
	echo "%%%%%% ex2.txt created!... %%%%%%"
	echo "%%%%%% INITITALIZE ex2.txt %%%%%%"
	echo "1" > ex2.txt
	 
else
	echo "          >>FILES CHECKED!"

fi
echo ">>>Verifying 'ex2.txt'..."
var="$(tail -1 ex2.txt)"
regex='^[0-9]+$'
if ! [[ $var =~ $regex ]]; then
	echo "***ERROR : INVALID INPUT IN 'ex2.txt'"
	echo "*HINT : 'ex2.txt' MUST CONTAIN AN INTEGER IN LAST LINE"
	exit
else
	echo ">>> File 'ex2.txt' verified!"
fi
sleep 1


echo "%%%% Creating Variables... %%%%%%"
filePath="ex2.txt"
lockPath="ex2.lock"

trap 'rm ${lockPath};exit' exit
echo "%%%%     >>>>   Locking... %%%%%%"
if ln $filePath $lockPath 2>&-; 
then
    echo ">>> LOCKED"
else
    echo $(<$filePath)
    rm $tmpfile
    exit
fi

while  [ true ]
do
    while read line;
    do
        n=$((line+1))
    done < ex2.txt
    echo $n >> ex2.txt
    echo " $n appended to the file!"	
done
