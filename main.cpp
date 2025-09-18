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
//		return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
		return sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));
	}
	void In(/*Diem p*/) {
		cout << "(" << x << "," << y << ")" << endl;
	}
	void Nhap(/*Diem p*/) {
		cin >> x >> y;
	}
};

#define PI 3.1415
struct VongTron {
	float x, y, r;
	float DienTich(/*VongTron c*/) {
		return PI * r * r;
	}
	void Nhap() {

	}
	void Xuat() {

	}

	float khoang_cach_den(/*VongTron c1, */ VongTron c2) {
		return sqrt((x-c2.x)* (x - c2.x) + (y - c2.y) * (y - c2.y));
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
		p[i].Nhap();
	}

	cout << "Nhap diem c ";
	c.Nhap();

	float s = 0;
	int min_i = 0;

	float min_d = p[0].khoang_cach_den(c);

	for (int i = 1; i < n; i++) {
		float d = p[i].khoang_cach_den(c);
		s += d;
		if (d < min_d) {
			min_d = d;
			min_i = i;
		}
	}

	cout << "Tong khoang cach: " << s << endl;
	cout << "Diem co khoang cach gan nhat: "; 
	p[min_i].In();
}
#define MAX_FLOAT 9999999999

void week02() {
	VongTron c[100];
	int n;
	cout << "Nhap so vong tron: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Nhap vong tron " << i << ": ";
		c[i].Nhap();
	}

	float s = 0;
	int min_i = -1;
	int min_j = -1;

	float min_d = MAX_FLOAT;

	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			float d = c[i].khoang_cach_den(c[j]);
			if ((d < min_d) && (d > c[i].r + c[j].r)) {
				min_d = d;
				min_i = i;
				min_j = j;
			}
		}
	}

	if (min_i>=0 && min_j>=0) {
		cout << "2 vong tron thoa dieu kien la: ";
		c[min_i].Xuat();
		c[min_j].Xuat();
	}
	else
	{
		cout << "Khong tim thay 2 vong trong thoa dieu kien" << endl;
	}
}

int main(int) {
	week02();
	return 1;
}