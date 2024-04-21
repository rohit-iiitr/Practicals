#include<stdio.h>
int hash[100]={0};
int main(){
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    printf("Original array : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    int choice,select;
    int p;
        printf("\n");
   do{
        printf("press 1 for find frequency\n");
        printf("press 2 for print element of max frequency\n");
        printf("press 3 for delete duplicate\n");
        printf("Enter -1 for end the program\n");
         printf("Enter the choice : ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:{
                //printf("Frequency of elements is: ");
                printf("Elements   frequency\n");
               int ans[n];
                    int p =0;
                    for(int i=0;i<n-1;i++){
                        if(arr[i]!=arr[i+1]){
                            ans[p]=arr[i];
                            p++;
                        }
                    }
                    for(int i=0;i<=n;i++){
                        printf("%d          %d\n",arr[i],hash[arr[i]]);
                    }
               //printf("\n");
               break;
            }
            case 2:{
                    for(int i=0;i<n;i++){
                        if(hash[arr[i]]>1) printf("%d ",arr[i]);
                    }
                }
                printf("\n");
                break;
            }
        } while(choice =-1);
}