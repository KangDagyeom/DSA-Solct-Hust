#include <iostream>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

const int n = 100000; // Ð?t kích thu?c m?ng a là 10^4
int a[n];

// T?o m?ng a[] v?i giá tr? ng?u nhiên t? -100 d?n 100
void generateArray() {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 201 - 100;  // Sinh s? ng?u nhiên t? -100 d?n 100
    }
}

void DuyetToanBoCoCaiTien() {
    int maxSum = a[0];
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    cout << "Duyet toan bo co cai tien: Trong luong day con lon nhat = " << maxSum << endl;
}

// Chia de tri + de quy
int maxLeft(int a[], int low, int mid) {
    if (mid < low) return 0;
    int sum = 0;
    int maxSum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum += a[i];
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    return maxSum;
}

int maxRight(int a[], int mid, int high) {
    if (mid + 1 > high) return 0;
    int sum = 0;
    int maxSum = INT_MIN;
    for (int i = mid + 1; i <= high; i++) {
        sum += a[i];
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    return maxSum;
}

int maxSub(int a[], int low, int high) {
    if (low == high) return a[high];
    else {
        int mid = (low + high) / 2;
        int WL = maxSub(a, low, mid);
        int WR = maxSub(a, mid + 1, high);
        int WM = maxLeft(a, low, mid) + maxRight(a, mid, high);
        return max(WL, max(WR, WM));
    }
}

void Recursion() {
    int maxSum = maxSub(a, 0, n - 1);
    cout << "De quy: Trong luong day con lon nhat = " << maxSum << endl;
}

void DynamicProgramming() {
    int ei = a[0];
    int si = a[0];
    for (int i = 1; i < n; i++) {
        ei = max(a[i], a[i] + ei);
        si = max(si, ei);
    }
    cout << "Phuong phap quy hoach dong: Trong luong day con lon nhat = " << si << endl;
}

int main() {
    // T?o m?ng a[] ng?u nhiên
    generateArray();
    
    // Ðo th?i gian cho DuyetToanBoCoCaiTien
    clock_t startTime = clock();
    DuyetToanBoCoCaiTien();
    clock_t endTime = clock();
    cout << "Thoi gian thuc hien duyet toan bo = " << (double)(endTime - startTime) / (double)CLOCKS_PER_SEC << " giay" << endl;
    
    // Ðo th?i gian cho Recursion
    startTime = clock();
    Recursion();
    endTime = clock();
    cout << "Thoi gian thuc hien de quy = " << (double)(endTime - startTime) / (double)CLOCKS_PER_SEC << " giay" << endl;
    
    // Ðo th?i gian cho DynamicProgramming
    startTime = clock();
    DynamicProgramming();
    endTime = clock();
    cout << "Thoi gian thuc hien quy hoach dong = " << (double)(endTime - startTime) / (double)CLOCKS_PER_SEC << " giay" << endl;
    
    return 0;
}
