#include <iostream>

using namespace std;

void week01() {

#define MAX 10
	
	float x[MAX];
	float y[MAX];

	int n; 
	cout << "Nhap so diem: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "x[" << i << "]: "; cin >> x[i];
		cout << "y[" << i << "]: "; cin >> y[i];
	}

	float s = 0;
	for (int i = 0; i < n; i++) {
		s += sqrt(x[i] * x[i] + y[i] * y[i]);
	}

	cout << "Tong khoang cach: " << s << endl;
}

int main(int) {
	week01();
	return 1;
}