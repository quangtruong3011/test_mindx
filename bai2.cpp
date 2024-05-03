#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Vemaybay
{
private:
    string tenchuyen;
    string ngaybay;
    int giave;

public:
    Vemaybay(string tenchuyen, string ngaybay, int giave) : tenchuyen(tenchuyen), ngaybay(ngaybay), giave(giave) {}

    ~Vemaybay() {}

    void Nhap()
    {
        cout << "Nhap ten chuyen bay: ";
        getline(cin, tenchuyen);
        cout << "Ngay bay: ";
        getline(cin, ngaybay);
        cout << "Gia ve: ";
        cin >> giave;
        cin.ignore();
    }

    void Xuat()
    {
        cout << "Ten chuyen bay: " << tenchuyen << " Ngay bay: " << ngaybay << " Gia ve: " << giave << endl;
    }

    int getGiave()
    {
        return giave;
    }
};

class Nguoi
{
private:
    string hoten;
    string gioitinh;
    int tuoi;

public:
    Nguoi(string hoten, string gioitinh, int tuoi) : hoten(hoten), gioitinh(gioitinh), tuoi(tuoi) {}

    ~Nguoi() {}

    void Nhap()
    {
        cout << "Ho ten: ";
        getline(cin, hoten);
        cout << "Gioi tinh: ";
        getline(cin, gioitinh);
        cout << "Tuoi: ";
        cin >> tuoi;
        cin.ignore();
    }

    void Xuat()
    {
        cout << "Ho ten: " << hoten << " Gioi tinh: " << gioitinh << " Tuoi: " << tuoi << endl;
    }
};

class HanhKhach : Nguoi
{
private:
    Vemaybay *ve;
    int soluong;

public:
    HanhKhach(string hoten, string gioitinh, int tuoi, Vemaybay *ve, int soluong) : Nguoi(hoten, gioitinh, tuoi), ve(ve), soluong(soluong) {}

    ~HanhKhach() {}

    void Nhap()
    {
        Nguoi::Nhap();
        ve->Nhap();
        cout << "So luong: ";
        cin >> soluong;
        cin.ignore();
    }

    void Xuat()
    {
        Nguoi::Xuat();
        ve->Xuat();
        cout << "So luong: " << soluong << endl;
    }

    int tongTien()
    {
        return ve->getGiave() * soluong;
    }
};

int main()
{
    vector<HanhKhach> hanhKhachs;
    int choice;

    do
    {
        cout << "1. Nhap thong tin hanh khach." << endl;
        cout << "2. Xuat thong tin hanh khach." << endl;
        cout << "3. Sap xep thong tin hanh khach." << endl;
        cout << "4. Thoat" << endl;

        cout << "Lua chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int n;
            cout << "So luong hanh khach: ";
            cin >> n;
            cin.ignore();
            for (int i = 0; i < n; i++)
            {
                cout << "Hanh khach " << i + 1 << ":" << endl;
                HanhKhach hanhKhach("", "", 0, new Vemaybay("", "", 0), 0);
                hanhKhach.Nhap();
                hanhKhachs.push_back(hanhKhach);
            }
            break;
        }

        case 2:
        {
            for (HanhKhach hanhKhach : hanhKhachs)
            {
                hanhKhach.Xuat();
                hanhKhach.tongTien();
            }
            break;
        }

        case 3:
        {
            sort(hanhKhachs.begin(), hanhKhachs.end(), [](HanhKhach a, HanhKhach b)
                 { return a.tongTien() > b.tongTien(); });
            cout << "Sap xep thanh cong!" << endl;
            break;
        }

        case 4:
        {
            cout << "Goodbye!" << endl;
            break;
        }

        default:
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
