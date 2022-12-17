// Aryan Dhotre 21BCY10037
#include <stdlib.h>
#include <stdio.h>
// to code stack datastructure using array.
// to implement push pop and traverse , isempty and isfull operation in stack.
#define SIZE 5
int menu()
{
    int choice;
    printf("\n 1 . push an element in stack");
    printf("\n 2 . pop an element from top of the stack");
    printf("\n 3 . traverse the stack");
    printf("\n 4 . check if stack is empty");
    printf("\n 5 . check if stack is full");
    printf("\n 6 . exit");
    printf("\n enter your choice : ");
    scanf("%d", &choice);
    return choice;
}

void push(int item, int *stack)
{
    if (stack[SIZE - 1] != 0)
    {
        printf("stack is full");
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (stack[i] == 0)
            {
                stack[i] = item;
                break;
            }
        }
    }
}
void pop(int *stack)
{
    // pops the topmost item from the stack
    if (stack[0] == 0)
    {
        printf("stack is empty");
    }
    else
    {
        for (int i = SIZE - 1; i >= 0; i--)
        {
            if (stack[i] != 0)
            {
                stack[i] = 0;
                break;
            }
        }
    }
}

void traverse(int *stack)
{
    // prints all the elements from the stack
    printf("-------------------\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\n", stack[i]);
    }
    printf("-------------------");
}

int main()
{
    int ch, item;
    int stack[SIZE] = {0, 0, 0, 0, 0};
    // traverse(stack);
    do
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            printf("enter the item to be pushed : ");
            scanf("%d", &item);
            push(item, stack);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            traverse(stack);
            break;
        case 4:
            if (stack[0] == 0)
            {
                printf("stack is empty");
            }
            else
            {
                printf("stack is not empty");
            }
            break;
        case 5:
            if (stack[SIZE - 1] != 0)
            {
                printf("stack is full");
            }
            else
            {
                printf("stack is not full");
            }
            break;
        default:
            printf("enter the choice between 1 to 6");
            break;
        }
    } while (ch < 6);
}