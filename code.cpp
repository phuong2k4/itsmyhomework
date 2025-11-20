#include <bits/stdc++.h>

using namespace std;
#include<bits/stdc++.h>
using namespace std;

// List Struct
struct SinhVien{
	string hovaten;
	string gioitinh;
	long namsinh;
	float diemtongket;
};


void input(vector<SinhVien> ds){
	int n;
	do{
		cout << "Nhap so luong sinh vien: ";
		cin >> n;
	}while(n < 0 && n > 100);
	cin.ignore();
	for(int i = 0;i<n;i++){
		SinhVien sv;
		cout << "Nhap ho va ten: " ;
		getline(cin, sv.hovaten);
		cout << "Nhap gioi tinh: ";
		getline(cin,sv.gioitinh);
		cout << "Nhap nam sinh: ";
		cin >> sv.namsinh;
		cin.ignore();
		cout << "Nhap diem tong ket: ";
		cin >> sv.diemtongket;
		cin.ignore();
		
		ds.push_back(sv);
	}
}

void output(vector<SinhVien> ds){
	if(ds.empty()){
		cout << "Danh sach trong.";
		return;
	}
	cout << "Danh Sach Sinh Vien" << endl;
	cout << left << setw(10) << "Ho va Ten"
	<< setw(20) << "Gioi Tinh"
	<< setw(20) << "Nam Sinh"
	<< setw(10) << "Diem Tong Ket" << endl;
	
	for(auto it : ds){
		cout << left << setw(10) << it.hovaten
		<< setw(20) << it.gioitinh
		<< setw(20) << it.namsinh
		<< setw(10) << it.diemtongket << endl;
	}
}

void sequentialSearch(vector<SinhVien> &ds){
	string key;
	cout << "Nhap ten sinh vien muon tim: ";
	cin >> key;
	int i = 0;
	while(i< ds.size() && ds[i] != key){
		i++;
	}
	if(i < ds.size()){
		cout << left << setw(10) << "Ho va Ten"
		<< setw(20) << "Gioi Tinh"
		<< setw(20) << "Nam Sinh"
		<< setw(10) << "Diem Tong Ket" << endl;
		
		cout << left << setw(10) << ds[i].hovaten
		<< setw(20) << ds[i].gioitinh
		<< setw(20) << ds[i].namsinh
		<< setw(10) << ds[i].diemtongket << endl;
		return;
	}
	cout << "khong co du lieu";
	return;
}

void bbsort(vector<SinhVien> &ds){
	for(int i = 0;i<ds.size()-1;i++){
		bool swapped = false;
		for(int j = 0;j<ds.size()-i-1;j++){
			if(ds[j].diemtongket > ds[j+1].diemtongket){
				swap(ds[j],ds[j+1]);
				swapped=true;
			}
		}
		if(!swapped)return;
	}
}

void binarySearch(vector<SinhVien> &ds){
	float diemcantim;
	cout << "Nhap Diem Can Tim: ";
	cin >> diemcantim;
	int l = 0,r=ds.size()-1;
	int mid;
	
	while(l<r){
		mid = (l+r)/2;
		if(ds[mid].diemtongket == diemcantim){
			cout << left << setw(10) << "Ho va Ten"
			<< setw(20) << "Gioi Tinh"
			<< setw(20) << "Nam Sinh"
			<< setw(10) << "Diem Tong Ket" << endl;
			
			cout << left << setw(10) << ds[mid].hovaten
			<< setw(20) << ds[mid].gioitinh
			<< setw(20) << ds[mid].namsinh
			<< setw(10) << ds[mid].diemtongket << endl;
			return;
		}else if(ds[mid].diemtongket > diemcantim){
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	cout << "Khong tim thay";
	return;
}

//List vector
#define Max 100

struct HangHoa{
	int stt;
	string MaHang;
	string tenhang;
	string donvitinh;
	long dongia;
	int soluong;
	long long thanhtien;
};

struct Vector{
	int count;
	HangHoa hh[Max];
};

void nhap1Hang(HangHoa &hh){
	cout << "Nhap So TT: ";
	cin >> hh.stt;
	cin.ignore();
	cout << "Nhap Ma Hang: ";
	getline(cin, hh.MaHang);
	cout << "Nhap Ten Hang: ";
	getline(cin, hh.tenhang);
	cout << "Nhap Don Vi Tinh: ";
	getline(cin,hh.donvitinh);
	cout << "Nhap Don Gia: ";
	cin >> hh.dongia;
	cin.ignore();
	cout << "Nhap So Luong: ";
	cin >> hh.soluong;
	cin.ignore();
	hh.thanhtien = hh.dongia * hh.soluong;
}

void nhapDanhSach(Vector &ds){
	cout << "So luong hang hoa: ";
	cin >> ds.count;
	cin.ignore();
	for(int i = 0;i<ds.count;i++){
		HangHoa hhoa;
		nhap1Hang(hhoa);
		ds.hh[i] = hhoa;
	}
}

void in1Hang(HangHoa &hh){
	cout << left << setw(10) << hh.stt
	<< setw(20) << hh.MaHang
	<< setw(20) << hh.tenhang
	<< setw(20) << hh.donvitinh
	<< setw(20) << hh.dongia
	<< setw(20) << hh.soluong
	<< setw(20) << hh.thanhtien << endl;
}

void xuatDanhSach(Vector &ds){
	
	if(ds.count <0){
		cout << "Trong." << endl;
		return;
	}
	
	cout << "Danh sach hang hoa" << endl;
	cout << left << setw(10) << "STT"
	<< setw(20) << "Ma Hang"
	<< setw(20) << "TenHang"
	<< setw(20) << "Don Vi Tinh"
	<< setw(20) << "Don Gia"
	<< setw(20) << "So Luong"
	<< setw(20) << "Thanh Tien" << endl;
	
	for(int i = 0;i<ds.count;i++){
		in1Hang(ds.hh[i]);
	}
}
void delHang(Vector &ds){
	if(ds.count < 0){
		cout << "Trong.";
		return;
	}
	int n;
	cout << "Ban muon xoa phan tu nao? ";
	cin >> n;
	for(int i = ds.count;i>=n;i--){
		swap(ds.hh[i],ds.hh[i-1]);
	}
	ds.count--;
}

void insertHang(Vector &ds){
	if(ds.count < 0){
		HangHoa hhoa;
		nhap1Hang(hhoa);
		ds.hh[0] = hhoa;
		return;
	}
	int n;
	cout << "Nhap vi tri muon chen: ";
	cin >> n;
	for(int i = ds.count;i>n;i--){
		swap(ds.hh[i],ds.hh[i-1]);
	}
	HangHoa hhoa;
	nhap1Hang(hhoa);
	ds.hh[n] = hhoa;
	ds.count++;
}

//list node
struct HangHoa{
	int stt;
	string MaHang;
	string tenhang;
	string donvitinh;
	long dongia;
	int soluong;
	long long thanhtien;
};
struct node{
	HangHoa hh;
	node *next;
};

typedef node *tro;

void nhap1Hang(HangHoa &hh){
	cout << "Nhap So TT: ";
	cin >> hh.stt;
	cin.ignore();
	cout << "Nhap Ma Hang: ";
	getline(cin, hh.MaHang);
	cout << "Nhap Ten Hang: ";
	getline(cin, hh.tenhang);
	cout << "Nhap Don Vi Tinh: ";
	getline(cin,hh.donvitinh);
	cout << "Nhap Don Gia: ";
	cin >> hh.dongia;
	cin.ignore();
	cout << "Nhap So Luong: ";
	cin >> hh.soluong;
	cin.ignore();
	hh.thanhtien = hh.dongia * hh.soluong;
}
tro taoNode(HangHoa &hhoa){
	tro p = new node;
	p->hh = hhoa;
	p->next = nullptr;
	return p;
}

void nhapNode(tro &l, HangHoa &hh){
	tro p = taoNode(hh);
	if(l==nullptr){
		l = p;
		return;
	}
	tro q = l;
	while(q->next != nullptr){
		q= q->next;
	}
	q->next = p;
}
void in1Hang(HangHoa &hh){
	cout << left << setw(10) << hh.stt
	<< setw(20) << hh.MaHang
	<< setw(20) << hh.tenhang
	<< setw(20) << hh.donvitinh
	<< setw(20) << hh.dongia
	<< setw(20) << hh.soluong
	<< setw(20) << hh.thanhtien << endl;
}

void xuatNode(tro &l){
	if(l==nullptr){
		cout << "Trong.";
		return;
	}
	cout << "Danh sach hang hoa" << endl;
	cout << left << setw(10) << "STT"
	<< setw(20) << "Ma Hang"
	<< setw(20) << "TenHang"
	<< setw(20) << "Don Vi Tinh"
	<< setw(20) << "Don Gia"
	<< setw(20) << "So Luong"
	<< setw(20) << "Thanh Tien" << endl;
	tro p = l;
	while(p!=nullptr){
		in1Hang(p->hh);
		p=p->next;
	}
}

int main(){
	tro l=nullptr;
	int n;
	cout << "So luong hang hoa: ";
	cin >> n;
	for(int i = 0;i<n;i++){
		HangHoa hh;
		nhap1Hang(hh);
		nhapNode(l,hh);
	}
	xuatNode(l);
	return 0;
}