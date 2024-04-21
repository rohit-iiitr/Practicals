#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head, *temp;

struct node* createnode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    printf("\n");
    return newnode;
}

void insertatend(struct node**head,int data){
    struct node*newnode = createnode(data);
    struct node*temp=*head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
       
    }
    temp->next=newnode;  
}

void insertbegin(struct node**head,int data){
    struct node*newnode = createnode(data);
    newnode->next=*head;
    *head=newnode;

}

void deleteList(struct Node** head) {
    temp = *head;
    struct Node* xyz;
    while (temp != NULL) {
        xyz = temp->next;
        free(temp);
        temp = xyz;
    }
    *head = NULL;
}

struct node * display(struct node *head){
   
    temp = head;
    while(temp!=NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    } printf("\n\n");
    return head;
}

int main(){
    int choice;
    int data;
    do{
        printf("press 1 for create a list\n");
        printf("press 2 insert at end in list\n");
        printf("press 3 insert at beginning in list\n");
        printf("press 4 to delete the list\n");
        printf("press 5 for display element of list\n");
    printf("Enter the choice: ");
    scanf("%d",&choice);
    switch(choice){
       
        case 1:
        createnode(data);
        break;

        case 2:
        printf("\nenter data want to insert at end");
        scanf("%d",&data);
        insertatend(&head,data);
        break;

        case 3:
        printf("\nenter data want to insert at begin");
        scanf("%d",&data);
        insertbegin(&head,data);
        display(head);

        case 4:
        deleteList(&head);
        break;

        case 5:
        head = display(head);
        break;

    } 
    } while(choice!=5);
    return 0;
}