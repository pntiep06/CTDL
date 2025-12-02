#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

struct NhanVien {
    string maNV;
    string hoDem;
    string ten;
    string gioiTinh;
    int namSinh;
    double luongCB;
};

void nhapDanhSach(vector<NhanVien> &ds) {
    ds.push_back({"E1001", "Trần Văn", "Bình", "Nam", 1996, 12.0});
    ds.push_back({"E1002", "Trần Mai", "Hương", "Nữ", 1995, 13.5});
    ds.push_back({"E1003", "Nguyễn Thành", "Trung", "Nam", 1994, 14.0});
    ds.push_back({"E1004", "Lê Thanh", "Hà", "Nữ", 1998, 10.0});
    ds.push_back({"E1005", "Phan Đức", "Anh", "Nam", 1992, 15.5});
    ds.push_back({"E1006", "Dương Bình", "Minh", "Nam", 2000, 8.5});
}

void hienThiDanhSach(const vector<NhanVien> &ds) {
    cout << left << setw(5) << "STT" 
         << setw(10) << "Mã NV" 
         << setw(20) << "Họ đệm" 
         << setw(10) << "Tên" 
         << setw(10) << "Giới tính" 
         << setw(10) << "Năm sinh" 
         << setw(15) << "Lương CB (triệu)" 
         << endl;
    cout << string(80, '-') << endl;
    for (size_t i = 0; i < ds.size(); i++) {
        cout << left << setw(5) << i + 1
             << setw(10) << ds[i].maNV
             << setw(20) << ds[i].hoDem
             << setw(10) << ds[i].ten
             << setw(10) << ds[i].gioiTinh
             << setw(10) << ds[i].namSinh
             << setw(15) << ds[i].luongCB
             << endl;
    }
    cout << endl;
}

int timKiemNhiPhanTheoTen(const vector<NhanVien> &ds, const string &tenCanTim) {
    int left = 0, right = ds.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ds[mid].ten == tenCanTim) {
            return mid;
        } else if (ds[mid].ten < tenCanTim) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void sapXepTheoTen(vector<NhanVien> &ds) {
    for (size_t i = 1; i < ds.size(); i++) {
        NhanVien key = ds[i];
        int j = i - 1;
        while (j >= 0 && ds[j].ten > key.ten) {
            ds[j + 1] = ds[j];
            j--;
        }
        ds[j + 1] = key;
    }
}

void themNhanVien(vector<NhanVien> &ds, int viTri) {
    if (viTri < 1 || viTri > ds.size() + 1) {
        cout << "Vị trí không hợp lệ!" << endl;
        return;
    }
    NhanVien nv;
    nv.maNV = "E1007";
    nv.hoDem = "Đinh Thu";
    nv.ten = "Hòa";
    nv.gioiTinh = "Nữ";
    nv.namSinh = 1998;
    nv.luongCB = 11.6;
    ds.insert(ds.begin() + viTri - 1, nv);
}

void xoaNhanVienTheoDieuKien(vector<NhanVien> &ds) {
    int namHienTai = 2025; // Giả sử năm hiện tại là 2025
    vector<NhanVien> dsMoi;
    for (const auto &nv : ds) {
        int tuoi = namHienTai - nv.namSinh;
        if (!(tuoi > 30 && nv.luongCB > 15.5)) {
            dsMoi.push_back(nv);
        }
    }
    ds = dsMoi;
}

int main() {
    vector<NhanVien> danhSach;
    
    // 1. Nhập và hiển thị danh sách
    nhapDanhSach(danhSach);
    cout << "Danh sách nhân viên ban đầu:" << endl;
    hienThiDanhSach(danhSach);
    
    // 2. Tìm kiếm nhị phân theo tên "Anh" (cần sắp xếp trước)
    sapXepTheoTen(danhSach);
    cout << "Danh sách sau khi sắp xếp theo tên:" << endl;
    hienThiDanhSach(danhSach);
    
    int viTri = timKiemNhiPhanTheoTen(danhSach, "Anh");
    if (viTri != -1) {
        cout << "Tìm thấy nhân viên tên 'Anh' tại vị trí: " << viTri + 1 << endl;
        cout << "Thông tin: " << danhSach[viTri].maNV << " - "
             << danhSach[viTri].hoDem << " " << danhSach[viTri].ten << endl;
    } else {
        cout << "Không tìm thấy nhân viên tên 'Anh'." << endl;
    }
    cout << endl;
    
    // 3. Thêm nhân viên vào vị trí thứ 3
    themNhanVien(danhSach, 3);
    cout << "Danh sách sau khi thêm nhân viên mới vào vị trí thứ 3:" << endl;
    hienThiDanhSach(danhSach);
    
    // 4. Xóa nhân viên tuổi > 30 và lương > 15.5 triệu
    xoaNhanVienTheoDieuKien(danhSach);
    cout << "Danh sách sau khi xóa nhân viên tuổi > 30 và lương > 15.5 triệu:" << endl;
    hienThiDanhSach(danhSach);
    
    return 0;
}
