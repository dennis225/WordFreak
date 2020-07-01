# WordFreak

# GOAL
The goal of this project is to implement a program that performs a simple glossary analysis. In particular, the program extracts “words” from a text file and prints to the console a mapping of the words found in the provided text file and their associated frequencies.

# DESCRIPTION
The project is a Glossary Analysis where it traverses through each text file and displays each distinct word from each text file along with the total number of frequencies of that word.


# IMPLEMENTATION
## main.c
The following functions are used:

1. int find(struct word** head,char* buf)
takes in a head (of type struct word**) and a buf character pointer. It traverses the linked list and returns the frequencies of the word in buf

2. void changeFreq(struct word** head, char* buf, int freqs)
takes in a head (of type struct word**), a buf character pointer and an integer freqs. It updates the frequency for each distinct word.

3. struct word* addAtEnd(struct word** current, char* buf)
takes in a current (of type struct word**) and a buf character pointer. It forms a new linked list at the end of each word and returns that new word. 

4. int main(int argc, char *argv[])
takes in an integer argc (count) and a character array argv (vector). It executes the program by making the linked list and adding only new elements each time by calling find(), changeFreq() and addAtEnd()

## words.h
A struct word is created with elements name, frequency and next link.

It aslo creates a typedef struct word WORD
