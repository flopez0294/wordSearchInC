CC = gcc

all:
	$(CC) -o app -g wordsearch.c

clean:
	rm -f app