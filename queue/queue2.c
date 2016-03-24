#include <stdio.h>
#include <stdlib.h>


#define QUEUESIZE 10
int queue[QUEUESIZE], f=0, r=-1;


// Check if queue is full
int queuefull() {
    if (r == QUEUESIZE - 1) {
        return 1;
    }
    return 0;
}

// Check if the queue is empty
int queueempty() {
    if (f > r) {
        return 1;
    }
    return 0;
}

// Show queue content
int queueshow() {
    int i;

    if (queueempty()) {
        printf(" \n The queue is empty\n");
        return;
    }

    printf("Start->");
    for (i = f; i <= r; i++) {
        printf("%d ", queue[i]);
    }
    printf("<-End");

    return 0;
}

// Perform an insert operation.
int enqueue(int oneelement) {
    if(queuefull()) {
        printf("\n\n Overflow!!!!\n\n");
        return 0;
    queue[++r] = oneelement;
    return 1;
}

// Perform a delete operation
int dequeue() {
    int elem;
    if(queueempty()) {
        printf(" \n The queue is empty\n");
        return -1;
    }
    elem = queue[f++];
    return elem;
}

int main() {
    int option, element;

    do {
    printf("\n Press 1-Insert, 2-Delete, 3-Show, 4-Exit\n");
    printf("\n Your selection? ");
    scanf("%d",&option);
    switch(option) {
        case 1:
            printf("\n\nContent to be Inserted?");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            element = dequeue();
            if (element != -1) {
                printf("\n\nDeleted element (with content %d) \n", element);
            }
            break;
        case 3:
            printf("\n\nStatus of the queue\n\n");
            queueshow();
            break;
        case 4:
            printf("\n\n Ending the program \n\n");
            break;
        default:
            printf("\n\nInvalid option, please retry! \n\n");
            break;
        }
    } while(option != 4);

    return 0;
}
