#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //contains declarations for all of the functions in the Windows API
typedef struct node
{
    int id;
    char brand_name[50];
    char tag[50];
    int quantity;
    int location;
    struct node *next;
} NODE;
NODE *add_product(NODE *first)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE)), *temp;
    printf("Enter the brand name:");
    scanf("%s", newnode->brand_name);
    printf("Enter the tag:");
    scanf("%s", newnode->tag);
    printf("Enter the quantity:");
    scanf("%d", &newnode->quantity);
    printf("Enter the location or row number:");
    scanf("%d", &newnode->location);
    newnode->next = NULL;
    if (first == NULL)
    {
        newnode->id = 1;
        first = newnode;
    }
    else
    {
        temp = first;
        while (temp->next != NULL)
            temp = temp->next;
        newnode->id = temp->id + 1;
        temp->next = newnode;
    }
    printf("The item has been added successfully\n");
    return first;
}
NODE *delete_product(NODE *first)
{
    if (first == NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }
    int key;
    NODE *temp = first, *prev = NULL;
    printf("Enter the id to be deleted:\n");
    scanf("%d", &key);
    while (temp != NULL && temp->id != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("The id is not present\n");
        return first;
    }
    printf("The id %d info is deleting...\n", temp->id);
    if (prev == NULL)
        first = temp->next;
    else
        prev->next = temp->next;
    free(temp);
    return first;
}
void update_product(NODE *first)
{
    if (first == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    int key;
    printf("Enter the id whose info is to be updated:\n");
    scanf("%d", &key);
    while (first != NULL && first->id != key)
        first = first->next;
    if (first == NULL)
    {
        printf("The id is not present\n");
        return;
    }
    printf("The id %d is found\n", key);
change:
    printf("Which info is to be edited:\n");
    printf("1. Brand name\n2. Tag\n3. Quantity\n4. Location\nEnter the choice:");
    scanf("%d", &key);
    switch (key)
    {
    case 1:
        printf("Enter the updated brand name: ");
        scanf("%s", first->brand_name);
        break;
    case 2:
        printf("Enter the updated tag: ");
        scanf("%s", first->tag);
        break;
    case 3:
        printf("Enter the updated quantity: ");
        scanf("%d", &first->quantity);
        break;
    case 4:
        printf("Enter the updated location: ");
        scanf("%d", &first->location);
        break;
    default:
        printf("Wrong choice\n");
        Sleep(1000);
        goto change;
    }
}
void find_product(NODE *first)
{
    if (first == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    int key;
    printf("Enter the id whose info is to be found:\n");
    scanf("%d", &key);
    while (first != NULL && first->id != key)
        first = first->next;
    if (first == NULL)
    {
        printf("The id is not present\n");
        return;
    }
    printf("The id %d is found\n", key);
    printf("Id: %d\n", first->id);
    printf("Brand name: %s\n", first->brand_name);
    printf("Tag: %s\n", first->tag);
    printf("Quantity: %d\n", first->quantity);
    printf("Location: %d\n", first->location);
}
void list_product_tags(NODE *first)
{
    if (first == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    int flag = 0;
    char ch[50];
    printf("Enter the tag whose info is to be found:\n");
    scanf("%s", ch);
    while (first != NULL)
    {
        if (!strcmp(ch, first->tag))
        {
            if (flag == 0)
            {
                printf("\nID\tBrand name\t\tQuantity\tLocation\n");
                flag = 1;
            }
            printf("%d\t%s\t%d\t%d\n", first->id, first->brand_name, first->quantity, first->location);
        }
        first = first->next;
    }
    if (flag == 0)
        printf("There is no matching element\n");
}
void list_product_brand(NODE *first)
{
    if (first == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    int flag = 0;
    char ch[50];
    printf("Enter the Brand name whose info is to be found:\n");
    scanf("%s", ch);
    while (first != NULL)
    {
        if (!strcmp(ch, first->brand_name))
        {
            if (flag == 0)
            {
                printf("\nID\tTag\t\tQuantity\tLocation\n");
                flag = 1;
            }
            printf("%d\t%s\t%d\t%d\n", first->id, first->tag, first->quantity, first->location);
        }
        first = first->next;
    }
    if (flag == 0)
        printf("There is no matching element\n");
}
int main()
{
    int choice;
    NODE *first = NULL;
    printf("Welcome to EASY SHOPPING in MART\n");
    for (;;)
    {
        printf("1. Add a product\n");
        printf("2. Delete a product\n");
        printf("3. Update a product\n");
        printf("4. Find a product\n");
        printf("5. List the product by tags\n");
        printf("6. List the product by brand name\n");
        printf("7. Exit\n");
        printf("Enter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = add_product(first);
            break;
        case 2:
            first = delete_product(first);
            break;
        case 3:
            update_product(first);
            break;
        case 4:
            find_product(first);
            break;
        case 5:
            list_product_tags(first);
            break;
        case 6:
            list_product_brand(first);
            break;
        case 7:
            printf("Thank you for using the EASY SHOPPING in MART");
            exit(0);
        default:
            printf("\nEnter the correct choice\n");
        }
        Sleep(1000);
    }
    return 0;
}
