#include <stdio.h>
#include <string.h>

#define MAX_HISTORY_SIZE 100
#define MAX_URL_LENGTH 100

// Global variables
char history[MAX_HISTORY_SIZE][MAX_URL_LENGTH];
int historySize = 0;
int currentPosition = -1;

// Function to visit a URL and add it to history
void visit(char *url) {
    if (historySize < MAX_HISTORY_SIZE) {
        strcpy(history[++currentPosition], url);
        historySize++;
    } else {
        printf("History is full\n");
    }
}

// Function to navigate back in history
void navigateBack() {
    if (currentPosition > 0) {
        currentPosition--;
        printf("Navigated back to: %s\n", history[currentPosition]);
    } else {
        printf("No more history to navigate back\n");
    }
}

// Function to navigate forward in history
void navigateForward() {
    if (currentPosition < historySize - 1) {
        currentPosition++;
        printf("Navigated forward to: %s\n", history[currentPosition]);
    } else {
        printf("No more history to navigate forward\n");
    }
}

int main() {
    // Simulate browsing history
    visit("www.google.com");
    visit("www.youtube.com");
    visit("www.facebook.com/page1");
    
    // Navigate back
    navigateBack();
    navigateBack();

    // Navigate forward
    navigateForward();

    return 0;
}
