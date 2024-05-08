#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is a space or not
int isSpace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

// Recursive function to extract words between start and end indices
void extractWords(char *sentence, int start, int end) {
    // Base case: if start exceeds end or start is beyond sentence length
    if (start > end || start >= strlen(sentence))
        return;

    // Skip leading spaces
    while (isSpace(sentence[start]) && start <= end)
        start++;

    // Find the end of the current word
    int wordEnd = start;
    while (!isSpace(sentence[wordEnd]) && wordEnd <= end)
        wordEnd++;

    // Print the word
    for (int i = start; i < wordEnd; i++)
        printf("%c", sentence[i]);

    printf(" "); // Add a space after each word

    // Recursive call to process the next word
    extractWords(sentence, wordEnd, end);
}

int main() {
    char sentence[] = "This is a sample sentence for testing";
    int start = 5; // Index of the first word to extract (inclusive)
    int end = 18;  // Index of the last word to extract (inclusive)

    extractWords(sentence, start, end);

    return 0;
}
