#include <bits/stdc++.h>
using namespace std;

struct Nut
{ int Info;
    Nut *Left, *Right;
    };
    Nut *T;
    
// 1. Tìm chiều cao của cây T.
int TinhChieuCao(Nut *T) {
    if (T == NULL) {
        return -1; // Cây rỗng có chiều cao -1
    }
    int leftHeight = TinhChieuCao(T->Left);
    int rightHeight = TinhChieuCao(T->Right);
    return max(leftHeight, rightHeight) + 1; // Chiều cao của cây là chiều cao lớn nhất của hai cây con cộng 1
}

// 2. Bổ sung một nút lá có giá trị trường Info bằng X vào cây T là cây nhị phân tìm kiếm theo trường khóa Info.
Nut* ThemNutLa(Nut *T, int X) {
    if (T == NULL) {
        Nut *newNode = new Nut;
        newNode->Info = X;
        newNode->Left = newNode->Right = NULL;
        return newNode; // Trả về nút mới nếu cây rỗng
    }
    if (X < T->Info) {
        T->Left = ThemNutLa(T->Left, X); // Chèn vào cây con trái
    } else if (X > T->Info) {
        T->Right = ThemNutLa(T->Right, X); // Chèn vào cây con phải
    }
    return T; // Trả về cây gốc
}

// 3. Xoá tất cả các nút của cây T (giải phóng toàn bộ vùng nhớ của tất cả các nút để biến cây T thành cây rỗng).
void XoaToanBoNut(Nut *&T) {
    if (T == NULL) {
        return; // Cây rỗng
    }
    XoaToanBoNut(T->Left);  // Xoá cây con trái
    XoaToanBoNut(T->Right); // Xoá cây con phải
    delete T;               // Giải phóng nút hiện tại
    T = NULL;               // Đặt T thành NULL để biến cây thành rỗng
}
/*
4. Tìm giá trị lớn nhất của trường Info của các nút thuộc cây T, với giả thiết rằng cây T có ít nhất là một nút (T khác NULL), trong 2 trường hợp sau:
a) Cây T là cây nhị phân tìm kiếm
b) Cây T không là cây nhị phân tìm kiếm.
*/
int TimGiaTriMax(Nut *T) {
    if (T == NULL) {
        return INT_MIN; // Trả về giá trị nhỏ nhất nếu cây rỗng
    }
    int maxLeft = TimGiaTriMax(T->Left);   // Tìm giá trị lớn nhất trong cây con trái
    int maxRight = TimGiaTriMax(T->Right); // Tìm giá trị lớn nhất trong cây con phải
    return max(T->Info, max(maxLeft, maxRight)); // Trả về giá trị lớn nhất giữa nút hiện tại và hai cây con
}


// 5. Tìm số nút nhánh trong cây T.
int SoNutNhang(Nut *T) {
    if (T == NULL) {
        return 0; // Cây rỗng không có nút nhánh
    }
    // Nút nhánh là nút có đúng một con
    if ((T->Left == NULL && T->Right != NULL) || (T->Left != NULL && T->Right == NULL)) {
        return 1 + SoNutNhang(T->Left) + SoNutNhang(T->Right); // Đếm nút nhánh và tiếp tục đếm trong hai cây con
    }
    return SoNutNhang(T->Left) + SoNutNhang(T->Right); // Không phải nút nhánh, tiếp tục đếm trong hai cây con
}
/*
6. 
a) Tìm địa chỉ nút cha của nút được trỏ bởi p thuộc cây T.
b) Từ đó tìm mức của nút được trỏ bởi p thuộc cây T.

7. Tìm địa chỉ của một nút thuộc cây T có giá trị trường Info bằng X (nếu có), hoặc trả về giá trị NULL nếu tìm không có, trong 2 trường hợp sau:
a) Cây T là cây nhị phân tìm kiếm
b) Cây T không là cây nhị phân tìm kiếm.
*/

// 8. In giá trị trường Info của các nút của cây T theo thứ tự giảm dần, biết rằng cây T là cây nhị phân tìm kiếm theo trường khóa Info.
void InGiamDan(Nut *T) {
    if (T == NULL) {
        return; // Cây rỗng
    }
    InGiamDan(T->Right); // In cây con phải trước
    cout << T->Info << " "; // In giá trị của nút hiện tại
    InGiamDan(T->Left); // In cây con trái sau
}

// 9. Tạo ra một cây mới L (nút gốc trỏ bởi L) có dữ liệu trường Info lần lượt được sao chép từ cây T.
Nut* SaoChepCay(Nut *T) {
    if (T == NULL) {
        return NULL; // Cây rỗng
    }
    Nut *newNode = new Nut; // Tạo nút mới
    newNode->Info = T->Info; // Sao chép giá trị Info
    newNode->Left = SaoChepCay(T->Left); // Sao chép cây con trái
    newNode->Right = SaoChepCay(T->Right); // Sao chép cây con phải
    return newNode; // Trả về nút mới
}

// 10. Kiểm tra một cây T bất kỳ có phải là cây nhị phân tìm kiếm hay không.
bool KiemTraCayNhiPhanTimKiem(Nut *T) {
    static Nut *prev = NULL; // Biến tĩnh để lưu nút trước đó
    if (T == NULL) {
        return true; // Cây rỗng là cây nhị phân tìm kiếm
    }
    
    // Kiểm tra cây con trái
    if (!KiemTraCayNhiPhanTimKiem(T->Left)) {
        return false;
    }
    
    // Kiểm tra giá trị của nút hiện tại so với nút trước đó
    if (prev != NULL && T->Info <= prev->Info) {
        return false; // Không phải cây nhị phân tìm kiếm
    }
    prev = T; // Cập nhật nút trước đó
    // Kiểm tra cây con phải
    return KiemTraCayNhiPhanTimKiem(T->Right);
}

// 11. Tìm cấp của cây T. Lưu ý rằng, cây T có cấp là 0 nếu cây T là cây rỗng hoặc cây có một nút.
int TinhCapCay(Nut *T) {
    if (T == NULL) {
        return 0; // Cây rỗng có cấp là 0
    }
    int leftDepth = TinhCapCay(T->Left);   // Tính cấp của cây con trái
    int rightDepth = TinhCapCay(T->Right); // Tính cấp của cây con phải
    return max(leftDepth, rightDepth) + 1; // Cấp của cây là cấp lớn nhất của hai cây con cộng 1
}

/*
12. a) Thay thế giá trị trường Info của mỗi nút trên cây T bằng mức của nút đó trên cây T.
b) Từ đó tìm số nút trên cây T có mức là x.

13. a) Tạo mới một danh sách liên kết đơn có nút đầu trỏ bởi F (được khai báo như trong nội dung của Bài tập 3) bằng cách sao chép giá trị trường Info của tất cả các nút thuộc cây T vào danh sách F.
b) Sắp xếp giá trị trường Info của các nút thuộc danh sách F theo thứ tự tăng dần.
c) Thay đổi giá trị trường Info của các nút trong cây T để nhận được một cây nhị phân tìm kiếm.

14. Cây T được gọi là một “đống” nếu giá trị trường Info của nút cha lớn hơn của nút con.
a) Kiểm tra cây T có phải là một đống hay không.
b) Tráo đổi giá trị trường Info của các nút trong cây T để biến cây T thành một đống.
*/