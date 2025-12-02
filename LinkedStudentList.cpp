#include<iostream>
#include<string>
#include<limits> 

using namespace std;

struct Student{
    string id;
    string firstName;
    string lastName;
    string gender;
    int birthYear;
    double finalGrade;
};

// Khai bao cau truc danh sach moc noi
struct Node{
    Student infor;
    Node *next;
};

typedef Node *TRO;

// Ham khoi tao danh sach rong
void init(TRO &L) {
    L = NULL;
}

// Ham kiem tra danh sach rong
bool isEmpty(TRO L) {
    return L == NULL;
}

// Ham them mot sinh vien vao cuoi danh sach
void addLast(TRO &L, Student sv) {
	
    TRO P = new Node();
    
    P->infor = sv;
    P->next = NULL;

    if (isEmpty(L)) {
        L = P;
    } else {
        TRO Q = L;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

// Ham nhap thong tin mot sinh vien
Student inputStudent() {
    Student sv;
    cout << "\n--- Nhap thong tin sinh vien ---";
    cout << "\nMa sinh vien (ID): ";
    cin >> sv.id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa b? d?m bàn phím
    cout << "Ho: ";
    getline(cin, sv.lastName);
    cout << "Ten: ";
    getline(cin, sv.firstName);
    cout << "Gioi tinh: ";
    getline(cin, sv.gender);
    cout << "Nam sinh: ";
    cin >> sv.birthYear;
    cout << "Diem tong ket: ";
    cin >> sv.finalGrade;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa b? d?m bàn phím
    return sv;
}

// Ham hien thi thong tin mot sinh vien
void displayStudent(Student sv) {
    cout << "\nID: " << sv.id
         << ", Ho ten: " << sv.lastName << " " << sv.firstName
         << ", Gioi tinh: " << sv.gender
         << ", Nam sinh: " << sv.birthYear
         << ", Diem cuoi ky: " << sv.finalGrade;
}

// Ham hien thi danh sach sinh vien
void displayList(TRO L) {
    if (isEmpty(L)) {
        cout << "\n Danh sach rong.";
        return;
    }
    cout << "\n--- Danh sach sinh vien ---";
   
    TRO Q = L;
    while (Q != NULL) {
        displayStudent(Q->infor);
        Q = Q->next;
    }
    cout << "\n---------------------------";
}

// Ham xoa phan tu dau tien trong danh sach
void deleteFirstElement(TRO &L)
{
    if(L==NULL) 
    {
        cout << "\n Danh sach rong.";
        return;
    }

    TRO Q = L;
    L=L->next;
    delete Q;
    cout << "\nDa xoa sinh vien dau tien.";
}

int main() {
	
    TRO studentList;
   
    init(studentList);

    cout << "Nhap thong tin cho 3 sinh vien:\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nNhap sinh vien thu " << i + 1 << ":";
        Student sv = inputStudent();
        addLast(studentList, sv);
    }

    displayList(studentList);
    
    // Su dung ham deleteFirstElement
//    deleteFirstElement(studentList);
//    displayList(studentList);
    
    return 0;
}
