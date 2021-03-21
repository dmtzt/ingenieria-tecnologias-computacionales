/*
 * text-tree.c
 * Reads a text file and stores all words found along its ocurrences in a binary tree
 * Prints the results in alphabetical order after the reading is done
 * 
 * David Alejandro Martínez Tristán A01610267
 * Last update: 14/Mar/2021
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "textfile.txt"
#define BUFFER_SIZE 64

typedef struct Node {
    char* word;
    int occurences;
    struct Node *right;
    struct Node *left;
} Node;

Node* newNode(char* word);
void insert(Node *current, char* newWord);
void printTree(struct Node *current);
void printWord(char* word);

int main(void) {
    char c;
    int pos = 0;
    // Allocate space in a buffer to store the word
    char* word = malloc(BUFFER_SIZE * sizeof(char));
    // Open the text file
    FILE* fptr = fopen(FILENAME, "r");
    Node* head = NULL;

    // File does not exist
    if (fptr == NULL)
    {
        printf("File does not exist\n");
        return 1;
    }

    // Read from start to end
    while (!feof(fptr))
    {
        // Read character by character
        c = getc(fptr);

        // If character is alphabetic, add as lowercase to the buffer
        if (isalpha(c) != 0)
        {
            word[pos] = tolower(c);
            pos++;
        }
        // If if it is not alphabetic, end word and insert to binary tree
        else if (pos > 0)
        {
            word[pos] = '\0';
            pos = 0;

            if (head == NULL)
                head = newNode(word);
            else
                insert(head, word);
        }
        
        // Word length exceeeds buffer size
        if (pos == BUFFER_SIZE)
        {
            printf("Error: word length exceeds buffer size\n");
            return 2;
        }
    }

    // Print resulting tree
    printf("Resulting tree\n");
    printTree(head);

    // Close file
    fclose(fptr);

    return 0;
}

Node* newNode(char* word) 
{
    // Allocate memory for new node
    Node* node = malloc(sizeof(Node));
    // Allocate memory for new word
    node->word = malloc(BUFFER_SIZE * sizeof(char));
    
    // Copy word to char array
    int i;
    for (i = 0; word[i] != '\0'; i++)
        node->word[i] = word[i];
    node->word[i] = '\0';
    
    // Set initial values for ocurrence and left and right pointers
    node->occurences = 1;
    node->left = NULL;
    node->right = NULL;

    // Return new node
    return node;
}

void insert(Node *current, char* newWord)
{
    // Create new node if the pointer is null
    if(current == NULL)
        current = newNode(newWord);
    else
    {
        // Compare the two words letter by letter until the end of one is reached
        for (int i = 0; newWord[i] != '\0' && current->word[i] != '\0'; i++)
        {
            // If current letter from new word comes before current letter from current word
            if (newWord[i] < current->word[i])
            {
                // Insert to the left
                if (current->left == NULL)
                    current->left = newNode(newWord);
                else
                    insert(current->left, newWord);

                return;
            }
            // If current letter from new word comes after current letter from current word
            else if (newWord[i] > current->word[i])
            {
                // Insert to the right
                if (current->right == NULL)
                    current->right = newNode(newWord);
                else
                    insert(current->right, newWord);

                return;
            }
            // Else, if all letters are the same
            else
            {
                // If new word is longer than current word
                if (current->word[i + 1] == '\0' && newWord[i + 1] != '\0')
                {
                    // Insert to the right
                    if (current->right == NULL)
                        current->right = newNode(newWord);
                    else
                        insert(current->right, newWord);

                    return;
                }
                // If current word is longer than new word
                else if (current->word[i + 1] != '\0' && newWord[i + 1] == '\0')
                {
                    // Insert to the left
                    if (current->left == NULL)
                        current->left = newNode(newWord);
                    else
                        insert(current->left, newWord);

                    return;
                }
                // Both words have the same length
                else if (current->word[i + 1] == '\0' && newWord[i + 1] == '\0')
                {
                    // Update occurences counter
                    current->occurences++;
                    return;
                }
            } 
        }
    }
}

void printTree(struct Node *current)
{
    // Print tree in order traverse (left, root, right)
    if (current != NULL)
    {
        printTree(current->left);
        printf("%i\t", current->occurences);
        printWord(current->word);
        printTree(current->right);

        // Free allocated memory
        free(current->word);
        free(current);
    }
}

void printWord(char* word)
{
    // Print word given a char pointer
    for (int i = 0; word[i] != '\0'; i++)
        printf("%c", word[i]);
    
    printf("\n");
}