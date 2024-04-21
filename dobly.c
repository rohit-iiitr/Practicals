#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev, *next;
};

struct node* head, *temp;

struct node* createnode(int val){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value :");
    scanf("%d",&val);
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    
}

void insert_at_end(struct node** head, int val){
    struct node* newnode = createnode(val);
    if(*head == NULL){
        *head = newnode;
    }
    else{
        temp = *head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
    printf("\n");
}

void insert_at_begg(struct node** head, int val){
    struct node* newnode = createnode(val);
    newnode->next = (*head);
    (*head) ->prev = newnode;
    printf("\n");
}

void findDuplicates(struct Node* head) {
    struct node* current = head;
    while (current != NULL) {
        int count = 1;
         temp = current->next;
        while (temp != NULL) {
            if (current->data == temp->data) {
                count++;
            }
            temp = temp->next;
        }
        if (count > 1) {
            printf("Element %d is duplicated %d times.\n", current->data, count);
        }
        current = current->next;
    }
}

void deleteList(struct Node** head) {
    struct node* current = *head;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
    *head = NULL; // Reset head to NULL as the list is now empty
}

void reverse(struct node *head){
    struct node*temp=head;
    while (temp->next!=NULL){
        temp=temp->next; 
    }
printf("reverse linked list is\n");
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
       
    }   
}

void display(struct node* head){
    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
int choice;
int val;
do{
     printf("press 1 for createnode\n");
     printf("press 2 for insert at end \n");
     printf("press 3 for insert element at begg.\n");
     printf("press 4 to check duplicate element\n");
     printf("press 5 for empty the list\n");
     printf("press 6 to rotate list\n");
     printf("press 7 to display\n");
     printf("8 : Exit");
     printf("Enter the choice : ");
     scanf("%d",&choice);
     switch(choice){
        case 1:
        createnode(val);
        break;

        case 2:
        insert_at_end(&head, val);
        break;

        case 3:
        insert_at_begg(&head, val);
        break;

        case 4:
        findDuplicates(head);
        break;

        case 5:
        deleteList(&head);
        break;

        case 6:
        reverse(head);

        case 7:
        display(head);
        break;
     }
} while(choice!=8);
}