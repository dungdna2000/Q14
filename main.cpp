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
	int min_i = 0;

	float min_d = sqrt(x[0] * x[0] + y[0] * y[0]);
	for (int i = 1; i < n; i++) {
		float d = sqrt(x[i] * x[i] + y[i] * y[i]);
		s += d;

		if (d < min_d) {
			min_d = d;
			min_i = i;
		}
	}

	cout << "Tong khoang cach: " << s << endl;
	cout << "Diem (" << x[min_i] << "," << y[min_i] << ") co khoang cach gan nhat" << endl;
}

int main(int) {
	week01();
	return 1;
}