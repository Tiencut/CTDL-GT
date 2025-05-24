#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node
typedef struct Node NODE;

struct Node {
    int key;
    Node *left;
    Node *right;
};

NODE *createNode(int x) {
    NODE *n = new Node;
    n->key = x;
    n->left = n->right = nullptr;
    return n;
}

// tìm kiếm theo đệ quy
NODE *searchNodeRecursive(Node *root, int x) {
    if(root == nullptr) {
        return nullptr;
    }
    if(root->key == x) {
        return root;
    }
    if(x < root->key) {
        return searchNodeRecursive(root->left, x);
    } else {
        return searchNodeRecursive(root->right, x);
    }
}

// tìm kiếm theo vòng lặp
Node *searchNodeVongLap(Node *root, int x) {
    Node *p = root;
    while (p != nullptr) {
        if(p->key == x) 
            return p;
        else if(x < p->key)
            p = p->left;
        else
            p = p->right;

    }
    return nullptr;
}

// insert
Node *insertNodeRecursive(Node *root, int x) {
    if(root == nullptr)
        return createNode(x);
    else if (x < root->key)
        return insertNodeRecursive(root->left, x);
    else if (x > root->key)
        return insertNodeRecursive(root->right, x);
    else
        return root; // không chèn node trùng    
}

Node *insertNodeIterative(Node *root, int x) {
    if (root == nullptr)
        return createNode(x);
    
    Node *tmp = root;
    Node *parent = nullptr;
    
    while(tmp != nullptr) {
        parent = tmp;
        if(x < tmp->key)
            tmp = tmp->left;
        else if (x > tmp->key)
            tmp = tmp->right;
        else
            // Nếu giá trị đã tồn tại, không chèn thêm
            return root;
    }
    
    if (x > parent->key)
        parent->right = createNode(x);
    else 
        parent->left = createNode(x);
        
    return root;
}

// Duyệt cây
// duyệt Node - left - right là duyệt trước
void preOrder(Node *root) {
    if(root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// duyệt left - Node - right là duyệt giữa
void inOrder(Node *root) {
    if(root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// duyệt left - right - Node là duyệt sau
void postOrder(Node *root) {
    if(root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

// xóa
    // Node cần xóa là Node lá (không có con)
    // Node cần xóa có 1 con
    // Node cần xóa có 2 con
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root; // Cây rỗng
    }

    // Tìm nút cần xóa
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Trường hợp 1: Nút không có con
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Trường hợp 2: Nút có 1 con
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Trường hợp 3: Nút có 2 con
        // Tìm giá trị nhỏ nhất ở cây con bên phải (Inorder Successor)
        Node* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }

        // Thay thế giá trị của nút cần xóa bằng giá trị của Inorder Successor
        root->key = temp->key;

        // Xóa Inorder Successor
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}




int main() {
    NODE *root = nullptr;

}