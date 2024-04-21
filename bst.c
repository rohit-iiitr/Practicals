#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<limits.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

bool search(struct TreeNode* root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

struct TreeNode* deleteNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        struct TreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

bool isBSTUtil(struct TreeNode* root, int min, int max) {
    if (root == NULL) {
        return true;
    }
    if (root->data < min || root->data > max) {
        return false;
    }
    return isBSTUtil(root->left, min, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, max);
}

bool isBST(struct TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int choice, value;
    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Print Inorder Traversal\n");
        printf("5. Check if BST\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    printf("%d is present in the BST.\n", value);
                } else {
                    printf("%d is not present in the BST.\n", value);
                }
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 4:
                printf("Inorder Traversal of BST: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                if (isBST(root)) {
                    printf("The tree is a valid Binary Search Tree.\n");
                } else {
                    printf("The tree is not a valid Binary Search Tree.\n");
                }
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}
