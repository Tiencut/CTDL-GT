#include <bits/stdc++.h>
using namespace std;

// bubble sort (nổi bọt)
void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// selection sort (chọn lọc)
// giải thích hoạt động:
// 1. Tìm phần tử nhỏ nhất trong mảng chưa được sắp xếp.
// 2. Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên của mảng chưa được sắp xếp.
// 3. Lặp lại quá trình cho đến khi mảng được sắp xếp hoàn toàn.
void SelectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

// insertion sort (chèn)
//// giải thích hoạt động:
// 1. Chia mảng thành hai phần: phần đã sắp xếp và phần chưa sắp xếp.
// 2. Lấy phần tử đầu tiên của phần chưa sắp xếp và chèn nó vào đúng vị trí trong phần đã sắp xếp.
void InsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// merge sort (trộn)
// giải thích hoạt động:
// 1. Chia mảng thành hai nửa cho đến khi mỗi nửa chỉ còn một phần tử.
// 2. Kết hợp các nửa đã sắp xếp lại với nhau để tạo thành mảng đã sắp xếp hoàn chỉnh.
void MergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(a, left, mid);
        MergeSort(a, mid + 1, right);
        
        // Merge the sorted halves
        int temp[right - left + 1]; 
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (a[i] <= a[j]) {
                temp[k++] = a[i++];
            } else {
                temp[k++] = a[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = a[i++];
        }
        while (j <= right) {
            temp[k++] = a[j++];
        }
        for (i = left, k = 0; i <= right; i++, k++) {
            a[i] = temp[k];
        }
    }
}

// quick sort (phân hoạch)
// giải thích hoạt động:
// 1. Chọn một phần tử làm "pivot" (trục).
// 2. Chia mảng thành hai phần: phần nhỏ hơn hoặc bằng pivot và phần lớn hơn pivot.
// 3. Đệ quy sắp xếp hai phần này.
void QuickSort(int a[], int left, int right) {
    if (left < right) {
        int pivot = a[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (a[j] <= pivot) {
                i++;
                swap(a[i], a[j]);
            }
        }
        swap(a[i + 1], a[right]);
        int partitionIndex = i + 1;

        QuickSort(a, left, partitionIndex - 1);
        QuickSort(a, partitionIndex + 1, right);
    }
}

// heap sort (đống)
// giải thích hoạt động:
// 1. Xây dựng một heap từ mảng.
// 2. Lấy phần tử lớn nhất (đối với heap max) và đổi chỗ nó với phần tử cuối cùng của mảng.
void Heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        Heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        Heapify(a, i, 0);
    }
}

// counting sort (đếm)


// radix sort (cơ số)

// bucket sort (xô)

