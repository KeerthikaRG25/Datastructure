#include <stdio.h>

#define MAX_JOBS 100

// Structure to represent a print job
typedef struct {
    int jobId;
    int length;
} PrintJob;

// Structure to represent a printer queue
typedef struct {
    PrintJob jobs[MAX_JOBS];
    int size;
} PrinterQueue;

// Function to add a print job to the queue
void submitJob(PrinterQueue *queue, int jobId, int length) {
    if (queue->size < MAX_JOBS) {
        PrintJob newJob = {jobId, length};
        queue->jobs[queue->size] = newJob;
        queue->size++;
        printf("Job %d added to the queue.\n", jobId);
    } else {
        printf("Queue is full. Cannot add job.\n");
    }
}

// Function to print the next job in the queue
void printNextJob(PrinterQueue *queue) {
    if (queue->size > 0) {
        PrintJob nextJob = queue->jobs[0];
        printf("Printing job %d of length %d.\n", nextJob.jobId, nextJob.length);
        // Shift remaining jobs to fill the gap
        for (int i = 0; i < queue->size - 1; i++) {
            queue->jobs[i] = queue->jobs[i + 1];
        }
        queue->size--;
    } else {
        printf("No jobs in the queue.\n");
    }
}

int main() {
    PrinterQueue queue = {{}, 0};

    // Submit some print jobs
    submitJob(&queue, 1, 5);
    submitJob(&queue, 2, 3);
    submitJob(&queue, 3, 7);

    // Print the next job
    printNextJob(&queue); // Prints job 1

    // Submit another job
    submitJob(&queue, 4, 2);

    // Print all remaining jobs
    printNextJob(&queue); // Prints job 2
    printNextJob(&queue); // Prints job 3
    printNextJob(&queue); // Prints job 4

    // Try printing when queue is empty
    printNextJob(&queue); // Prints "No jobs in the queue."

    return 0;
}
