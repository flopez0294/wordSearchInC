#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char **arr);
void searchPuzzle(char **arr, char *word);
int sizeOfWord(char* word);
bool checkAround(char **arr, char* word, int i, int j, int letIdx);

int bSize;
int wordSize;

// Main function, DO NOT MODIFY
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);

    // Allocate space for the puzzle block and the word to be searched
    char **block = (char **)malloc(bSize * sizeof(char *));
    char *word = (char *)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for (i = 0; i < bSize; i++)
    {
        *(block + i) = (char *)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j)
        {
            fscanf(fptr, "%c ", *(block + i) + j);
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    printf("Enter the word to search: ");
    scanf("%s", word);

    wordSize = sizeOfWord(word);
    printf("Size of Word: %d\n", wordSize);

    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);
    printf("\n");

    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);

    for (i = 0; i < bSize; i++)
    {
        free(*(block + i));
    }

    free(block);
    free(word);
    return 0;
}

int sizeOfWord(char *word) {
    int i = 0;
    int size = 0;
    while (*(word + i) != '\0') {
        size++;
        i++;
    }
    return size;
}

void printPuzzle(char **arr)
{
    // This function will print out the complete puzzle grid (arr).
    // It must produce the output in the SAME format as the samples
    // in the instructions.
    // Your implementation here...
    int i, j;
    for (i = 0; i < bSize; i++)
    {
        for (j = 0; j < bSize; j++)
        {
            printf("%c ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

bool checkAround(char **arr, char* word, int i, int j, int letIdx) {
    // recursive function
    if (*(*(arr + i) + j) == *(word + letIdx)){
        bool temp = false;
        if ((word + letIdx) == (word + wordSize - 1)) {
            return true;
        }
        if (i - 1 >= 0 &&  j - 1 >= 0) {
            temp = checkAround(arr, word, i - 1, j - 1, letIdx + 1);
            if (temp) {
                return true;
            }
        }
        if (i + 1 <= bSize - 1 && j + 1 <= bSize) {
            temp = checkAround(arr, word, i + 1, j + 1, letIdx + 1);
            if (temp) {
                return true;
            }
        }
        if (i + 1 <= bSize -1 && j <= bSize - 1) {
            temp = checkAround(arr, word, i + 1, j, letIdx + 1);
            if (temp) {
                return true;
            }
        }
        if (i <= bSize -1 && j + 1 <= bSize) {
            temp = checkAround(arr, word, i, j + 1, letIdx + 1);
            if (temp) {
                return true;
            }
        }
        if (i - 1 >= 0 && j <= bSize - 1) {
            temp = checkAround(arr, word, i - 1, j, letIdx + 1);
            if (temp) {
                return true;
            }
        }
        if (i <= bSize -1 && j - 1 >= 0) {
            temp = checkAround(arr, word, i, j + 1, letIdx + 1);
            if (temp) {
                return true;
            }
        }
        if (i + 1 <= bSize - 1 && j - 1 >= 0) {
            temp = checkAround(arr, word, i + 1, j - 1, letIdx + 1);
            if (temp) {
                return true;
            }
        }
        if (i - 1 >= 0 && j + 1 <= bSize - 1) {
            temp = checkAround(arr, word, i - 1, j + 1, letIdx + 1);
            if (temp) {
                return true;
            }
        }
    }
    
    return false;
}

void searchPuzzle(char **arr, char *word)
{
    // This function checks if arr contains the search word. If the
    // word appears in arr, it will print out a message and the path
    // as shown in the sample runs. If not found, it will print a
    // different message as shown in the sample runs.
    // Your implementation here...
    int x;
    // make word capitalized
    for (x = 0; x < wordSize; x++)
    {
        if ((int)*(word + x) >= 'a' && (int)*(word + x) <= 'z') {
            *(word + x) = ((int)*(word + x) - 32);
        }
    }

    // make double for loop to inteate throuhgh array then make recursice function to get around the area.
    bool flag = false;
    int i, j;
    for (i = 0; i < bSize; i++) {
        for (j = 0; j < bSize; j++) {
            flag = checkAround(arr, word, i, j, 0);
            if (flag) break;
        }
        if (flag) break;
    }
    printf("%d\n", flag);
    // print out solution if any
}






