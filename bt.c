#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left, *right ;
};

struct node* createnode(int data){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        if(newnode == NULL){
            return NULL;
        }
        newnode ->data = data;
        newnode -> right = NULL;
        newnode -> left = NULL;
        return newnode;
        printf("\n");
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createnode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct node* root){
    if(root!=NULL){
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right); 
    }
    printf("\n");
}

void preorder(struct node* root){
    if(root!=NULL){
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
     }
    printf("\n");
}

void postorder(struct node* root){
    if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data); 
    }
    printf("\n");
}

int main(){
    int value;
    struct node* root;
    printf("Enter the root value of tree :");
    scanf("%d",&value);
    root = createnode(value);
    int choice;
    do{
        printf("\nPress 1 for create child node\n");
        printf("Press 2 to print inorder traversal\n");
        printf("Press 3 for print in preorder traversal\n");
        printf("Press 4 to print in postorder traversal\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the value of child :");
            scanf("%d",&value);
            insert(root,value);
            // root->left = createnode(value);
            // root = root->left;
            break;

            case 2:
            inorder(root);
            break;

            case 3:
            preorder(root);
            break;

            case 4:
            postorder(root);
            break;

            case 5:
            printf("Press 5 to exit the programme");
            break;

            default:
            printf("Invalid choice\n");
        } 
    } while(choice!=5);

    return 0;
}