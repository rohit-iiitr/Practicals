#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    
    int arr[n];
    printf("Enter the array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Original array :\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int count =0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp;
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                count++;
                            }
        }
    }
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
    printf("No. of steps in sorting: %d",count);
    return 0;

}