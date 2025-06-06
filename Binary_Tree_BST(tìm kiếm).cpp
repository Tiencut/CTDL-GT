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

// đếm số nút
int SoNut(Nut *T) {
    if (T == nullptr) {
        return 0;
    }
    return 1 + SoNut(T->Left) + SoNut(T->Right);
}

// đếm số lá
int SoNutLa(Nut *T) {
    if (T == nullptr) {
        return 0;
    }
    if (T->Left == nullptr && T->Right == nullptr) {
        return 1;
    }
    return SoNutLa(T->Left) + SoNutLa(T->Right);
}

// T khác rỗng, return giá trị nhỏ nhất
int minValue(Nut *T) {
    Nut *current = T;
    while (current->Left != nullptr) {
        current = current->Left;
    }
    return current->Info;
}

// T khác rỗng, return giá trị lớn nhất
int maxValue(Nut *T) {
    Nut *current = T;
    while (current->Right != nullptr) {
        current = current->Right;
    }
    return current->Info;
}

// Duyệt cây
void preOrder(Nut *T) {
    if(T != nullptr) {
        cout << T->Info << " ";
        preOrder(T->Left);
        preOrder(T->Right);
    }
}

// Duyệt cây theo thứ tự 
void inOrder(Nut *T) {
    if(T != nullptr) {
        inOrder(T->Left);
        cout << T->Info << " ";
        inOrder(T->Right);
    }
}

// Duyệt cây theo thứ tự ngược
void postOrder(Nut *T) {
    if(T != nullptr) {
        postOrder(T->Left);
        postOrder(T->Right);
        cout << T->Info << " ";
    }
}


// tìm kiếm theo đệ quy
NUT *searchNodeRecursive(Nut *T, int x) {
    if(T == nullptr) {
        return nullptr;
    }
    if(T->Info == x) {
        return T;
    }
    if(x < T->Info) {
        return searchNodeRecursive(T->Left, x);
    } else {
        return searchNodeRecursive(T->Right, x);
    }
}

// tìm kiếm theo vòng lặp
Nut *searchNodeVongLap(Nut *T, int x) {
    Nut *p = T;
    while (p != nullptr) {
        if(p->Info == x)
            return p;
        else if(x < p->Info)
            p = p->Left;
        else
            p = p->Right;
    }
    return nullptr;
}

// insert
Nut *insertNodeRecursive(Nut *T, int x) {
    if(T == nullptr)
        return createNode(x);
    else if (x < T->Info)
        T->Left = insertNodeRecursive(T->Left, x);
    else if (x > T->Info)
        T->Right = insertNodeRecursive(T->Right, x);
    return T;
}

Nut *insertNodeIterative(Nut *T, int x) {
    if (T == nullptr)
        return createNode(x);

    Nut *tmp = T;
    Nut *parent = nullptr;

    while(tmp != nullptr) {
        parent = tmp;
        if(x < tmp->Info)
            tmp = tmp->Left;
        else if (x > tmp->Info)
            tmp = tmp->Right;
        else
            return T;
    }

    if (x > parent->Info)
        parent->Right = createNode(x);
    else
        parent->Left = createNode(x);

    return T;
}


// xóa
Nut* deleteNode(Nut* T, int key) {
    if (T == nullptr) {
        return T;
    }

    if (key < T->Info) {
        T->Left = deleteNode(T->Left, key);
    } else if (key > T->Info) {
        T->Right = deleteNode(T->Right, key);
    } else {
        if (T->Left == nullptr && T->Right == nullptr) {
            delete T;
            return nullptr;
        }

        if (T->Left == nullptr) {
            Nut* temp = T->Right;
            delete T;
            return temp;
        } else if (T->Right == nullptr) {
            Nut* temp = T->Left;
            delete T;
            return temp;
        }

        Nut* temp = T->Right;
        while (temp->Left != nullptr) {
            temp = temp->Left;
        }

        T->Info = temp->Info;
        T->Right = deleteNode(T->Right, temp->Info);
    }

    return T;
}
