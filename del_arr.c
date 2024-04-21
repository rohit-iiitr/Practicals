#include<stdio.h>
void first(int arr[],int size){
    printf("Array after delete from first");
    for(int i=1;i<size;i++){
        printf("%d ",arr[i]);
    }
}
void last(int arr[],int size){
    printf("Array after delete from last: ");
    for(int i=0;i<size-1;i++){
        printf("%d",arr[i]);
    }
}
void after(int arr[],int size){
    int el,index;
    scanf("%d",&el);
   for (int i = 0; i < size; i++)
   {
    if(arr[i] == el) index = i; 
   }

   for (int i = index+1; i < size-1; i++)
   {
    int temp = arr[i];
    arr[i] = arr[i+1];
    arr[i+1] = temp;
   }
   for (int i = 0; i < size-1; i++)
   {
    printf("%d ",arr[i]);
   }

}
int main(){
    int choice;
    printf("Press 1 for delete element from first\n");
    printf("Press 2 for delete element from second\n");
    printf("Press 3 for delete element after given element\n");
    printf("Enter the choice: ");
    scanf("%d",&choice);
    int size;
    printf("Enter the size of an array: ");
    scanf("%d",&size);
    int arr[size+1];
    printf("Enter the elements: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Original array: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]); 
    }
    printf("\n");
    switch(choice){
        case 1:{
            first(arr,size);
        }
        case 2:{
            last(arr,size);
        }
        case 3:{
            after(arr,size);
        }
    }
}