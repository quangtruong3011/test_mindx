#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vemaybay
{
private:
    string tenchuyen;
    string ngaybay;
    float giave;

public:
    Vemaybay() : giave(0.0f) {}

    Vemaybay(string tenchuyen, string ngaybay, float giave) : tenchuyen(tenchuyen), ngaybay(ngaybay), giave(giave) {}

    ~Vemaybay() {}

    void Nhap()
    {
        cout << "Nhap ten chuyen: ";
        getline(cin, tenchuyen);
        cout << "Ngay bay: ";
        getline(cin, ngaybay);
        cout << "Gia ve: ";
        cin >> giave;
        cin.ignore();
    }

    void Xuat()
    {
        cout << "Ten chuyen: " << tenchuyen << " Ngay bay: " << ngaybay << " Gia ve: " << giave << endl;
    }

    float getgiave() const
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
    Nguoi() : tuoi(0) {}

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

class Hanhkhach : public Nguoi
{
private:
    vector<Vemaybay> ve;
    int soluong;

public:
    Hanhkhach() : soluong(0) {}

    Hanhkhach(string hoten, string gioitinh, int tuoi, int soluong) : Nguoi(hoten, gioitinh, tuoi), soluong(soluong) {}

    ~Hanhkhach() {}

    void Nhap()
    {
        Nguoi::Nhap();
        cout << "So luong ve: ";
        cin >> soluong;
        cin.ignore();
        ve.resize(soluong);
        for (int i = 0; i < soluong; i++)
        {
            cout << "Ve thu " << i + 1 << ": " << endl;
            ve[i].Nhap();
        }
    }

    void Xuat()
    {
        Nguoi::Xuat();
        cout << "So luong ve: " << soluong << endl;
        for (int i = 0; i < soluong; i++)
        {
            cout << "Ve thu " << i + 1 << ": " << endl;
            ve[i].Xuat();
        }
    }

    float Tongtien()
    {
        float sum = 0;
        for (int i = 0; i < soluong; i++)
        {
            sum += ve[i].getgiave();
        }
        cout << "Tong tien: " << sum << endl;
        return sum;
    }
};

int main()
{
    Hanhkhach *hanhkhach = nullptr;
    int tongHanhKhach = 0;

    cout << "1. Nhap thong tin hanh khach" << endl;
    cout << "2. Xuat thong tin hanh khach" << endl;
    cout << "3. Sap xep thong tin hanh khach" << endl;
    cout << "4. Thoat" << endl;

    int choice;

    do
    {
        cout << "Chon chuc nang: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
            {
                int n;
                cout << "Nhap so luong hanh khach: ";
                cin >> n;
                tongHanhKhach += n;
                cin.ignore();
                hanhkhach = new Hanhkhach[n];
                for (int i = 0; i < n; i++)
                {
                    cout << "Hanh khach thu " << i + 1 << ": " << endl;
                    hanhkhach[i].Nhap();
                }

                break;
            }

            case 2:
                if (hanhkhach == nullptr)
                {
                    cout << "Chua nhap thong tin hanh khach" << endl;
                }
                else
                {
                    for (int i = 0; i < tongHanhKhach; i++)
                    {
                        cout << "Hanh khach thu " << i + 1 << ": " << endl;
                        hanhkhach[i].Xuat();
                        hanhkhach[i].Tongtien();
                    }
                }
                break;

            case 3:
                if (hanhkhach == nullptr)
                {
                    cout << "Chua nhap thong tin hanh khach" << endl;
                }
                else
                {
                    for (int i = 0; i < tongHanhKhach - 1; i++)
                    {
                        for (int j = i + 1; j < tongHanhKhach; j++)
                        {
                            if (hanhkhach[i].Tongtien() < hanhkhach[j].Tongtien())
                            {
                                swap(hanhkhach[i], hanhkhach[j]);
                            }
                        }
                    }
                    cout << "Danh sach hanh khach: " << endl;
                    for (int i = 0; i < tongHanhKhach; i++)
                    {
                        cout << "Hanh khach thu " << i + 1 << ": " << endl;
                        hanhkhach[i].Xuat();
                        hanhkhach[i].Tongtien();
                    }
                }
                break;

            case 4:
                cout << "Goodbye!" << endl;
                if (hanhkhach != nullptr)
                {
                    delete[] hanhkhach;
                }
                break;

            default:
                cout << "Lua chon khong hop le. Vui long chon lai" << endl;
                break;
            }
        }
        catch (exception const &ex)
        {
            cerr << "ERROR: " << ex.what() << endl;
        }

    } while (choice != 4);

    return 0;
}
