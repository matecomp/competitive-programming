compile:
	g++ *.cpp
run:
	make compile
	./a.out < in.txt > temp.txt
	cat temp.txt
diff:
	diff temp.txt out.txt