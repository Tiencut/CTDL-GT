#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node
typedef struct node NODE;

struct node {
    int key;
    node *left;
    node *right;
};

NODE *createNode(int x) {
    NODE *n = ;
    n->key = x;
    n->left = n->right = nullptr;
    return n;
}

int main() {
    NODE *root = nullptr;

}