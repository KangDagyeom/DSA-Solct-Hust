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
void DynamicProgramming(){
	int ei = a[0];
	int si = a[0];
	for(int i = 1;i <= n-1;i++){
		ei = max(a[i],a[i]+ei);
		si = max(si,ei);
	}
	cout<<"Phuong phap quy hoach dong: Trong luong day con lon nhat = "<<si<<endl;
}
int main() {
	DuyetToanBoCoCaiTien();
	Recursion();
	DynamicProgramming();
	return 0;
}
//Ket luan
/*
| Thuật toán               | Độ phức tạp | n=10⁴  | Thời gian     | n=10⁵  | Thời gian     |
|--------------------------|-------------|--------|---------------|--------|---------------|
| Duyệt toàn bộ            | n³          | 10¹²   | 2.7 giờ       | 10¹⁸   | 115 ngày      |
| Duyệt toàn bộ có cải tiến| n²          | 10⁸    | 1 giây        | 10¹²   | 2.7 giờ       |
| Đệ quy (Recursive)       | n log n     | 1.33*10⁵ | 10³ giây    | 1.99*10⁷ | 2*10^-1 giây  |
| Quy hoạch động (Dynamic programming) | n | 10⁴    | 10⁴ giây    | 10^6    | 2*10^-2 giây    |
*/
