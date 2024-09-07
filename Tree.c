// tree.h
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

// tree.c
#include "tree.h"
#include <stdlib.h>

// Create a new node
Node* create_node(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Create a new tree
Tree* create_tree() {
    Tree* tree = (Tree*) malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

// Insert a node into the tree
void insert_node(Tree* tree, int value) {
    Node* node = create_node(value);
    if (tree->root == NULL) {
        tree->root = node;
    } else {
        // Recursively find the correct position for the new node
        insert_node_recursive(tree->root, node);
    }
}

// Recursive helper function for inserting a node
void insert_node_recursive(Node* current, Node* new_node) {
    if (new_node->value < current->value) {
        if (current->left == NULL) {
            current->left = new_node;
        } else {
            insert_node_recursive(current->left, new_node);
        }
    } else {
        if (current->right == NULL) {
            current->right = new_node;
        } else {
            insert_node_recursive(current->right, new_node);
        }
    }
}

// Print the tree in-order (left-root-right)
void print_tree(Tree* tree) {
    print_tree_recursive(tree->root);
}

// Recursive helper function for printing the tree
void print_tree_recursive(Node* current) {
    if (current != NULL) {
        print_tree_recursive(current->left);
        printf("%d ", current->value);
        print_tree_recursive(current->right);
    }
}

int main() {
    Tree* tree = create_tree();

    insert_node(tree, 5);
    insert_node(tree, 2);
    insert_node(tree, 8);
    insert_node(tree, 3);
    insert_node(tree, 9);

    printf("Tree: ");
    print_tree(tree);
    printf("\n");

    return 0;
}