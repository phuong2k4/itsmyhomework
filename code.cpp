#include <bits/stdc++.h>
#include <map>

using namespace std;

struct SinhVien
{
    string id_code;
    string name_Student;
    int born_Year;
    float average_Point;
};

void input(vector<SinhVien> &ds, int &n)
{
    do
    {
        cout << "Nhap so luong sinh vien: ";
        cin >> n;
    } while (n < 0 && n >= 100);
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        SinhVien sv;
        cout << "Nhap thong tin cua sinh vien: " << endl;

        cout << "Ma sinh vien: " << endl;
        getline(cin, sv.id_code);
        cout << "Ten sinh vien: " << endl;
        getline(cin, sv.name_Student);
        cout << "Nam sinh: " << endl;
        cin >> sv.born_Year;
        cout << "Diem trung binh: " << endl;
        cin >> sv.average_Point;

        cin.ignore();
        ds.push_back(sv);
    }
}

void output(vector<SinhVien> &ds)
{
    if (ds.empty())
    {
        cout << "Khong co sinh vien trong bang du lieu.";
        return;
    }
    cout << "\n===================================================================" << endl;
    cout << "                         DANH SACH SINH VIEN" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << left << setw(10) << "Ma Sv:" << endl
         << setw(30) << "Ten Sv: " << endl
         << setw(10) << "Nam Sinh: " << endl
         << setw(10) << "Diem Trung Binh: " << endl;

    for (auto &sv : ds)
    {
        cout << left << setw(10) << sv.id_code
             << setw(30) << sv.name_Student
             << setw(10) << sv.born_Year
             << fixed << setprecision(2) << sv.average_Point << endl;
    }
}

void sequentiallySearch(vector<SinhVien> &ds)
{
    if (ds.empty())
    {
        cout << "Khong co danh sach sinh vien!";
        return;
    }
    string findSbd;
    cout << "Nhap ho ten can tim: " << endl;
    getline(cin, findSbd);
    int i = 0;
    while (i < ds.size() && ds[i].name_Student != findSbd)
    {
        i++;
    }
    if (i < ds.size())
    {
        cout << "Thong tin sinh vien tim kiem: " << endl;
        cout << "Ma Sv: " << ds[i].id_code << endl;
        cout << "Ten Sv: " << ds[i].name_Student << endl;
        cout << "Nam Sinh : " << ds[i].born_Year << endl;
        cout << "Diem Trung Binh: " << ds[i].average_Point << endl;
    }
    else
    {
        cout << "Khong co sinh vien nao co ten nhu vay!" << endl;
        return;
    }
}

void bubbleSort(vector<SinhVien> &ds)
{
    int n = ds.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ds[j].average_Point < ds[j + 1].average_Point)
            {
                double temp = ds[j].average_Point;
                ds[j].average_Point = ds[j + 1].average_Point;
                ds[j + 1].average_Point = temp;
                swapped = true;
            }
        }
        if (!swapped)
            return;
    }
}

void binarySearch(vector<SinhVien> &ds, double key)
{
    int left = 0, right = ds.size() - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (ds[mid].average_Point == key)
        {
            cout << "Thong tin sinh vien can tim: " << endl;
            cout << "Ma Sinh Vien: " << ds[mid].id_code << endl;
            cout << "Ten Sinh Vien: " << ds[mid].name_Student << endl;
            cout << "Nam sinh Sinh Vien: " << ds[mid].born_Year << endl;
            cout << "Diem TB: " << ds[mid].average_Point << endl;
            return;
        }
        else if (ds[mid].average_Point > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << "Khong tim thay sinh vien";
}

void insertionSortString(vector<SinhVien> &ds)
{
    for (int i = 1; i < ds.size(); i++)
    {
        SinhVien flag = ds[i];
        int j = i - 1;
        while (j >= 0 && flag.name_Student < ds[j].name_Student)
        {
            ds[j + 1] = ds[j];
            j--;
        }
        ds[j + 1] = flag;
    }
}

void insertionSortInterger(vector<SinhVien>&ds){
    for(int i = 1; i<ds.size();i++){
        SinhVien flag = ds[i];
        int j = i-1;
        while(j>=0 && flag.average_Point < ds[j].average_Point){
            ds[j+1] = ds[j];
            j--;
        }
        ds[j+1] = flag;
    }
}

void sequentiallySearchAdvanced(vector<SinhVien> &ds)
{
    if (ds.empty())
    {
        cout << "Danh Sach Sinh Vien Trong!" << endl;
        return;
    }
    string findName;
    getline(cin, findName);
    int i = 0;
    SinhVien sv;
    sv.name_Student = findName;
    ds.push_back(sv);

    while (ds[ds.size()].name_Student != findName)
    {
        i++;
    }
    if (i < ds.size())
    {
        cout << "Thong tin sinh vien tim kiem: " << endl;
        cout << "Ma Sv: " << ds[i].id_code << endl;
        cout << "Ten Sv: " << ds[i].name_Student << endl;
        cout << "Nam Sinh : " << ds[i].born_Year << endl;
        cout << "Diem Trung Binh: " << ds[i].average_Point << endl;
    }
    else
    {
        cout << "Khong tim thay sinh vien! " << endl;
    }
}

int main()
{
    vector<SinhVien> list;
    int quantity = 0;

    input(list, quantity);
    output(list);

    return 0;
}