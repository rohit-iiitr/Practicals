//WAP to implement QUEUE using array and function
#include<stdio.h>
int top = -1;
int low = -1;
void enqueue(int arr[],int n){
    int data;
    if(top == n-1) printf("Queue is full");
    else{printf("Enter the element: ");
    scanf("%d",&data);
        top++; 
        arr[top]=data;
        if(low==-1) low = 0;
    }
    printf("\n");
}

 void dequeue(){
    if(low == top) printf("Queue is empty\n");
    else low = low + 1;
    printf("\n");
}

int peek(int arr[]){
    printf("%d",arr[top]);
    printf("\n");
    return 0;

}

int display(int arr[]){
    for(int i=low;i<=top;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    int choice;
    printf("\n");
    do{
        printf("1 : For enqueue\n");
        printf("2: Dequeue\n");
        printf("3: Peek element\n");
        printf("4: Display\n");
        printf("5: Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            enqueue(arr,n);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            peek(arr);
            break;
            case 4:
            display(arr);
        }
    } while(choice !=5);
    return 0;
}