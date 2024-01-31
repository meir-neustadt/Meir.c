#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check validiaty of the score

int checkScore(int score){
    if(score<0 || score>100){return -1;}
    if(score<55){return 0;}
    return score;
}

// Structure for a node in the BST
struct Node {
    int score;
    char name[12];
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int score, const char name[20]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->score = checkScore(score);
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a score into the BST
struct Node* insert(struct Node* root, int score, const char *name) {
    if (root == NULL) {
        return createNode(score, name);
    }

    if (score < root->score) {
        root->left = insert(root->left, score, name);
    } else {
        root->right = insert(root->right, score, name);
    }

    return root;
}

// Function to perform an in-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%s\t%d\n", root->name, root->score);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert scores into the BST
    root = insert(root, 58, "John");
    insert(root, 83, "Alice");
    insert(root, 67, "Bob");
    insert(root, 40, "Charlie");
    insert(root, 81, "Eva");
    insert(root, 67, "David");
    insert(root, -3, "Frank");
    insert(root, 88, "Grace");
    insert(root, 57, "Henry");
    insert(root, 100, "Meir");

    // Perform in-order traversal and display the elements
    printf("In-order traversal:\n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
