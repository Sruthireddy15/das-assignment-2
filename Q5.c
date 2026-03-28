#include <stdio.h>

#define MAX 5
 
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if((rear + 1) % MAX == front) {
        printf("Queue Full\n");
    } else {
        if(front == -1) front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }
}

void dequeue() {
    if(front == -1) {
        printf("Queue Empty\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        if(front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void peek() {
    if(front == -1)
        printf("Queue Empty\n");
    else
        printf("Front element: %d\n", queue[front]);
}

void display() {
    int i = front;
    if(front == -1) {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue: ");
    while(1) {
        printf("%d ", queue[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int ch, x;

    while(1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
        }
    }
}