#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

int mutex = 1;      // Binary semaphore for mutual exclusion
int full = 0;       // Counter for filled slots
int empty = BUFFER_SIZE; // Counter for empty slots
int x = 0;          // Item count

void wait(int *s) {
    while (*s <= 0); // Busy wait (not recommended for real-world applications)
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void producer() {
    if (empty > 0) {
        wait(&empty);
        wait(&mutex);

        x++;
        printf("Producer has produced: Item %d\n", x);

        signal(&mutex);
        signal(&full);
    } else {
        printf("Buffer is full!\n");
    }
}

void consumer() {
    if (full > 0) {
        wait(&full);
        wait(&mutex);

        printf("Consumer has consumed: Item %d\n", x);
        x--;

        signal(&mutex);
        signal(&empty);
    }

    // Print "Buffer is empty!" message when full is 0
    if (full == 0) {
        printf("Buffer is empty!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nEnter 1.Producer 2.Consumer 3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
