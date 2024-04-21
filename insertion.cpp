#include<stdio.h>
void last(int arr[],int size){
    int element;
    scanf("%d",&element);
    arr[size-1]=element;
    printf("After adding element in last : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
void first(int arr[],int size){
    for(int i=size;i>=1;i--){
        arr[i]=arr[i-1];
    }
    int element;
    scanf("%d",&element);
    arr[0]=element;
    printf("Ater adding element in last: ");
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    }
}
void after(int arr[],int size){
     int el1, el2, index;
    printf("Element after which add: ");
    scanf("%d",&el1);
    printf("Element to be add: ");
    scanf("%d",&el2);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == el1)
            index = i;
    }
    for (int i = size; i >= index + 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index + 1] = el2;
    printf("after adding element to given element: ");
    for (int i = 0; i < size + 1; i++)
    {
        printf("%d ", arr[i]);
    }

}
int main(){
    int choice;
    printf("Press 1 for adding elements in last\n");
    printf("Press 2 for adding element in first\n");
    printf("Press 3 for inserting element next after given element\n");
    printf("Enter the choice : ");
    
    scanf("%d",&choice);
    int size;
    printf("Enter the size of an array: ");
    scanf("%d",&size);
    int arr[size+1];
    printf("Enter the array: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    
    switch(choice){
        case 1:{
            last(arr,size);
        }
        case 2:{
            first(arr,size);
        }
        case 3:{
            after(arr,size);
        }
    }
}