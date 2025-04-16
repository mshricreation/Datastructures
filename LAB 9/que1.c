#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

 
void enqueue(int data) {
    if (rear == SIZE - 1) {
        printf("Queue is full (Overflow)\n");
        return;
    }
    if (front == -1) front = 0;  
    rear++;
    queue[rear] = data; 
}

 void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty (Underflow)");
        return;
    }
    front++;
}

 
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

 
int main() {
  int N;
  printf("enter size of array");
  scanf("%d",&N);
  int Qu[N];

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue();  
    return 0;
}