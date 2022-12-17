// Aryan Dhotre 21BCY10037
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *notnext; // previous pointer
};
typedef struct node NODE;
NODE *head;

int menu()
{
    int ch;
    printf("\nPress,\n1. Insert Begin\n2. Insert End\n3. Insert Position");
    printf("\n4. Delete Begin\n5. Delete End\n6. Delete Element");
    printf("\n7. Search\n8. Edit\n9. Traverse from front\n10. Traverse from back");
    printf("\n11. Exit\nYour Choice :");
    scanf("%d", &ch);
    return (ch);
}

void insert_begin(int item)
{
    NODE *curr;
    curr = (NODE *)malloc(sizeof(NODE));
    curr->data = item;
    if (head == NULL)
    { // first element condition
        curr->next = NULL;
        curr->notnext = NULL; // since first element, previous pointer is NULL
    }
    else
    {                         // not the first element
        curr->next = head;    // points to the first element
        curr->notnext = NULL; // since (new)first element, previous pointer is NULL
        head->notnext = curr; // points to the new first element
    }
    head = curr;
}

void insert_end(int item)
{
    NODE *curr, *prev;
    curr = (NODE *)malloc(sizeof(NODE));
    curr->data = item;
    curr->next = NULL;
    if (head == NULL)
    {                         // first element condition
        curr->notnext = NULL; // since first element, previous pointer is NULL
        head = curr;
    }
    else
    { // not the first element
        prev = head;
        while (prev->next != NULL)
            prev = prev->next;
        prev->next = curr;
        curr->notnext = prev;
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
        head->notnext = NULL; // since first element, previous pointer is NULL
        printf("\nDeleted element is %d", curr->data);
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
    { // when there is only one element
        curr = head;
        head = NULL;
        printf("\nDeleted element is %d", curr->data);
        free(curr);
    }
    else
    {
        prev = head;
        curr = head->next;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        prev = curr->notnext;
        prev->next = NULL;
        printf("\nDeleted element is %d", curr->data);
        free(curr);
    }
}

void insert_position(int item, int pos)
{
    NODE *curr, *prev;
    int i;
    curr = head;
    for (i = 1; i < pos - 1; i++)
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
    { // inserting in first position
        prev->next = head;
        prev->notnext = NULL;
        head = prev;
    }
    else
    {
        prev->next = curr->next;
        prev->notnext = curr;
        curr->next = prev;
    }
}
int edit_item(int item, int ritem)
{
    NODE *curr;
    curr = head;
    int i = 0;
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
    return 0;
}

void traverse_from_front()
{
    NODE *curr;
    if (head == NULL)
    {
        printf("\nLinked list is empty , No traverse operation");
        return;
    }
    else
    {
        curr = head;
        while (curr != NULL)
        {
            printf("%d->", curr->data);
            curr = curr->next;
        }
        printf("Nil\n");
    }
}

void traverse_from_back()
{
    NODE *curr;
    if (head == NULL)
    {
        printf("\nLinked list is empty , No traverse operation");
        return;
    }
    else
    {
        curr = head;
        while (curr->next != NULL) // getting to the last element
        {
            curr = curr->next;
        }
        while (curr != NULL)
        {
            printf("%d->", curr->data);
            curr = curr->notnext;
        }
        printf("Nil\n");
    }
}

int serach(int item)
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
    return 0;
}

void delete_item(int item)
{
    NODE *curr, *prev;
    if (head == NULL)
    {
        printf("\nLinked list is empty , No delete operation");
        return;
    }
    else
    {
        curr = head;
        while (curr->data != item)
        {
            curr = curr->next;
        }
        prev = curr->notnext;
        prev->next = curr->next;
        curr->next->notnext = prev;
        printf("\nDeleted element is %d", curr->data);
        free(curr);
    }
}

int main()
{
    int ch, item, pos, ritem;
    head = NULL;
    do
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be inserted :");
            scanf("%d", &item);
            insert_begin(item);
            break;
        case 2:
            printf("\nEnter the element to be inserted :");
            scanf("%d", &item);
            insert_end(item);
            break;
        case 3:
            printf("\nEnter the element to be inserted :");
            scanf("%d", &item);
            printf("\nEnter the position :");
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
            printf("\nEnter the element to be deleted :");
            scanf("%d", &item);
            delete_item(item);
            break;
        case 7:
            printf("\nEnter the element to be searched :");
            scanf("%d", &item);
            pos = serach(item);
            if (pos > 0)
                printf("Item found at position %d", pos);
            else
                printf("Item not found");

            break;
        case 8:
            printf("\nEnter the element to be edited :");
            scanf("%d", &item);
            printf("\nEnter the element to be replaced :");
            scanf("%d", &ritem);
            pos = edit_item(item, ritem);
            if (pos != 0)
            {
                printf("Item ednted at position %d", pos);
            }
            else
                printf("Item not found");
            break;
        case 9:
            traverse_from_front();
            break;
        case 10:
            traverse_from_back();
            break;
        default:
            printf("\nInvalid choice (Enter between 1-10)");
        }

    } while (ch < 11);
    return 0;
}