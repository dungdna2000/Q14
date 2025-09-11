#include <iostream>

using namespace std;

struct Diem {
	float x;
	float y;

	float khoang_cach_den_tam(/*Diem p*/) {
		//return sqrt(p.x * p.x + p.y * p.y);
		return sqrt(x * x + y * y);
	}
	float khoang_cach_den(/*Diem p1,*/ Diem p2) {
		return sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));
	}

};


void week01() {

#define MAX 10
	Diem p[MAX];
	Diem c;

	int n; 
	cout << "Nhap so diem: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Nhap diem thu " << i << ": ";
		cin >> p[i].x >> p[i].y;
	}

	cout << "Nhap diem c ";
	cin >> c.x >> c.y;


	float s = 0;
	int min_i = 0;

//	float min_d = khoang_cach_den_tam(p[0]);
//	float min_d = p[0].khoang_cach_den_tam();

//	float min_d = khoang_cach(p[0],c);
	float min_d = p[0].khoang_cach_den(c);

	for (int i = 1; i < n; i++) {
//		float d = p[i].khoang_cach_den_tam();
//		float d = khoang_cach(p[i], c);
		float d = p[i].khoang_cach_den(c);

		s += d;

		if (d < min_d) {
			min_d = d;
			min_i = i;
		}
	}

	cout << "Tong khoang cach: " << s << endl;
	cout << "Diem (" << p[min_i].x << "," << p[min_i].y << ") co khoang cach gan nhat" << endl;
}

int main(int) {
	week01();
	return 1;
}