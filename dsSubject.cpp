//#pragma once

//#include <iostream>
//#include <string>
//
//// Khai báo c?u trúc Môn H?c
//struct MonHoc {
//    std::string MAMH; // Mã môn h?c
//    std::string TENMH; // Tên môn h?c
//    int STCLT; // S? tín ch? lý thuy?t
//    int STCTH; // S? tín ch? th?c hành
//};
//
//// Khai báo c?u trúc Node cho cây nh? phân tìm ki?m cân b?ng
//struct Node {
//    MonHoc data; // D? li?u môn h?c
//    Node* left; // Con trái
//    Node* right; // Con ph?i
//    int height; // Chi?u cao c?a node
//};
//
//// Hàm kh?i t?o m?t node m?i
//Node* newNode(MonHoc monHoc) {
//    Node* node = new Node();
//    node->data = monHoc;
//    node->left = nullptr;
//    node->right = nullptr;
//    node->height = 1; // M?c d?nh khi node m?i du?c thêm vào cây, chi?u cao là 1
//    return node;
//}
//
//// Thêm các hàm khác d? qu?n lý cây nh? phân tìm ki?m cân b?ng nhu: insert, delete, rotateLeft, rotateRight, ...
//
//
//void inOrder(Node* root) {
//    if (root != nullptr) {
//        inOrder(root->left); // Duy?t cây con trái
//        std::cout << root->data.MAMH << " - " << root->data.TENMH << " - "
//                  << root->data.STCLT << " - " << root->data.STCTH << std::endl; // X? lý nút hi?n t?i
//        inOrder(root->right); // Duy?t cây con ph?i
//    }
//}
//
//// Hàm l?y chi?u cao c?a nút
//int height(Node* N) {
//    if (N == nullptr)
//        return 0;
//    return N->height;
//}
//
//// Hàm l?y h? s? cân b?ng c?a nút N
//int getBalance(Node* N) {
//    if (N == nullptr)
//        return 0;
//    return height(N->left) - height(N->right);
//}
//
//// Các hàm quay cây d? cân b?ng
//Node* rightRotate(Node* y) {
//    Node* x = y->left;
//    Node* T2 = x->right;
//
//    // Th?c hi?n quay
//    x->right = y;
//    y->left = T2;
//
//    // C?p nh?t chi?u cao
//    y->height = std::max(height(y->left), height(y->right)) + 1;
//    x->height = std::max(height(x->left), height(x->right)) + 1;
//
//    // Tr? v? nút m?i
//    return x;
//}
//
//Node* leftRotate(Node* x) {
//    Node* y = x->right;
//    Node* T2 = y->left;
//
//    // Th?c hi?n quay
//    y->left = x;
//    x->right = T2;
//
//    // C?p nh?t chi?u cao
//    x->height = std::max(height(x->left), height(x->right)) + 1;
//    y->height = std::max(height(y->left), height(y->right)) + 1;
//
//    // Tr? v? nút m?i
//    return y;
//}
//
//// Hàm chèn nút m?i và cân b?ng cây
//Node* insert(Node* node, MonHoc key) {
//    // Bu?c 1: Th?c hi?n chèn nhu BST thông thu?ng
//    if (node == nullptr)
//        return(newNode(key));
//
//    if (key.MAMH < node->data.MAMH)
//        node->left = insert(node->left, key);
//    else if (key.MAMH > node->data.MAMH)
//        node->right = insert(node->right, key);
//    else // Không cho phép trùng l?p MAMH
//        return node;
//
//    // Bu?c 2: C?p nh?t chi?u cao c?a nút cha
//    node->height = 1 + std::max(height(node->left), height(node->right));
//
//    // Bu?c 3: L?y h? s? cân b?ng d? ki?m tra nút cha có b? m?t cân b?ng không
//    int balance = getBalance(node);
//
//    // N?u nút này b? m?t cân b?ng, thì có 4 tru?ng h?p
//
//    // Tru?ng h?p trái-trái
//    if (balance > 1 && key.MAMH < node->left->data.MAMH)
//        return rightRotate(node);
//
//    // Tru?ng h?p ph?i-ph?i
//    if (balance < -1 && key.MAMH > node->right->data.MAMH)
//        return leftRotate(node);
//
//    // Tru?ng h?p trái-ph?i
//    if (balance > 1 && key.MAMH > node->left->data.MAMH) {
//        node->left = leftRotate(node->left);
//        return rightRotate(node);
//    }
//
//    // Tru?ng h?p ph?i-trái
//    if (balance < -1 && key.MAMH < node->right->data.MAMH) {
//        node->right = rightRotate(node->right);
//        return leftRotate(node);
//    }
//
//    // Tr? v? nút không thay d?i
//    return node;
//}
//
//int main() {
//    // Ví d? kh?i t?o và thêm môn h?c vào cây
//    MonHoc mh1 = {"CSC101", "C?u trúc d? li?u", 3, 2};
//    Node* root = newNode(mh1);
//    
//    // Thêm các môn h?c khác vào cây t?i dây
//
//    return 0;
//}

