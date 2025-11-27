#include <iostream>

using namespace std;

class Diem {
public: 
	float x;
	float y;

	Diem(float xx, float yy) {
		x = xx;
		y = yy;
	}

	Diem():Diem(0,0) {}

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
//class VongTron {
//private: 
//	float r;
//public: 
//	Diem tam; 
//	float DienTich(/*VongTron c*/) {
//		return PI * r * r;
//	}
//	void Nhap() {
//		cout << "Tam: "; tam.Nhap();
//		cout << "Ban kinh: "; cin >> r;
//	}
//	void Xuat() {
//
//	}
//	VongTron(float x, float y, float rr):tam(x,y) {
//		r = rr;
//	}
//
//	VongTron() {
//		tam.x = 0;
//		tam.y = 0;
//		r = 1.0;
//	}
//
//	float khoang_cach_den(/*VongTron c1, */ VongTron c2) {
//		return tam.khoang_cach_den(c2.tam);
//	}
//
//	bool chua(/*VongTron c,*/Diem p) {
//		return tam.khoang_cach_den(p) <= r;
//	}
//
//	void setBanKinh(/*VongTron c,*/ float value) {
//		if (value < 0)
//		{
//			cout << "Ban kinh khong duoc phep la so am" << endl;
//			return;
//		}
//		r = value;
//	}
//};

int uscln(int a, int b) {
	a = abs(a);
	b = abs(b);

	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

class PhanSo {
private: 
	int tu, mau;
public: 
	// Nhap, Xuat 
	PhanSo(int t, int m) {
		tu = t;
		mau = m;
	}

	PhanSo(int t): PhanSo(t,1) {}

	PhanSo():PhanSo(0,1) {
		// PhanSo(0,1)
	}

	void Xuat() {
		cout << tu << "/" << mau << endl;
	}
	void toi_gian(/*PhanSo a*/) {
		int t = uscln(abs(tu), abs(mau));
		tu = tu / t;
		mau = mau / t;
	}
	
//	PhanSo cong(/*PhanSo a,*/ PhanSo b) 
	PhanSo operator-(/*PhanSo a,*/ PhanSo b) {
		PhanSo kq;
		kq.tu = tu * b.mau - mau * b.tu;
		kq.mau = mau * b.mau;
		kq.toi_gian();

		return kq;
	}

	friend PhanSo operator+(PhanSo a, PhanSo b);

};

PhanSo operator+(PhanSo a, PhanSo b) {
	PhanSo kq;
	kq.tu = a.tu * b.mau + a.mau * b.tu;
	kq.mau = a.mau * b.mau;

	kq.toi_gian();

	return kq;
}

class LaBaiTay {
private:
	int Nuoc; // 4 = Co, 3 = Ro, 2 = Chuon, 1 = Bich
	int So;   // 1 = Mach, 2 ... 10, 11 = Boi (J), 12 = Dam (Q), 13 = Gia (K)
public: 
	LaBaiTay(int s, int n) {
		Nuoc = n;
		So = s;
	}
	LaBaiTay():LaBaiTay(1,4) {}
	void Nhap() {

	}

	void Xuat() {

	}

	int TrongSo() {
		return So == 1 ? So * 1000 + Nuoc : So * 10 + Nuoc;
	}

	bool LonHon(/*LaBaiTay a,*/ LaBaiTay b) {
		return TrongSo() > b.TrongSo();
	}

	int getNuoc() { return Nuoc;  }
	int getSo() { return So; }
};


class TayPoker {
private:
	LaBaiTay labai[5];
public:
	void Nhap() {}
	void Xuat() {}

	// to-be implement by ChatGPT :) 
	void sort() {
		for (int i = 4; i > 0; i--)
			for (int j = 0; j < i; j++) {
				if (labai[j].LonHon(labai[j + 1])) {
					LaBaiTay tmp = labai[i];
					labai[i] = labai[i + 1];
					labai[i + 1] = tmp;
				}
			}
	}

	// Tra ra loai cua tay bai 
	// 0 = le
	// 1 = 1 doi
	// 2 = 2 doi 
	// 3 = 3 la 
	// 4 = Sanh
	// 5 = Thung
	// 6 = Cu lu
	// 7 = Tu quy
	// 8 = Thung pha sanh 
	int Loai() {
		sort();
		if (ThungPhaSanh()) return 8;
		if (TuQuy()) return 7;
		// if (CuLu()) return 6;
		// ...
		// if (Doi()) return 1;
		return 0;
	}

	bool BaLa() {

	}

	bool MotDoi() {

	}

	bool TuQuy() {

		int countEqual = 1;
		for (int i = 1; i < 5; i++) {
			if (labai[i].getSo() == labai[0].getSo()) countEqual++;
		}
		if (countEqual == 4) return true;

		countEqual = 0;
		for (int i = 1; i < 5; i++) {
			if (labai[i].getSo() == labai[1].getSo()) countEqual++;
		}
		if (countEqual == 4) return true;
		return false;

	}
	bool Thung() {
		return labai[0].getNuoc() == labai[1].getNuoc() &&
			labai[1].getNuoc() == labai[2].getNuoc() &&
			labai[2].getNuoc() == labai[3].getNuoc() &&
			labai[3].getNuoc() == labai[4].getNuoc();
	}

	bool Sanh() {

	}

	bool ThungPhaSanh() {
		return Thung() && Sanh();
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

//void week02() {
//	
//	VongTron c[100];
//	int n;
//	cout << "Nhap so vong tron: ";
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		cout << "Nhap vong tron " << i << ": ";
//		c[i].Nhap();
//	}
//
//	Diem p[100];
//
//	int m;
//	cout << "Nhap so diem: ";
//	cin >> m;
//
//	for (int i = 0; i < m; i++) {
//		cout << "Nhap diem thu " << i << ": ";
//		p[i].Nhap();
//	}
//
//	int max_s = -1;
//
//	for (int i = 0; i < n; i++) { // i = vong tron
//		int s = 0;
//		for (int j = 0; j < m; j++) {  // j = diem
//			if (c[i].chua(p[j])) s++;
//		}
//	}
//
//}

//void week03() {
//	VongTron v(5, 6, 8);
//	cout << "Dien tich vong tron: " << v.DienTich() << endl;
//}

class ThoiGian {
private: 
	int h, m, s;
public: 
	ThoiGian(int hh, int mm, int ss) {
		h = hh;
		m = mm;
		s = ss;
	}
	ThoiGian() :ThoiGian(0, 0, 0) {}
	void Nhap() {}

	ThoiGian operator+(int ss) {
		ThoiGian kq;

		int sss = 60 * (h*60 + m)+ s + ss;

		kq.s = sss % 60;
		kq.m = (sss / 60) % 60;
		kq.h = sss / 3600;
		return kq;
	}

	int operator-(/*ThoiGian a,*/ThoiGian b) {
		int ssa = 60 * (h * 60 + m) + s;
		int ssb = 60 * (b.h * 60 + b.m) + b.s;
		return ssa - ssb;
	}

	friend ostream& operator<<(ostream&,ThoiGian);
	friend istream& operator>>(istream& i, ThoiGian& a);

};

ostream& operator<<(ostream &os, ThoiGian a) {
	os << a.h << ":" << a.m << ":" << a.s << endl;
	return os;
}

istream& operator>>(istream& is, ThoiGian &a) {
	is >> a.h >> a.m >> a.s;
	return is;
}

PhanSo * week04() {
	//PhanSo ps[10];
	//PhanSo t;
	//for (int i = 0; i < 10; i++) {
	//	t = ps[i].cong(t);
	//}

	//t.Xuat();
	ThoiGian t(14,9,30);
	//t.Nhap();
	//ThoiGian t1 = t.cong(50);
	//t1.Xuat();
	return NULL;
}

void testBubble() {
	int a[5] = { 5,3,2,1,-7 };

	for (int i = 4; i > 0; i--)
		for (int j = 0; j < i; j++) {
			if (a[j] >  a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}

	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";

	cout << endl;
}

void week05_th() {
	LaBaiTay labai[100];
	int n = 0;

	for (int i = 0; i < n; i++)
		labai[i].Nhap();

	int max_i = 0;
	LaBaiTay max_labai = labai[0];
	for (int i = 1; i < n; i++) {
		if (labai[i].LonHon(max_labai)) {
			max_i = i;
			max_labai = labai[i];
		}
	}

	cout << "La bai lon nhat: ";
	max_labai.Xuat();

}

void week05() {
	//PhanSo a(1, 2);
	//PhanSo b(3, 2);
	//PhanSo c(4, 2);
	//PhanSo d = a + 5;
	//PhanSo e = 11 + b;
	ThoiGian t(1, 0, 0);
	ThoiGian t1 = t + 65;
	//t1.Xuat();

	cin >> t;
	cout << t1 << endl;
	cout << t1 - t << endl;
}

class CTimeSpan {
private: 
	int ss;
public: 
	CTimeSpan(/* CTimSpan *this */int ss) {
		this->ss = ss;
	}

	CTimeSpan(int h, int m, int s) {
		ss = h * 3600 + m * 60 + s;
	}

	CTimeSpan operator+(CTimeSpan b) {
		return CTimeSpan(ss + b.ss);
	}
	friend ostream& operator<<(ostream& os, CTimeSpan dt);
};

ostream& operator<<(ostream& os, CTimeSpan dt) {
	os << dt.ss / 3600 << ":" << (dt.ss % 3600) / 60 << ":" << dt.ss % 60;
	return os;
}

int DAYS_OF_MONTH[12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class CDate {
	int d, m, y;

	int getDaysOfMonth(int month, int year) {
		bool nam_nhuan = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
		if (month == 2 && nam_nhuan) return 29;
		return DAYS_OF_MONTH[month-1];
	}

public: 
	CDate(int dd, int mm, int yy) {
		d = dd;
		m = mm;
		y = yy;
	}
	friend ostream& operator<<(ostream& os, CDate date);

	CDate operator+(int n) {
		int d_result = d;
		int m_result = m;
		int y_result = y;

		int remaining = n;


		while (remaining > 0) {
			int dd = getDaysOfMonth(m_result, y_result);
			if (d_result + remaining <= dd) {
				d_result += remaining;
				remaining = 0;
			}
			else {
				remaining -= (dd - d_result + 1);
				d_result = 1;
				m_result++;
				if (m_result > 12) {
					m_result = 1;
					y_result++;
				}
			}
		}

		return CDate(d_result, m_result, y_result);
	}
};

ostream& operator<<(ostream& os, CDate date) {
	os << date.d << "/" << date.m << "/" << date.y;
	return os;
}

#define PI 3.1415





//class HinhVuong : public HinhChuNhat {
//public: 
//	void Nhap() {
//		cin >> dai;
//		rong = dai;
//	}
//};


void week06_lab() {
	//CTimeSpan dt1(1, 0, 0);
	//CTimeSpan dt2(0, 30, 1);
	CDate d1(29, 1, 2025);

	for (int n=365;n<=365*2;n++)
		cout << d1 + n << endl;
}

class HocSinh {
protected: 
	string HoTen;
	float Toan, Van;
public: 
	void Nhap() {
		cout << "Ho ten: ";  cin >> HoTen;
		cout << "Diem Toan: ";  cin >> Toan;
		cout << "Diem Van: "; cin >> Van;
	}
	void Xuat() {

	}

	float DiemTB() { return 0; };

	//string XepLoai() {
	//	if (DiemTB() < 5) return "Kem";
	//	else if (DiemTB() < 6.5) return "Trung Binh";
	//	else if (DiemTB() < 8) return "Kha";
	//	else return "Gioi";
	//}
};

class HocSinhKhoiA : public HocSinh {
	float Ly;
public:
	void Nhap() {
		HocSinh::Nhap();
		cout << "Diem Ly: ";  cin >> Ly;
	}
	float DiemTB() { return (Toan + Van + Ly * 2) / 4; }
};


class Hinh {
public:
	virtual float DienTich() = 0;
	virtual void Test() = 0;
	//{
	//	cout << "Hinh::DienTich()" << endl;
	//	return 0; 
	//}
};

class VongTron : public Hinh {
protected:
	float r1;
public:
	VongTron() : VongTron(1.0) {}
	VongTron(float rr) { r1 = rr; }
	float DienTich() {
		cout << "Hinh::VongTron()" << endl;
		return PI * r1 * r1; 
	}
	void Nhap() {
		cout << "VongTron::Nhap()" << endl;
		cin >> r1;
	}
	void Xuat() {
		cout << "VongTron::Xuat()" << endl;
		cout << r1;
	}
};

class HinhChuNhat: public Hinh {
protected:
	float dai, rong;

public:
	HinhChuNhat(float d, float r) {
		dai = d;
		rong = r;
	}
	float DienTich() { return dai * rong; }
};


class Airplane {
protected: 
	float weight;
public: 

	Airplane() {
		cout << "Airplane::Airplane()" << endl;
	}
	Airplane(float w) {
		weight = w;
	}
};

class F16: public Airplane {
public: 
	F16(float w, int invisibleLevel):Airplane(w) {

	}
};

#define DEN 1
#define TRANG 0

class BanCo {
	QuanCo* bc[8][8];
public: 
	BanCo() {
		for (int h = 0; h < 8; h++)
			for (int c = 0; c < 8; c++)
				bc[h][c] = NULL;
	
		bc[0][0] = new Xe(DEN);

	}

	QuanCo * getQuanCo(int h, int c) {
		return bc[h][c];
	}
};

class QuanCo {
protected: 
	int mau;  // 0 = trang, 1 = den
public:
	int getMau() { return mau;  }
	QuanCo(int m) { mau = m; }
	virtual bool nuocDiHopLe(BanCo &banco, int fromH, int fromC, int toH, int toC) = 0;
};

class Xe : public QuanCo {
public: 
	Xe(int m): QuanCo(m) {}

	bool nuocDiHopLe(BanCo& banco, int fromH, int fromC, int toH, int toC) {
		if (toH < 0 || toH>7 || toC < 0 || toC > 7) return false;
		if (fromH != toH && fromC != toC) return false;

		if (fromH == toH) {
			if (fromC < toC) {
				for (int c = fromC + 1; c < toC; c++) {
					if (banco.getQuanCo(fromH, c) != NULL) return false;
				}

				QuanCo* qc = banco.getQuanCo(toH, toC);
				if (qc->getMau() == mau) return false;

				banco.moveQuanCo(this, toH, toC);
			}
		}
	}
};

int main(int) {

	F16 a1(5000,1);

	//VongTron h0(2.3);
	//HinhChuNhat h1(3, 4);
	//VongTron h2(3.5);

	//Hinh* h[3];
	//h[0] = &h0;
	//h[1] = &h1;
	//h[2] = &h2;

	//int n = 3;

	//float tong = 0;
	//for (int i= 0; i < n; i++) {
	//	tong += h[i]->DienTich();
	//}

	return 1;
}