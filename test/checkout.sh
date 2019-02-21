
./test.exe 2> errors.txt | tee output.txt

if cat output.txt | grep '  = false' -q; then
	echo 'Test failed'
	exit 1
fi

rm test.exe test.c || exit 1
echo OK
