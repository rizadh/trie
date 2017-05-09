trie: trie.o main.o 
	gcc -Wall -g -o trie trie.o main.o
main.o: main.c trie.h
	gcc -Wall -g -c main.c
trie.o: trie.c trie.h
	gcc -Wall -g -c trie.c
clean:
	rm -rf trie *.o
