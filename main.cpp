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
	Diem tam; 
	float r;
	float DienTich(/*VongTron c*/) {
		return PI * r * r;
	}
	void Nhap() {
		cout << "Tam: "; tam.Nhap();
		cout << "Ban kinh: "; cin >> r;
	}
	void Xuat() {

	}

	float khoang_cach_den(/*VongTron c1, */ VongTron c2) {
		return tam.khoang_cach_den(c2.tam);
	}

	bool chua(/*VongTron c,*/Diem p) {
		return tam.khoang_cach_den(p) <= r;
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

	Diem p[100];

	int m;
	cout << "Nhap so diem: ";
	cin >> m;

	for (int i = 0; i < m; i++) {
		cout << "Nhap diem thu " << i << ": ";
		p[i].Nhap();
	}

	int max_s = -1;

	for (int i = 0; i < n; i++) { // i = vong tron
		int s = 0;
		for (int j = 0; j < m; j++) {  // j = diem
			if (c[i].chua(p[j])) s++;
		}

		if (s>max_s) {
			?
		}
	}

}

int main(int) {
	week02();
	return 1;
}