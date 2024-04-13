//#pragma once

//#include <iostream>
//#include <string>
//
//// Khai b�o c?u tr�c M�n H?c
//struct MonHoc {
//    std::string MAMH; // M� m�n h?c
//    std::string TENMH; // T�n m�n h?c
//    int STCLT; // S? t�n ch? l� thuy?t
//    int STCTH; // S? t�n ch? th?c h�nh
//};
//
//// Khai b�o c?u tr�c Node cho c�y nh? ph�n t�m ki?m c�n b?ng
//struct Node {
//    MonHoc data; // D? li?u m�n h?c
//    Node* left; // Con tr�i
//    Node* right; // Con ph?i
//    int height; // Chi?u cao c?a node
//};
//
//// H�m kh?i t?o m?t node m?i
//Node* newNode(MonHoc monHoc) {
//    Node* node = new Node();
//    node->data = monHoc;
//    node->left = nullptr;
//    node->right = nullptr;
//    node->height = 1; // M?c d?nh khi node m?i du?c th�m v�o c�y, chi?u cao l� 1
//    return node;
//}
//
//// Th�m c�c h�m kh�c d? qu?n l� c�y nh? ph�n t�m ki?m c�n b?ng nhu: insert, delete, rotateLeft, rotateRight, ...
//
//
//void inOrder(Node* root) {
//    if (root != nullptr) {
//        inOrder(root->left); // Duy?t c�y con tr�i
//        std::cout << root->data.MAMH << " - " << root->data.TENMH << " - "
//                  << root->data.STCLT << " - " << root->data.STCTH << std::endl; // X? l� n�t hi?n t?i
//        inOrder(root->right); // Duy?t c�y con ph?i
//    }
//}
//
//// H�m l?y chi?u cao c?a n�t
//int height(Node* N) {
//    if (N == nullptr)
//        return 0;
//    return N->height;
//}
//
//// H�m l?y h? s? c�n b?ng c?a n�t N
//int getBalance(Node* N) {
//    if (N == nullptr)
//        return 0;
//    return height(N->left) - height(N->right);
//}
//
//// C�c h�m quay c�y d? c�n b?ng
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
//    // Tr? v? n�t m?i
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
//    // Tr? v? n�t m?i
//    return y;
//}
//
//// H�m ch�n n�t m?i v� c�n b?ng c�y
//Node* insert(Node* node, MonHoc key) {
//    // Bu?c 1: Th?c hi?n ch�n nhu BST th�ng thu?ng
//    if (node == nullptr)
//        return(newNode(key));
//
//    if (key.MAMH < node->data.MAMH)
//        node->left = insert(node->left, key);
//    else if (key.MAMH > node->data.MAMH)
//        node->right = insert(node->right, key);
//    else // Kh�ng cho ph�p tr�ng l?p MAMH
//        return node;
//
//    // Bu?c 2: C?p nh?t chi?u cao c?a n�t cha
//    node->height = 1 + std::max(height(node->left), height(node->right));
//
//    // Bu?c 3: L?y h? s? c�n b?ng d? ki?m tra n�t cha c� b? m?t c�n b?ng kh�ng
//    int balance = getBalance(node);
//
//    // N?u n�t n�y b? m?t c�n b?ng, th� c� 4 tru?ng h?p
//
//    // Tru?ng h?p tr�i-tr�i
//    if (balance > 1 && key.MAMH < node->left->data.MAMH)
//        return rightRotate(node);
//
//    // Tru?ng h?p ph?i-ph?i
//    if (balance < -1 && key.MAMH > node->right->data.MAMH)
//        return leftRotate(node);
//
//    // Tru?ng h?p tr�i-ph?i
//    if (balance > 1 && key.MAMH > node->left->data.MAMH) {
//        node->left = leftRotate(node->left);
//        return rightRotate(node);
//    }
//
//    // Tru?ng h?p ph?i-tr�i
//    if (balance < -1 && key.MAMH < node->right->data.MAMH) {
//        node->right = rightRotate(node->right);
//        return leftRotate(node);
//    }
//
//    // Tr? v? n�t kh�ng thay d?i
//    return node;
//}
//
//int main() {
//    // V� d? kh?i t?o v� th�m m�n h?c v�o c�y
//    MonHoc mh1 = {"CSC101", "C?u tr�c d? li?u", 3, 2};
//    Node* root = newNode(mh1);
//    
//    // Th�m c�c m�n h?c kh�c v�o c�y t?i d�y
//
//    return 0;
//}

