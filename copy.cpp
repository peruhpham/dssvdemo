#include <iostream>
#include <string>
#include <algorithm> // For std::sort
using namespace std;

// Định nghĩa cấu trúc SinhVien
struct SinhVien {
    int id;
    string ten;
    int tuoi;
    float diem;
    SinhVien* left;
    SinhVien* right;
    int height;
};

// Tạo một đối tượng SinhVien mới
SinhVien* taoSinhVien(int id, string ten, int tuoi, float diem) {
    SinhVien* sv = new SinhVien();
    sv->id = id;
    sv->ten = ten;
    sv->tuoi = tuoi;---------------------------------------------------------
    sv->diem = diem;
    sv->left = nullptr;
    sv->right = nullptr;
    sv->height = 1;
    return sv;
}

// Lấy chiều cao của cây
int chieuCao(SinhVien* sv) {
    if (sv == nullptr)
        return 0;
    return sv->height;
}

// Lấy max của 2 số nguyên
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Xoay phải
SinhVien* xoayPhai(SinhVien* y) {
    SinhVien* x = y->left;
    SinhVien* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(chieuCao(y->left), chieuCao(y->right)) + 1;
    x->height = max(chieuCao(x->left), chieuCao(x->right)) + 1;

    return x;
}

// Xoay trái
SinhVien* xoayTrai(SinhVien* x) {
    SinhVien* y = x->right;
    SinhVien* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(chieuCao(x->left), chieuCao(x->right)) + 1;
    y->height = max(chieuCao(y->left), chieuCao(y->right)) + 1;

    return y;
}

// Lấy độ chênh lệch cân bằng
int getBalance(SinhVien* sv) {
    if (sv == nullptr)
        return 0;
    return chieuCao(sv->left) - chieuCao(sv->right);
}

// Thêm sinh viên mới vào cây
SinhVien* themSinhVien(SinhVien* sv, int id, string ten, int tuoi, float diem) {
    if (sv == nullptr)
        return taoSinhVien(id, ten, tuoi, diem);

    if (id < sv->id)
        sv->left = themSinhVien(sv->left, id, ten, tuoi, diem);
    else if (id > sv->id)
        sv->right = themSinhVien(sv->right, id, ten, tuoi, diem);
    else
        return sv;

    sv->height = 1 + max(chieuCao(sv->left), chieuCao(sv->right));

    int balance = getBalance(sv);

    // Cân bằng cây
    if (balance > 1 && id < sv->left->id)
        return xoayPhai(sv);

    if (balance < -1 && id > sv->right->id)
        return xoayTrai(sv);

    if (balance > 1 && id > sv->left->id) {
        sv->left = xoayTrai(sv->left);
        return xoayPhai(sv);
    }

    if (balance < -1 && id < sv->right->id) {
        sv->right = xoayPhai(sv->right);
        return xoayTrai(sv);
    }

    return sv;
}

// Duyệt cây AVL theo thứ tự trung tố và lưu thông tin vào mảng tạm thời
void duyetCayVaLuuThongTin(SinhVien* sv, SinhVien** danhSachTamThoi, int& currentIndex) {
    if (sv != nullptr) {
        duyetCayVaLuuThongTin(sv->left, danhSachTamThoi, currentIndex);
        danhSachTamThoi[currentIndex++] = sv;
        duyetCayVaLuuThongTin(sv->right, danhSachTamThoi, currentIndex);
    }
}

// So sánh tên của hai sinh viên để sử dụng trong hàm std::sort
bool soSanhTheoTen(const SinhVien* a, const SinhVien* b) {
    return a->ten < b->ten;
}

//----------------------------------------------------------------
// Hàm sắp xếp chọn
void sapXepChon(SinhVien** danhSach, int n, bool (*soSanh)(const SinhVien*, const SinhVien*)) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (soSanh(danhSach[j], danhSach[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(danhSach[i], danhSach[minIndex]);
        }
    }
}

//----------------------------------------------------------------
// In danh sách sinh viên đã được sắp xếp theo thứ tự tên
void inDanhSachTheoTen(SinhVien** danhSachTamThoi, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Ten: " << danhSachTamThoi[i]->ten << ", ID: " << danhSachTamThoi[i]->id << ", Tuoi: " << danhSachTamThoi[i]->tuoi << ", Diem: " << danhSachTamThoi[i]->diem << endl;
    }
}

int main() {
    SinhVien* root = nullptr;
    const int MAX_SINH_VIEN = 100; // Số lượng tối đa sinh viên
    SinhVien* danhSachTamThoi[MAX_SINH_VIEN]; // Mảng tạm thời chứa thông tin sinh viên
    int currentIndex = 0; // Chỉ số hiện tại trong mảng tạm thời
    
    // Thêm các sinh viên vào cây
    root = themSinhVien(root, 1003, "Bob", 22, 7.5);
    root = themSinhVien(root, 1002, "Alice", 21, 9.0);
    root = themSinhVien(root, 1001, "John", 20, 8.5);
    root = themSinhVien(root, 1004, "Emily", 19, 8.0);

    // Duyệt cây và lưu thông tin vào mảng tạm thời
    duyetCayVaLuuThongTin(root, danhSachTamThoi, currentIndex);

    // Sắp xếp danh sách tạm thời theo tên
    // sort(danhSachTamThoi, danhSachTamThoi + currentIndex, soSanhTheoTen);
    sapXepChon(danhSachTamThoi, currentIndex, soSanhTheoTen);

    // In danh sách sinh viên theo thứ tự tên
    cout << "Danh sach sinh vien theo thu tu ten:" << endl;
    inDanhSachTheoTen(danhSachTamThoi, currentIndex);

    return 0;
}
