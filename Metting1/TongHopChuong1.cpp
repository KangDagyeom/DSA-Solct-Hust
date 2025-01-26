#include <iostream>
#include <climits>
using namespace std;

int a[] = {-2, 11, -4, 13, -5, 2};
int n = sizeof(a) / sizeof(a[0]);

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
//Chia de tri + de quy
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

int main() {
	DuyetToanBoCoCaiTien();
	Recursion();
	return 0;
}
