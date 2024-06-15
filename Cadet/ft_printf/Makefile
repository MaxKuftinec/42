x := file1 file2
hello: ${x}
	echo "Look at me: " ${x}
	touch hello
file1:
	touch file1
file2:
	touch file2
clean:
	rm -f file1 file2 hello