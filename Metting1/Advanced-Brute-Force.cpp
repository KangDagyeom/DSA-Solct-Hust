#include <iostream>
using namespace std;
int main() {
	int a [] = {1,2,3,4};
	int n = sizeof(a) / sizeof(a[0]);
	int maxSum  = a[0];
	for(int i = 0; i<n; i++) {
		int sum = 0;
		for(int j = i; j<n; j++) {
			sum += a[j];
			if(sum > maxSum) {
				maxSum = sum;
			}
		}
	}
	cout<<"Trong luong day con lon nhat la: "<<maxSum<<endl;
	return 0;
}


