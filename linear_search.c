#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int steps = 0;
    int key ;
    printf("Enter the key: ");
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("Key found");
            steps = i+1;        }
    }
    printf("\n");
    printf("No. of steps: %d",steps);
}