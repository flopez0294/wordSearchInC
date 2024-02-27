CC = gcc

all:
	$(CC) -o app wordsearch.c

clean:
	rm -f app