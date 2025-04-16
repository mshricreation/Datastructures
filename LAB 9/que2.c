#include <stdio.h>
#include <stdlib.h>

 
struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
         
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d enqueued to queue.\n", value);
}

 
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty (Underflow)\n");
        return;
    }


    struct Node* temp = front;
    printf("%d dequeued from queue.\n", front->data);
    front = front->next;

     
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}
 
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

 
int main() {
    enqueue(100);
    enqueue(200);
    enqueue(300);
    display();
    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue();  
    return 0;
}