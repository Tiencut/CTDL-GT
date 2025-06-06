#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node
typedef struct Nut NUT;

struct Nut {
    int Info;
    Nut *Left, *Right;
};
Nut *T;

NUT *createNode(int x) {
    NUT *n = new Nut;
    n->Info = x;
    n->Left = n->Right = nullptr;
    return n;
}

// Đếm số nút
int SoNut(Nut *T) {
    if (T == nullptr) {
        return 0;
    }
    return 1 + SoNut(T->Left) + SoNut(T->Right);
}

// Đếm số lá
int SoLa(Nut *T) {
    if (T == nullptr) {
        return 0;
    }
    if (T->Left == nullptr && T->Right == nullptr) {
        return 1; // Nút lá
    }
    return SoLa(T->Left) + SoLa(T->Right);
}

// T khác rỗng, giá trị Info nhỏ nhất trong cây
int minInFo(Nut *T) {
    if (T == NULL) return INT_MAX; // hoặc 1 giá trị lớn tùy đề
    int minLeft = minInFo(T->Left);
    int minRight = minInFo(T->Right);
    int minVal = T->Info;
    if (minLeft < minVal) minVal = minLeft;
    if (minRight < minVal) minVal = minRight;
    return minVal;
}


// Duyệt cây
void preOrder(Nut *T) {
    if(T != nullptr) {
        cout << T->Info << " ";
        preOrder(T->Left);
        preOrder(T->Right);
    }
}

void inOrder(Nut *T) {
    if(T != nullptr) {
        inOrder(T->Left);
        cout << T->Info << " ";
        inOrder(T->Right);
    }
}

void postOrder(Nut *T) {
    if(T != nullptr) {
        postOrder(T->Left);
        postOrder(T->Right);
        cout << T->Info << " ";
    }
}

// Thêm node vào cây nhị phân tổng quát (thêm vào vị trí đầu tiên còn trống theo thứ tự từ trái sang phải)
void insertNode(Nut* &T, int x) {
    if (T == nullptr) {
        T = createNode(x);
        return;
    }
    queue<Nut*> q;
    q.push(T);
    while (!q.empty()) {
        Nut* temp = q.front();
        q.pop();
        if (temp->Left == nullptr) {
            temp->Left = createNode(x);
            return;
        } else {
            q.push(temp->Left);
        }
        if (temp->Right == nullptr) {
            temp->Right = createNode(x);
            return;
        } else {
            q.push(temp->Right);
        }
    }
}

// Tìm kiếm node theo giá trị (duyệt toàn bộ cây)
Nut* searchNode(Nut* T, int x) {
    if (T == nullptr) return nullptr;
    if (T->Info == x) return T;
    Nut* left = searchNode(T->Left, x);
    if (left != nullptr) return left;
    return searchNode(T->Right, x);
}

// Xóa node theo giá trị (xóa node đầu tiên tìm thấy theo thứ tự duyệt mức)
void deleteNode(Nut* &T, int key) {
    if (T == nullptr) return;
    if (T->Left == nullptr && T->Right == nullptr) {
        if (T->Info == key) {
            delete T;
            T = nullptr;
        }
        return;
    }
    queue<Nut*> q;
    q.push(T);
    Nut* keyNode = nullptr;
    Nut* temp;
    Nut* last;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->Info == key) keyNode = temp;
        if (temp->Left) {
            q.push(temp->Left);
        }
        if (temp->Right) {
            q.push(temp->Right);
        }
        last = temp;
    }
    if (keyNode != nullptr) {
        keyNode->Info = last->Info;
        // Xóa last node
        queue<Nut*> q2;
        q2.push(T);
        while (!q2.empty()) {
            Nut* t = q2.front();
            q2.pop();
            if (t->Left) {
                if (t->Left == last) {
                    delete t->Left;
                    t->Left = nullptr;
                    return;
                } else {
                    q2.push(t->Left);
                }
            }
            if (t->Right) {
                if (t->Right == last) {
                    delete t->Right;
                    t->Right = nullptr;
                    return;
                } else {
                    q2.push(t->Right);
                }
            }
        }
    }
}
