#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**************************
 * Defines the structure of
 * Linked-List
 * ***********************/
typedef struct linked_list
{
    int data;
    struct linked_list *next;
} * node;
/**************************
 * initialize and make a 
 *  node
 *************************/
node createNode()
{
    node temp = NULL;
    temp = (node)malloc(sizeof(struct linked_list));
    temp->next = NULL;
    return temp;
}
/**************************
 * Returns Index n of lin-
 * ked-list ll 
 *************************/
node getElementByIndex(node l, int n)
{
    node temp = l;
    for (int i = 0; i < n; i++)
    {
        if (temp == NULL)
            return NULL;
        temp = temp->next;
    }
    return temp;
}
/**************************
 * Prints linked list till 
 * it finishes!
 * ***********************/
void print_list(node head)
{
    node temp = head;
    int i = 0;
    printf("================================\n");
    printf("LIST %p VALUES ARE :\n", head);
    printf("================================\n");
    printf("[#INDEX] -> VALUE\n");
    while (temp != NULL)
    {
        if (i == 0)
            printf("[#%d] -> HEAD\n", i++);
        else
            printf("[#%d] -> %d\n", i++, temp->data);
        temp = temp->next;
    }
}
/***************************
 * Inserts a node into the 
 * Linked-List
 * *************************/
bool insert_node(node ll, int value, int index)
{
    node temp = createNode();
    temp->data = value;
    node head = getElementByIndex(ll, index);
    int i = 0;

    bool flag = false;
    if (((temp != NULL) && (head != NULL)))
    {
        temp->next = head->next;
        head->next = temp;
        flag = true;
    }
    return flag;
}
/***************************
 * Deletes a node from the
 * Linked-List
 * *************************/
bool delete_node(node ll, int index)
{
    
    bool flag = false;
    if (index == 0){return flag;}// List at least has a head!
    node element = getElementByIndex(ll, index);
    node parent = getElementByIndex(ll, index - 1);
    if (element != NULL)
    {
        flag = true;
        parent->next = element->next;
        free(element);
    }
    return flag;
}
/*****************************
 * Returns List Size
 * ***************************/
int sizeList(node l)
{
    node temp = l;
    int i = -1;
    for (;; i++)
    {
        if (temp == NULL)
            break;
        temp = temp->next;
    }
    return i;
}

int main(int argc, char const *argv[])
{
    node l = createNode();

    printf("================================\n");
    printf("WELCOME! You have a list of INTs\n");
    printf("in memory address %p\n", l);
    printf("================================\n");
    print_list(l);
    while (-1)
    {
        int userInput;
        printf("********************************\n");
        printf("-ADD TO LIST      ----> ENTER 1 \n");
        printf("-DELETE FROM LIST ----> ENTER 2 \n");
        printf("***EXIT           ----> ENTER 0 \n");
        printf("********************************\n");
        scanf("%d", &userInput);
        int u_index, u_value;
        switch (userInput)
        {
        case 0:
            printf("********************************\n");
            printf("**EXIT COMMAND  \n");
            print_list(l);
            printf("Exit...!");
            return 0;
            break;

        case 1:
            printf("********************************\n");
            printf("**ADD   COMMAND  \n");
            printf("->Enter an INTEGER    VALUE \n");
            scanf("%d", &u_value);
            printf("->Enter prefered LIST INDEX \n");
            printf("INDEX IS UNSIGNED INT =< %d \n", sizeList(l));
            scanf("%d", &u_index);
            if (insert_node(l, u_value, u_index))
            {
                printf("INTEGER %d Added!\n", u_value);
            }
            else
            {
                printf("ERROR!\n");
            }

            break;
        case 2:
            printf("********************************\n");
            printf("**DELETE COMMAND  \n");
            printf("->Enter prefered LIST INDEX \n");
            // printf("INDEX IS UNSIGNED INT =< %d \n", sizeList(l));
            scanf("%d", &u_index);
            if (delete_node(l, u_index))
            {
                printf("INTEGER INDEX %d Deleted!\n", u_index);
            }
            else
            {
                printf("ERROR!\n");
            }
            break;
        default:
            printf("********************************\n");
            printf("UNSUPPORTED INPUT!");
            return 0;
        }
        print_list(l);
    }

    return 0;
}
