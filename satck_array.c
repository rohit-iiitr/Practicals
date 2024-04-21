#include <stdio.h>
void push(int arr[], int *top, int n) {
    if (*top == n - 1) {
        printf("Stack is full\n");
        return;
    }
    printf("Enter the element to push: ");
    scanf("%d", &arr[++*top]);
}
void display(int arr[], int top) {
    printf("Elements in stack are: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void pop(int *top,int arr[]){
    if (*top == -1) {
                    printf("Stack is empty\n");
                } else {
                    printf("Popped element: %d\n", arr[*top--]);
                }
}

void del_all_ele(int *top,int arr[]){
    *top=  -1;
}
int main() {
    int n;
    printf("Enter the size of stack: ");
    scanf("%d", &n);
    printf("\n");
    int arr[n];
    int top = -1;  
    int choice;
    do {
        printf("Enter 1 to push element in stack\n");
        printf("Enter 2 for display elements of stack\n");
        printf("Enter 3 for pop element in stack\n");
        printf("Enter 4 for display the peak element\n");
        printf("Enter 5 to delete all the element form stack\n");
        printf("Enter 6 to exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:{
                push(arr, &top, n);
                //printf("Elements of the stack is: ");
                //display(arr,top);
                break;}
            case 2:{
                display(arr, top);
                break;}
            case 3:{
                pop(&top,arr);
                printf("Elements of the stack is: ");
                //display(arr,top);
                break;}
            case 4:{
                printf("Peak element :");
                printf("%d",arr[top]);
            }
            case 5:{
                del_all_ele(&top,arr);
                //display(arr, top);
                break;
            }
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}