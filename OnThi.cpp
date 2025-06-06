#include <bits/stdc++.h>
using namespace std;

/*
Câu 1 (2 điểm)
Cho một dãy A gồm n số nguyên: A[0], A[1], ..., A[n-1]. 
Viết thuật toán in ra danh sách các phần tử ở bên phải của phần tử A[i] thuộc dãy A và có giá trị nhỏ hơn hoặc bằng A[i], với mọi i nguyên từ 0..n-1.

Vào: A[] = {12, 1, 2, 3, 0, 11, 1}
Ra: ds[] = {6, 2, 2, 2, 0, 1, 0}

Vào: A[] = {5, 4, 3, 2, 1}
Ra: ds[] = {4, 3, 2, 1, 0}
*/

/*
Giải thích đề bài:
- Đầu vào là một mảng A[] gồm n số nguyên.
- Đầu ra là một mảng ds[] gồm n số nguyên, trong đó ds[i] là số lượng các phần tử ở bên phải của A[i] thuộc dãy A và có giá trị <= A[i].
- Để giải quyết bài toán này, ta có thể sử dụng một stack để lưu trữ các chỉ số của các phần tử trong mảng A[].
- duyệt từ phải sang trái của mảng A[], với mỗi phần tử A[i], ta sẽ kiểm tra các phần tử trong stack:
  + Nếu phần tử trong stack lớn hơn A[i], ta sẽ pop nó ra khỏi stack.
  + Nếu phần tử trong stack nhỏ hơn hoặc bằng A[i], ta sẽ đếm số lượng các phần tử trong stack và lưu vào ds[i].
- Cuối cùng, ta sẽ in ra mảng ds[].
*/

void cau1(int A[], int n) {
    int ds[n];
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && A[s.top()] > A[i]) {
            s.pop();
        }
        ds[i] = s.size();
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << ds[i] << " ";
    }
    cout << endl;
}

/*
Câu 2 (3 điểm): dslk đơn
*/

typedef char St25[25]; 
typedef char St8[8];

struct NutM {
    int MaM;
    NutM *Tiep;
};

struct NutGV {
    St8 MaGV;
    St25 HoTenGV;
    NutGV *Down;
    NutM *DSM;
};
NutGV *FirstT;

// a) (1.5 đ) hàm Addr(NutGV *FirstT, St8 BMaGV) return địa chỉ (mã giáo viên: BMaGV, NULL nếu không có)
NutGV *Addr(NutGV *FirstT, St8 BMaGV) {
    NutGV *p = FirstT;
    while (p != NULL) {
        if (strcmp(p->MaGV, BMaGV) == 0)
            return p;
        p = p->Down;
    }
    return NULL;
}

// b) (1.5 đ) hàm ListOfTeachers(NutGV *FirstT, int BMaM), show giáo viên dạy mã môn học: BMaM.
void ListOfTeachers(NutGV *FirstT, int BMaM) {
    NutGV *p = FirstT;
    while (p != NULL) {
        NutM *q = p->DSM;
        while (q != NULL) {
            if (q->MaM == BMaM) {
                cout << p->HoTenGV << endl;
            }
            q = q->Tiep;
        }
        p = p->Down;
    }
}

/*
Câu 3 (3 điểm)
Cho cây nhị phân T (nút gốc trỏ bởi T)
*/

struct Nut {
    int Info;           // trường Info lưu các số nguyên
    Nut *Left, *Right;  // trường Left và Right lưu địa chỉ cây con trái và cây con phải
};
Nut *T;

// a) (1.0 đ) Viết hàm SoNutLa(Nut *T) cho kết quả là số nút lá trong cây T.
int SoNutLa(Nut *T) {
    if (T == NULL) {
        return 0;
    }
    if (T->Left == NULL && T->Right == NULL) {
        return 1;
    }
    return SoNutLa(T->Left) + SoNutLa(T->Right);
}

/*
b) (2.0 đ) Cây T được gọi là một "đống" nếu cây T là rỗng, 
hoặc cây T chỉ có một nút, 
hoặc cây T có tính sau: Info của bất kỳ nút nào thuộc cây T đều >= giá trị trường Info nút cha và nút con phải của nó.
Viết hàm DieuChinh(Nut *T) nhằm cho phép tráo đổi giá trị trường Info của các nút trong cây T, nhưng không thay đổi cấu trúc cây, để nhận được một đống.
*/
void DieuChinh(Nut *T) {
    if (T == NULL) {
        return;
    }
    if (T->Left != NULL && T->Left->Info > T->Info) {
        swap(T->Info, T->Left->Info);
        DieuChinh(T->Left);
    }
    if (T->Right != NULL && T->Right->Info > T->Info) {
        swap(T->Info, T->Right->Info);
        DieuChinh(T->Right);
    }
}



/*
Câu 4 (2 điểm)
Cho dãy số nguyên gồm n phần tử a, a, ..., a[n-1].
*/

// a. (1.0 đ) Viết thuật toán sắp xếp nhanh (Quick Sort) để sắp xếp dãy số trên theo thứ tự tăng dần.
void QuickSort(int a[], int left, int right) {
    if (left < right) {
        int pivot = a[(left + right) / 2];
        int i = left, j = right;
        while (i <= j) {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            if (i <= j) {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }
        QuickSort(a, left, j);
        QuickSort(a, i, right);
    }
}

// b. (1.0 đ) Áp dụng thuật toán trên trình bày các bước thực hiện sắp xếp dãy sau: a={7, 12, 13, 6, 3, 9, 5, 10, 8}
/*
7 12 13 6 3 9 5 10 8
6 3 5 7 12 13 9 10 8
3 5 6 7 12 13 9 10 8
10 8 9 7 12 13 6 3 5
7 8 9 10 12 13 3 5 6
*/