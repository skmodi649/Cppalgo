#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *ptrtonxtnode;
};
struct node *head;
void insertAtBeg();
void showList();

void insertAtBeg()
{
    struct node *newptr;
    int val;
    if(newptr == NULL){
        printf("List in empty")
    }
    else{
    // Now dynamically allocating memeory to the node created
    newptr = (struct node*)malloc(sizeof(struct node*));
    printf("Enter the value to be inserted\n");
    scanf("%d",&val);
    newptr->data = val;
    newptr->ptrtonxtnode = head;
    head = newptr;
    printf("The element has been inserted\n");
    }
}
void showList(){
    struct node *temp;
    temp = head;
    if(temp == NULL){
        printf("List is empty\n");
    }
    else{
    temp = (struct node*)malloc(sizeof(struct node*));
    printf("The elements in the Linked list are : \n");
    while(temp != NULL){
        int value = temp->data;
        printf("\n%d",value);
    }
}
}
int main(){
    int choice;
    printf("Enter your choice\n1 for inserting at beginning\n2 for the displaying the linked list\n3 for exiting\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        insertAtBeg();
        break;
    case 2:
    showList();
    break;
    case 3:
    exit;
    }
    return 0;
}