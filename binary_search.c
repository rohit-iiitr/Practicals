#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp;
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                            }
        }}
    int low = 0;
    int high = n-1;
    int key;
    printf("Enter the key: ");
    scanf("%d",&key);
    int steps = 0 ; 

    while(low<=high){
        steps++;
        int mid;
        mid = low + (high - low)/2;
        if(arr[mid] == key){
            printf("Element found\n");
            break;
        }
        if(arr[mid]<key){
            low = mid + 1;
        }
        else if(arr[mid]>key) high = mid - 1;
        else printf("Element not found\n");
    }
    printf("No. of steps: %d",steps);
}