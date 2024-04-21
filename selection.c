#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of an array :");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of an array :");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int count=0;
    for(int i=0;i<n-1;i++){
        int temp = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<=arr[temp]){
                temp = j;
            }}
                int ans = arr[i];
                arr[i]=arr[temp];
                arr[temp]=ans;
                count++;
    }
    printf("Sorted elements :");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("No. of steps :%d",count);
}