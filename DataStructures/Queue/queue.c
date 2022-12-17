// 21BCY10037 Aryan Dhotre
//  Queue implementation in C
//  Queue is a linear data structure which follows a particular order in which the operations are performed.
#include <stdio.h>
#include <stdlib.h>
#define Size 6
int rear;
int front = 0;
int queue[Size];

int menu()
{
    int choice;
    printf("\n\nPress,\n1. Enqueue\n2. Dequeue\n3. Check if queue is empty\n4. Check if queue is full\n5. Display\n6. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    return (choice);
}

int isFull()
{
    if (rear == Size - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (front > rear)
        return 1;
    else
        return 0;
}

void enqueue(int n)
{
    if (isFull())
        printf("Queue is Full");
    else
    {
        rear++;
        queue[rear] = n;
    }
}

void dequeue()
{

    if (!isEmpty())
        printf("\n%d is deleted", queue[front++]);
    else
        printf("\nqueue is Empty");
}

void traverse()
{
    int i;
    if (!isEmpty())
    {
        printf("\nqueue is : ");
        for (i = front + 1; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n------------------");
    }
    else
        printf("\nqueue is Empty");
}

int main()
{
    int choice, num;
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            printf("Enter the value :");
            scanf("%d", &num);
            enqueue(num);
            traverse();
            break;
        case 2:
            dequeue();
            traverse();
            break;
        case 3:
            if (isEmpty())
                printf("\nqueue is Empty");
            else
                printf("\nqueue is not Empty");
            break;
        case 4:
            if (isFull())
                printf("\nqueue is Full");
            else
                printf("\nqueue is not Full");
            break;
        case 5:
            traverse();
            break;
        default:
            exit(0);
        }
    } while (choice < 6);
}