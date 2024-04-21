#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* prev, *next;

};

struct node* temp , *head;

struct node*createnode(int data){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;

    printf("\n");
}

void insertAtEnd(struct node **head,int data){
struct node*newnode = createnode(data);

if (*head==NULL){
    *head=newnode;
}

else{
    struct node *p = *head;
    while(p->next!=NULL){   
        p = p->next;
    }
    p ->next = newnode;
    newnode->prev = p;
}
printf("\n");
}

void duplicate(struct node* head){
        int arr[100]={0};
        temp = head;
        while(temp->next!=NULL){
            int val = temp->data;
            arr[val]++;
            temp = temp->next;
        }

        printf("\nDuplicate elements   frequency\n");
        for(int i=0;i<100;i++){
            if(arr[i]>1){
                printf("%d               %d\n",i,arr[i]);
            }
        }

        printf("\n");
}

void insertatposition(struct node**head,int data,int position){
    int i=1;
    struct node*newnode = createnode(data);
    struct node*temp = *head;
    while(i<position-1){
        temp=temp->next;
        i++;

    }

    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    newnode -> next -> prev = newnode;
    printf("\n");
}

void deleteatend(struct node**head){
    struct node*temp=*head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
     
    }
    temp->prev->next=NULL;
    free(temp);
    printf("\n");
}

void display(struct node*head){
    struct node*temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;

      }
    printf("\n");
    

}

int main(){

    int choice,num;
    int position;
    int data; 
    do{
        printf("Enter 1 to createnode\n");
        printf("Enter 2 to insert element\n");
        printf("Enter 3 to check duplicate element\n");
        printf("Enter 4 to update element\n");
        printf("Enter 5 to delete element from list\n");
        printf("Enter 6  to display\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        printf("\n");
            switch(choice){
                case 1:
                createnode(data);
                break;

                case 2:
                printf("enter number of nodes: ");
                scanf("%d",&num);
                for (int i = 0; i < num; i++)
                {
                    printf("enter data for node %d ",i+1);
                    scanf("%d",&data);
                    insertAtEnd(&head,data);
       
                }
                break;

                case 3:
                duplicate(head);
                break;

                case 4:
                printf("Enter the position :");
                scanf("%d",&position);
                insertatposition(&head,data,position);
                break;

                case 5:
                deleteatend(&head);
                break;

                case 6:
                display(head);
                break;
            }
        
    
    
    } while(choice!=7);
    return 0;
}