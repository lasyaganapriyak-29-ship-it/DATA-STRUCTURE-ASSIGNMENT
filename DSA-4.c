#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int x) 
{
    if(rear == MAX-1)
        printf("Queue Full\n");
    else 
    {
        if(front == -1) front = 0;
        queue[++rear] = x;
    }
}
void dequeue() 
{
    if(front == -1 || front > rear)
        printf("No documents to print\n");
    else 
    {
        printf("Printing document: %d\n", queue[front]);
        front++;
    }
}
void display() 
{
    int i;
    if(front == -1)
        printf("Queue Empty\n");
    else 
    {
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
int main() 
{
    int ch, x;
    do {
        printf("\n1.Add\n2.Print\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch(ch) 
        {
            case 1:
                printf("Enter document number: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
        }
    } while(ch != 4);
    return 0;
}