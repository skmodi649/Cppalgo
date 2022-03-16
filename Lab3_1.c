#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
struct stu_data
{
int regno;
int age;
char stuName[MAX];
char phonenum[MAX];
struct stu_data *next;
};
struct stu_data *insert(struct stu_data *front, int id, int new_age,char name[],char phone[],int cage)
{
if(cage<5){
struct stu_data *newnode;
newnode = (struct stu_data*)malloc(sizeof(struct stu_data));
if (newnode == NULL)
{
printf("\n Allocation failed \n");
exit(2);
}
newnode->regno = id;
newnode->age = new_age;
strcpy(newnode->stuName, name);
strcpy(newnode->phonenum, phone);
newnode->next = front;
front = newnode;
return(front);
}
else{
printf("more than 5 people of same age are present");
}
}
void printNode(struct stu_data *p)
{
printf("\n Student Details...\n");
printf("\n Student Number : %d", p->regno);
printf("\n Student Age : %d", p->age);
printf("\n Name : %s", p->stuName);
printf("\n phone number : %s\n", p->phonenum);
printf("-------------------------------------\n");
}
struct stu_data* deleteNode(struct stu_data *front, int id)
{
struct stu_data *ptr;
struct stu_data *bptr;
if (front->regno == id)
{
ptr = front;
printf("\n Node deleted:");
printNode(front);
front = front->next;
free(ptr);
return(front);
}
for (ptr = front->next, bptr = front; ptr != NULL; ptr = ptr->next,bptr = bptr->next)
{
if (ptr->regno == id)
{
printf("\n Node deleted:");
printNode(ptr);
bptr->next = ptr->next;
free(ptr);
return(front);
}
}
printf("\n Student Number %d not found ", id);
return(front);
}
void search(struct stu_data *front, int key)
{
struct stu_data *ptr;
for (ptr = front; ptr != NULL; ptr = ptr -> next)
{
if (ptr->regno == key)
{
printf("\n Key found:");
printNode(ptr);
return;
}
}
printf("\n Student Number %d not found ", key);
}
int count(struct stu_data *front, int key)
{
struct stu_data *ptr;
int c=0;
for (ptr = front; ptr != NULL; ptr = ptr -> next)
{
if (ptr->age == key)
{
c++;
}
}
return c;
}
void display(struct stu_data *front)
{
struct stu_data *ptr;
for (ptr = front; ptr != NULL; ptr = ptr->next)
{
printNode(ptr);
}
}
void menu()
{
printf("---------------------------------------------\n");
printf("Press 1 to INSERT a node into the list \n");
printf("Press 2 to DELETE a node from the list \n");
printf("Press 3 to DISPLAY the list \n");
printf("Press 4 to SEARCH the list \n");
printf("Press 5 to EXIT \n");
printf("---------------------------------------------\n");
}
char option()
{
char choice;
printf("\n\n>> Enter your choice: ");
switch(choice=getchar())
{
case '1':
case '2':
case '3':
case '4':
case '5': return(choice);
default : printf("\n Invalid choice.");
}
return choice;
}
/* End of option() */
/* The main() program begins */
void main()
{
    printf("Name : Suraj Kumar");
    printf("Registartion Number : 20BCE2835");
    printf("-----------------------------------------------");
struct stu_data *linkList;
char name[21], phone[51];int age;
char choice;
int sno;
linkList = NULL;
printf("\n Welcome to demonstration of singly linked list \n");
menu();
do
{
/* choose oeration to be performed */
int cage=count(linkList, age);
choice = option();
switch(choice)
{
case '1':
printf("\n Enter the Student Reg Number : ");
scanf("%d", &sno);
printf("\n Enter the Student Age: ");
scanf("%d", &age);
printf("Enter the Student name : ");
fflush(stdin);
gets(name);
printf("Enter the Student phone number: ");
gets(phone);
linkList = insert(linkList, sno, age, name, phone,cage);
break;
case '2':
printf("\n\n Enter the Student number to be deleted:
"); scanf("%d", &sno);
linkList = deleteNode(linkList, sno);
break;
case '3':
if (linkList == NULL)
{
printf("\n List empty.");
break;
}
display(linkList);
break;
case '4':
printf("\n\n Enter the employee number to be searched: ");
scanf("%d", &sno);
search(linkList, sno);
break;
case '5': break;
}
} while (choice != '5');