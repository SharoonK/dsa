#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char key[20];
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char key[]) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->key, key);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, char key[]) {
    if (root == NULL)
        return createNode(key);

    if (strcmp(key, root->key) < 0)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s ", root->key);
        inorder(root->right);
    }
}

int bstSearch(struct Node *root, char key[]) {
    int comparisons = 0;

    while (root != NULL) {
        comparisons++;

        if (strcmp(key, root->key) == 0)
            return comparisons;

        if (strcmp(key, root->key) < 0)
            root = root->left;
        else
            root = root->right;
    }

    return comparisons;
}

int linearSearch(char arr[][20], int n, char key[]) {
    int comparisons = 0;

    for (int i = 0; i < n; i++) {
        comparisons++;

        if (strcmp(arr[i], key) == 0)
            return comparisons;
    }

    return comparisons;
}

int main() {
    char keys[][20] = {
        "A102", "A25", "A7", "B100",
        "B12", "A120", "B3", "A45"
    };

    int n = 8;
    struct Node *root = NULL;

    for (int i = 0; i < n; i++)
        root = insert(root, keys[i]);

    printf("Inorder Traversal:\n");
    inorder(root);

    printf("\n\nSearch Comparison:\n");

    char searchKeys[][20] = {
        "A120", "B3", "A45", "B100"
    };

    for (int i = 0; i < 4; i++) {
        int bst = bstSearch(root, searchKeys[i]);
        int linear = linearSearch(keys, n, searchKeys[i]);

        printf("%s : BST = %d comparisons, "
               "Linear = %d comparisons\n",
               searchKeys[i], bst, linear);
    }

    return 0;
}