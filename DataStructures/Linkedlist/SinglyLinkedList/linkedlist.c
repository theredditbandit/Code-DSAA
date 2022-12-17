#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
NODE *head;

int menu()
{
    int ch;
    printf("\nPress,\n1. Insert Begin\n2. Insert End\n3. Insert Position");
    printf("\n4. Delete Begin\n5. Delete End\n6. Delete Element");
    printf("\n7. Search\n8. Edit\n9. Traverse\n10. Exit\nYour Choice :");
    scanf("%d", &ch);
    return (ch);
}

void insert_begin(int item)
{
    NODE *curr;
    curr = (NODE *)malloc(sizeof(NODE));
    curr->data = item;
    if (head == NULL)
        curr->next = NULL;
    else
        curr->next = head;
    head = curr;
}

void insert_end(int item)
{
    NODE *curr, *prev;
    curr = (NODE *)malloc(sizeof(NODE));
    curr->data = item;
    curr->next = NULL;
    if (head == NULL)
        head = curr;
    else
    {
        prev = head;
        while (prev->next != NULL)
            prev = prev->next;
        prev->next = curr;
    }
}

void delete_begin()
{
    NODE *curr;
    if (head == NULL)
    {
        printf("\nLinked list is empty , No delete operation");
        return;
    }
    else
    {
        curr = head;
        head = head->next;
        printf("Deleted nodes is : %d ", curr->data);
        free(curr);
    }
}

void delete_end()
{
    NODE *curr, *prev;
    if (head == NULL)
    {
        printf("\nLinked list is empty , No delete operation");
        return;
    }
    else if (head->next == NULL)
    {
        curr = head;
        head = NULL;
        printf("Deleted nodes is : %d ", curr->data);
        free(curr);
    }
    else
    {
        prev = head;
        curr = head->next;
        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        printf("Deleted nodes is : %d ", curr->data);
        free(curr);
    }
}

void insert_position(int item, int pos)
{
    NODE *curr, *prev;
    int i;
    curr = head;
    for (i = 0; i < pos - 2; i++)
    {
        curr = curr->next;
        if (curr == NULL)
        {
            printf("\n Cannot insert node at this position");
            return;
        }
    }
    prev = (NODE *)malloc(sizeof(NODE));
    prev->data = item;
    if (pos == 1)
    {
        prev->next = curr;
        head = prev;
    }
    else
    {
        prev->next = curr->next;
        curr->next = prev;
    }
}

int edit_item(int item, int ritem)
{
    NODE *curr;
    int i = 0;
    curr = head;
    while (curr != NULL)
    {
        if (curr->data == item)
        {
            curr->data = ritem;
            return (++i);
        }
        ++i;
        curr = curr->next;
    }
}

void traverse()
{
    NODE *curr;
    curr = head;
    while (curr != NULL)
    {
        printf("%d ->", curr->data);
        curr = curr->next;
    }
    printf("Nil\n");
}

int search(int item)
{
    NODE *curr;
    int i = 0;
    curr = head;
    while (curr != NULL)
    {
        if (curr->data == item)
            return (++i);
        ++i;
        curr = curr->next;
    }
    return (0);
}

void delete_item(int item)
{
    NODE *curr, *prev;
    curr = head;
    while (curr != NULL)
    {
        if (curr->data == item)
        {
            if (curr == head)
            {
                head = head->next;
                free(curr);
                return;
            }
            else
            {
                prev->next = curr->next;
                free(curr);
                return;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    printf("\nItem not found");
}

void main()
{
    int ch, item, pos, ritem;
    head = NULL;
    do
    {
        // clrscr();
        // system("CLS");
        ch = menu();
        switch (ch)
        {
        case 1:
            printf("Enter the item to be inserted : ");
            scanf("%d", &item);
            insert_begin(item);
            break;
        case 2:
            printf("Enter the item to be inserted : ");
            scanf("%d", &item);
            insert_end(item);
            break;
        case 3:
            printf("Enter the item to be inserted : ");
            scanf("%d", &item);
            printf("Enter the position : ");
            scanf("%d", &pos);
            insert_position(item, pos);
            break;
        case 4:
            delete_begin();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            printf("Enter the item to be deleted : ");
            scanf("%d", &item);
            delete_item(item);
            break;
        case 7:
            printf("Enter the item to be searched : ");
            scanf("%d", &item);
            pos = search(item);
            if (pos > 0)
                printf("Item found at position %d", pos);
            else
                printf("Item not found");
            break;
        case 8:
            printf("Enter the item to be edited : ");
            scanf("%d", &item);
            printf("Enter the new item : ");
            scanf("%d", &ritem);
            pos = edit_item(item, ritem);
            if (pos != 0)
                printf("Item edited at position %d", pos);
            else
                printf("Item not found");
            break;
        case 9:
            traverse();
            break;
        default:
            printf("\n Enter the choice between 1 to 10 \n");
        
        }
    } while (ch < 10);
}
