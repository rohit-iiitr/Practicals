#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int data;
    //struct node * prev;
    struct node * next;
};
struct node *head, *temp;

struct node* create(struct node** head){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    int n;
    printf("Enter the data: ");
    scanf("%d",&n);
    newnode -> data=n;
    newnode -> next = NULL;
    if(*head == NULL){
        *head = newnode;
        newnode -> next = newnode;
    }
    else{
        temp = *head;
        while(temp != NULL){
             temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> next = *head;
        
    }
    printf("\n");
    return *head;
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
    do{
        
        printf("Enter the choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            head = create(&head);
            break;
            case 2:
            head = display(head);
        }
    } while(choice !=3);
    return 0;
}