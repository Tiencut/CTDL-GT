#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int Info;
    Node *Next; 
};
Node *F;

// DUYỆT
// 1. Tìm số nút trong danh sách F có giá trị trường Info bé hơn một số nguyên X cho trước.
int CountLessThanX(int X)
{
    int count = 0;
    Node *current = F;
    while (current != NULL)
    {
        if (current->Info < X)
            count++;
        current = current->Next;
    }
    return count;
}

// ĐẾM SỐ NÚT
int CountNodes() {
    int count = 0;
    Node *current = F;
    while (current != NULL) {
        count++;
        current = current->Next;
    }
    return count;
}


// TÌM KIẾM
// 4. Tìm giá trị lớn nhất của trường Info của các nút thuộc danh sách F, với giả thiết rằng danh sách F có ít nhất là một nút (F khác NULL).
int FindMax()
{
    if (F == NULL)
        return INT_MIN; // Danh sách rỗng

    int maxVal = F->Info;
    Node *current = F->Next;

    while (current != NULL)
    {
        if (current->Info > maxVal)
            maxVal = current->Info;
        current = current->Next;
    }
    return maxVal;
}



// CHÈN
// 2. Chèn một nút có giá trị trường Info bằng X vào danh sách F đã được sắp xếp theo thứ tự tăng dần của trường Info.
void InsertSorted(int X)
{
    Node *newNode = new Node;
    newNode->Info = X;
    newNode->Next = NULL;

    // Trường hợp danh sách rỗng hoặc nút mới nhỏ hơn nút đầu
    if (F == NULL || F->Info > X)
    {
        newNode->Next = F;
        F = newNode;
        return;
    }

    // Tìm vị trí chèn
    Node *current = F;
    while (current->Next != NULL && current->Next->Info < X)
    {
        current = current->Next;
    }
    newNode->Next = current->Next;
    current->Next = newNode;
}



// CHÈN CUỐI
// 5. Bổ sung một nút mới có giá trị trường Info bằng X vào cuối danh sách F.
void AppendNode(int X)
{
    Node *newNode = new Node;
    newNode->Info = X;
    newNode->Next = NULL;

    // Trường hợp danh sách rỗng
    if (F == NULL)
    {
        F = newNode;
        return;
    }

    // Tìm nút cuối
    Node *current = F;
    while (current->Next != NULL)
    {
        current = current->Next;
    }
    current->Next = newNode; // Gắn nút mới vào cuối danh sách
}


// XÓA THEO GIÁ TRỊ
// 3. Xoá một nút có giá trị trường Info bằng X của danh sách F đã được sắp xếp theo thứ tự tăng của trường Info.
void DeleteNode(int X)
{
    if (F == NULL)
        return; // Danh sách rỗng

    // Trường hợp nút đầu cần xoá
    if (F->Info == X)
    {
        Node *temp = F;
        F = F->Next;
        delete temp;
        return;
    }

    // Tìm nút cần xoá
    Node *current = F;
    while (current->Next != NULL && current->Next->Info != X)
    {
        current = current->Next;
    }

    // Nếu tìm thấy nút cần xoá
    if (current->Next != NULL)
    {
        Node *temp = current->Next;
        current->Next = current->Next->Next;
        delete temp;
    }
}


// 6. Xoá nút cuối của danh sách F.
void DeleteLastNode()
{
    if (F == NULL)
        return; // Danh sách rỗng

    // Trường hợp chỉ có một nút
    if (F->Next == NULL)
    {
        delete F;
        F = NULL;
        return;
    }

    // Tìm nút trước nút cuối
    Node *current = F;
    while (current->Next->Next != NULL)
    {
        current = current->Next;
    }

    delete current->Next; // Xoá nút cuối
    current->Next = NULL; // Đặt Next của nút trước cuối là NULL
}

// XÓA HẾT
void DeleteAll() {
    Node *current = F;
    while (current != NULL) {
        Node *temp = current;
        current = current->Next;
        delete temp;
    }
    F = NULL; // Đặt danh sách về rỗng
}

/*
7. Tìm địa chỉ của một nút thuộc danh sách F có giá trị trường Info bằng X (nếu có), hoặc trả về giá trị NULL nếu tìm không có, trong 2 trường hợp sau:
a) Danh sách F không được sắp xếp
b) Danh sách F được sắp xếp theo thứ tự tăng dần của trường Info.
*/

// 8. In ngược (từ nút cuối đến nút đầu).
void PrintReverse(Node *node)
{
    if (node == NULL)
        return;                // Trường hợp danh sách rỗng
    PrintReverse(node->Next);  // Đệ quy để in từ cuối lên đầu
    cout << node->Info << " "; // In giá trị trường Info
}

// 9. Tạo ra một danh sách mới L (nút đầu trỏ bởi L) có dữ liệu trường Info lần lượt được sao chép từ danh sách F.
Node *CopyList()
{
    if (F == NULL)
        return NULL; // Trường hợp danh sách rỗng

    Node *L = new Node; // Tạo nút đầu tiên
    L->Info = F->Info;
    L->Next = NULL;

    Node *currentF = F->Next; // Bắt đầu từ nút tiếp theo của F
    Node *currentL = L;       // Dùng để xây dựng danh sách mới

    while (currentF != NULL)
    {
        Node *newNode = new Node; // Tạo nút mới
        newNode->Info = currentF->Info;
        newNode->Next = NULL;

        currentL->Next = newNode;  // Gắn nút mới vào cuối danh sách L
        currentL = newNode;        // Cập nhật currentL
        currentF = currentF->Next; // Tiến đến nút tiếp theo trong F
    }

    return L; // Trả về danh sách mới L
}

/*
10. Cho trước 2 danh sách F1 và F2 đã được sắp xếp theo thứ tự tăng của trường Info và lần lượt biểu diễn cho 2 tập hợp các số nguyên F1 và F2. Viết hàm nhằm tạo ra danh sách F3 để biểu diễn cho:
a) Hợp của 2 tập hợp F1 và F2. Ví dụ: Nếu F1={1,3,5} và F2={1,2,5} thì F3={1,2,3,5}.
b) Giao của 2 tập hợp F1 và F2. Ví dụ: Nếu F1={1,3,5} và F2={1,2,5} thì F3={1,5}.
*/