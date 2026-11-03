#include<iostream>
#include<string>
using namespace std;
class phuongtien{
	private:
		int maxe;
		string loaixe;
		int giovao;
		int tgdo;
	public:
		phuongtien();
		phuongtien(int ma, string loai, int gio, int tg);
		
		int laymaxe() const;
    	string layloaixe() const;
		double tinhphi() const;
    	void hienthi() const;
};
phuongtien::phuongtien(){
	maxe = 0;
	loaixe = "";
	giovao = 0;
	tgdo = 0;
}
phuongtien::phuongtien(int ma, string loai, int gio, int tg){
	maxe = ma;
	loaixe = loai;
	giovao = gio;
	tgdo = tg;
}
int phuongtien::laymaxe() const {
	return maxe;
}
string phuongtien::layloaixe() const {
    return loaixe;
}
double phuongtien::tinhphi() const {
    double gia = 0.0;
    if (loaixe == "Car" || loaixe == "car") gia = 6.0;
    if (loaixe == "Motorcycle" || loaixe == "motorcycle") gia = 4.0;
    if (loaixe == "Bicycle" || loaixe == "bicycle") gia = 2.0;

    bool caodiem = false;
    if ((giovao >= 6 && giovao <= 9) || (giovao >= 15 && giovao <= 18)) {
        caodiem = true;
    }
    double phi = 0.0;
    if (tgdo <= 2) {
        if (caodiem) {
            phi = tgdo * (gia * 1.3);
        } else {
            phi = tgdo * (gia * 0.95);
        }
    } else {
        if (caodiem) {
            phi = 2 * (gia * 1.3);
        } else {
            phi = 2 * (gia * 0.95);
        }
        phi = phi + (tgdo - 2) * (gia * 0.9);
    }
    return phi;
}
void phuongtien::hienthi() const {
    cout << "  Ma xe: " << maxe 
         << " | Loai: " << loaixe 
         << " | Gio vao: " << giovao 
         << " | Tg do: " << tgdo 
         << " | Phi: " << tinhphi() << "$" << endl;
}
class baixe {
private:
    int mabai;
    char kichthuoc;
    phuongtien pt1, pt2, pt3;
    bool co1, co2, co3;

public:
    baixe();
    baixe(int ma, char kt);
    int layma() const;
    bool them(phuongtien v);
    bool xoa(int maxe);
    bool chua(int maxe) const;
    void hienthi() const;
    bool coloai(string loai, int& dem, double& tong) const;
};
baixe::baixe() {
    mabai = 0;
    kichthuoc = ' ';
    co1 = false;
    co2 = false;
    co3 = false;
}

baixe::baixe(int ma, char kt) {
    mabai = ma;
    kichthuoc = kt;
    co1 = false;
    co2 = false;
    co3 = false;
}
int baixe::layma() const {
    return mabai;
}
bool baixe::them(phuongtien v) {
    if (kichthuoc == 'S' || kichthuoc == 's') {
        if (!co1) {
            pt1 = v;
            co1 = true;
            return true;
        }
    }
    if (kichthuoc == 'M' || kichthuoc == 'm') {
        if (!co1) {
            pt1 = v;
            co1 = true;
            return true;
        }
        if (!co2) {
            pt2 = v;
            co2 = true;
            return true;
        }
    }
    if (kichthuoc == 'L' || kichthuoc == 'l') {
        if (!co1) {
            pt1 = v;
            co1 = true;
            return true;
        }
        if (!co2) {
            pt2 = v;
            co2 = true;
            return true;
        }
        if (!co3) {
            pt3 = v;
            co3 = true;
            return true;
        }
    }
    return false;
}
bool baixe::xoa(int maxe) {
    if (co1 && pt1.laymaxe() == maxe) {
        co1 = false;
        return true;
    }
    if (co2 && pt2.laymaxe() == maxe) {
        co2 = false;
        return true;
    }
    if (co3 && pt3.laymaxe() == maxe) {
        co3 = false;
        return true;
    }
    return false;
}
bool baixe::chua(int maxe) const {
    if (co1 && pt1.laymaxe() == maxe) return true;
    if (co2 && pt2.laymaxe() == maxe) return true;
    if (co3 && pt3.laymaxe() == maxe) return true;
    return false;
}
void baixe::hienthi() const {
    cout << "Bai xe ma: " << mabai << " | Kich thuoc: " << kichthuoc << endl;
    if (!co1 && !co2 && !co3) {
        cout << "  (Bai dang trong)" << endl;
        return;
    }
    if (co1) pt1.hienthi();
    if (co2) pt2.hienthi();
    if (co3) pt3.hienthi();
}
bool baixe::coloai(string loai, int& dem, double& tong) const {
    bool co = false;
    if (co1 && pt1.layloaixe() == loai) {
        dem++;
        tong = tong + pt1.tinhphi();
        pt1.hienthi();
        co = true;
    }
    if (co2 && pt2.layloaixe() == loai) {
        dem++;
        tong = tong + pt2.tinhphi();
        pt2.hienthi();
        co = true;
    }
    if (co3 && pt3.layloaixe() == loai) {
        dem++;
        tong = tong + pt3.tinhphi();
        pt3.hienthi();
        co = true;
    }
    return co;
}
class SystemInterface {
private:
    baixe bai1, bai2, bai3;
    bool co1, co2, co3;

public:
    SystemInterface();
    void runMenu();
};
SystemInterface::SystemInterface() {
    co1 = false;
    co2 = false;
    co3 = false;
}
void SystemInterface::runMenu() {
    int chon = 0;
    while (chon != 9) {
        cout << "\n===== MENU QUAN LY BAI DO XE =====" << endl;
        cout << "1. Tao bai xe moi" << endl;
        cout << "2. Them xe" << endl;
        cout << "3. Xoa bai xe" << endl;
        cout << "4. Lay xe ra" << endl;
        cout << "5. Hien thi tat ca bai xe" << endl;
        cout << "6. Hien thi xe theo ma bai" << endl;
        cout << "7. Liet ke theo loai xe" << endl;
        cout << "8. Tinh phi trung binh" << endl;
        cout << "9. Thoat" << endl;
        cout << "Chon chuc nang (1-9): ";
        cin >> chon;

        if (chon == 1) {
            int ma;
            char kt;
            cout << "Nhap ma bai: ";
            cin >> ma;
            cout << "Nhap kich thuoc (S, M, L): ";
            cin >> kt;

            if (!co1) {
                bai1 = baixe(ma, kt);
                co1 = true;
                cout << "Tao bai xe thanh cong o vi tri 1!\n";
            } else if (!co2) {
                bai2 = baixe(ma, kt);
                co2 = true;
                cout << "Tao bai xe thanh cong o vi tri 2!\n";
            } else if (!co3) {
                bai3 = baixe(ma, kt);
                co3 = true;
                cout << "Tao bai xe thanh cong o vi tri 3!\n";
            } else {
                cout << "He thong da du 3 bai xe!\n";
            }
        } 
        else if (chon == 2) {
            int ma, gio, tg;
            string loai;
            cout << "Nhap ma xe: ";
            cin >> ma;
            cout << "Nhap loai xe (Car, Motorcycle, Bicycle): ";
            cin >> loai;
            cout << "Nhap gio vao (0..23): ";
            cin >> gio;
            cout << "Nhap thoi gian do (1..23): ";
            cin >> tg;

            phuongtien v(ma, loai, gio, tg);
            bool dathem = false;

            if (co1 && bai1.them(v)) {
                dathem = true;
                cout << "Da xep vao bai " << bai1.layma() << endl;
            } else if (co2 && bai2.them(v)) {
                dathem = true;
                cout << "Da xep vao bai " << bai2.layma() << endl;
            } else if (co3 && bai3.them(v)) {
                dathem = true;
                cout << "Da xep vao bai " << bai3.layma() << endl;
            }

            if (!dathem) {
                cout << "Khong the them xe (cac bai da day hoac chua tao bai)!\n";
            }
        } 
        else if (chon == 3) {
            int ma;
            cout << "Nhap ma bai can xoa: ";
            cin >> ma;

            if (co1 && bai1.layma() == ma) {
                co1 = false;
                cout << "Da xoa bai xe " << ma << endl;
            } else if (co2 && bai2.layma() == ma) {
                co2 = false;
                cout << "Da xoa bai xe " << ma << endl;
            } else if (co3 && bai3.layma() == ma) {
                co3 = false;
                cout << "Da xoa bai xe " << ma << endl;
            } else {
                cout << "Khong tim thay ma bai nay!\n";
            }
        } 
        else if (chon == 4) {
            int ma;
            cout << "Nhap ma xe can lay ra: ";
            cin >> ma;
            
            bool dalay = false;
            if (co1 && bai1.xoa(ma)) dalay = true;
            if (co2 && bai2.xoa(ma)) dalay = true;
            if (co3 && bai3.xoa(ma)) dalay = true;

            if (dalay) {
                cout << "Da lay xe " << ma << " ra khoi bai!\n";
            } else {
                cout << "Khong tim thay xe trong he thong!\n";
            }
        } 
        else if (chon == 5) {
            if (!co1 && !co2 && !co3) {
                cout << "Hien tai chua co bai xe nao.\n";
            } else {
                if (co1) bai1.hienthi();
                if (co2) bai2.hienthi();
                if (co3) bai3.hienthi();
            }
        } 
        else if (chon == 6) {
            int ma;
            cout << "Nhap ma bai can xem: ";
            cin >> ma;

            if (co1 && bai1.layma() == ma) bai1.hienthi();
            else if (co2 && bai2.layma() == ma) bai2.hienthi();
            else if (co3 && bai3.layma() == ma) bai3.hienthi();
            else cout << "Khong tim thay ma bai!\n";
        } 
        else if (chon == 7) {
            string loai;
            cout << "Nhap loai xe can tim (Car/Motorcycle/Bicycle): ";
            cin >> loai;

            int dem = 0;
            double tong = 0.0;
            if (co1) bai1.coloai(loai, dem, tong);
            if (co2) bai2.coloai(loai, dem, tong);
            if (co3) bai3.coloai(loai, dem, tong);

            if (dem == 0) {
                cout << "Khong co xe nao thuoc loai " << loai << endl;
            }
        } 
        else if (chon == 8) {
            string ds[3] = {"Car", "Motorcycle", "Bicycle"};
            for (int i = 0; i < 3; i++) {
                int dem = 0;
                double tong = 0.0;
                if (co1) bai1.coloai(ds[i], dem, tong);
                if (co2) bai2.coloai(ds[i], dem, tong);
                if (co3) bai3.coloai(ds[i], dem, tong);

                cout << "Loai " << ds[i] << ": ";
                if (dem > 0) {
                    cout << "Tong = " << dem << " xe, Phi trung binh = " << tong / dem << "$" << endl;
                } else {
                    cout << "Chua co xe" << endl;
                }
            }
        }
    }
    cout << "Ket thuc chuong trinh!\n";
}
int main() {
    SystemInterface si;
    si.runMenu();
    return 0;
}
