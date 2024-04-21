#include<stdio.h>
#include<stdlib.h>

#define N 5
int queue[N];
int front = -1; 
int rear = -1;

void enqueue(int x){
    if (front == -1 && rear == -1)
    {
      front = rear = 0;
      queue[rear] = x; 
    }
    else if ((rear+1)% N==front)
    {
        printf("\nqueue is full");
        
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
    
}
void dequeue(){
    if (front==-1 && rear == -1)
    {
        printf("\nqueue is empty");
        
    }
    else if (front==rear)
    {
        printf("\nDequeued element is %d",queue[front]);
        front = rear = -1;
     
    }
    else{
        printf("\nDequeued element is %d",queue[front]);
        front = (front + 1)%N;
    }
    
    
}
void display(){
    int i=front;
    if (front==-1 && rear==-1)
    {
        printf("\nqueue is empty");
        /* code */
    }
    else{
        printf("\nqueue is\n");
        while (i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%N;
            /* code */
        }
    } printf("%d",queue[rear]);
    }
    

int main(){
    int choice,x;
    // do
    while(1)
    {
       
        printf("\n\n1. ENQ");
        printf("\n2. DEQ");
        printf("\n3. DISPLAY");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
switch (choice)
{
case 1:
printf("\nenter data want to enqueue: ");
scanf("%d",&x);
enqueue(x);
    break;

case 2:
dequeue();
break;

case 3:
display();
break;
}

        /* code */
    } 
    // while (choice!=4);
    
}