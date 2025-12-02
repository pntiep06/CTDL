#include<iostream>
#include<string>
#include<limits> // can cho numeric_limits

using namespace std;

struct Student{
	string id; 
	string firstName;
	string lastName;
	string gender;
	int birthYear;
	double finalGrade;
}; 
// Khai bao bien kieu hang kich thuoc toi da cua mang Student la 100 
const int MAX_STUDENTS_ARRAY = 100;

// Khai bao cau truc mang Student
struct vector{
	
	int count;
	Student e[MAX_STUDENTS_ARRAY];
	
};


// Ham nhap thong tin cua mot sinh vien
Student inputStudent() {
    Student sv;
    
   
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Lenh xoa bo nho dem truoc khi di vao nhap du lieu kieu string
   	cout << "Nhap ma sinh vien: ";
    getline(cin, sv.id);
    
    cout << "Nhap ho sinh vien: ";
    getline(cin, sv.lastName);
    
    cout << "Nhap ten sinh vien: ";
    getline(cin, sv.firstName);
    
    cout << "Nhap gioi tinh (Nam/Nu): ";
    getline(cin, sv.gender); 
    
    
    cout << "Nhap nam sinh: ";
    cin >> sv.birthYear;
    
    cout << "Nhap diem tong ket: ";
    cin >> sv.finalGrade;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    
    return sv;
}


Student inputStudent(string id, string lastName, string firstName, string gender, int birthYear, double finalGrade)
{
	Student sv;
	sv.id = id;
	sv.lastName = lastName;
	sv.firstName = firstName;
	sv.gender = gender;
	sv.birthYear = birthYear;
	sv.finalGrade = finalGrade;
	
	return sv;
}

// Ham nhap danh sach gom n sinh vien
vector inputStudentList(int n)
{
	vector studentList;
	studentList.count =0;
	
	char choice;
	
	do{
		if(studentList.count>= n || studentList.count >=MAX_STUDENTS_ARRAY)
		{
			cout << "Danh sach da day khong the them sinh vien moi." <<endl;
			break;
		}
		cout << "\n Nhap thong tin sinh vien thu " <<studentList.count + 1 <<": " <<endl;
		studentList.e[studentList.count] = inputStudent();
		studentList.count ++;
		
		cout <<"\n Ban co muon nhap them sinh vien khac khong? (y/n):";
		cin>>choice;
	}while(choice == 'y' || choice == 'Y');
	
	return studentList;
	
}

// Ham in thong tin cua mot sinh vien
void displayStudent(const Student* sv) {
    if (sv == NULL) {
        cout << "Loi: Con tro sinh vien la NULL." << endl;
        return;
    }
   
    cout << "Ma sinh vien: "<< sv->id << ", Ho ten sinh vien: " 
			  << sv->lastName << " " << sv->firstName
              << ", Gioi tinh: " << sv->gender
              << ", Nam sinh: " << sv->birthYear
              << ", Diem tong ket: " << sv->finalGrade << endl;
}


// Ham in danh sach sinh vien
void printStudentList(vector &studentList) { 

    if (studentList.count == 0) {
        cout << "Danh sach sinh vien trong." << endl;
        return;
    }
    cout << "\n--- Danh sach sinh vien ---" << endl;
    for (int i = 0; i < studentList.count; ++i) {
        cout << "Sinh Vien " << i + 1 << "- ";
        displayStudent(&studentList.e[i]); 
    }
    cout << "--------------------------" << endl;
}

// Ham xoa thong tin sinh vien dau tien trong danh sach
void deleteFirstElement(vector &studentList)
{
	if(studentList.count < 0)
	{
		cout << "\n Danh sach rong!";
		return;
	}
	
	for(int i = 1; i<=studentList.count; i++)
	{
		studentList.e[i-1] = studentList.e[i];
	}
	studentList.count --;
}


// Ham kiem tra danh sach da day chua
bool full(vector &studentList)
{
	if(studentList.count==MAX_STUDENTS_ARRAY) return true;
	else return false;
}


//
//// Ham chen thong tin 1 sinh vien vao vi tri k trong danh sach 
int insert(vector &studentList, int k, Student st)
{
	if(k<=studentList.count + 1 && k > 0 && !full(studentList))
	{
		for(int i = studentList.count; i>=k-1; i--)
			studentList.e[i+1]=studentList.e[i];
			
		studentList.e[k-1] = st;
		studentList.count ++;
		return 1;
	}
	else
		return 0;	
	
}
//
//// Ham chen sinh vien vao vi tri thu ba trong danh sach
void insertStudentInto3rdPosition(vector &studentList)
{
	Student sv;
	sv=inputStudent("1006","Le Thi", "Doan", "Nu", 1998, 7.6);
	if(insert(studentList,3,sv))
	{
		cout << "\n Chen thanh cong! ";
		printStudentList(studentList);
	}
	else{
		cout << "\n Chen khong thanh cong";
	}
}
//
//
void selectionSortByName(vector &studentList) {
    //Sap xep sinh vien theo ten theo thu tu tang dan
    int n = studentList.count;
    Student  tmp;
    
	int min;
  
    for(int i = 0;i <n-1; i++) {
    	min = i;
        for(int j = i+1; j < n ; j++) {
            if(studentList.e[j].firstName.compare(studentList.e[min].firstName) < 0) {
                min = j;
            }
        }
        tmp = studentList.e[i];
        studentList.e[i] =  studentList.e[min];
        studentList.e[min] = tmp;
    }
    
    
}

int main() {

     
   	vector myStudentData;
    myStudentData.count = 0;

    myStudentData = inputStudentList(MAX_STUDENTS_ARRAY);
    printStudentList(myStudentData); 
    
    
    cout << "Danh sach sau khi xoa thong tin sinh vien dau tien:" ; 
	deleteFirstElement(myStudentData);
    printStudentList(myStudentData);

	
	Student sv1 = inputStudent();
    
    cout << "--- Thong tin hoc sinh da nhap ---" << endl;
    cout << "Ma sinh vien: " << sv1.id << endl; 
    cout << "Ho va ten: " << sv1.lastName << " " << sv1.firstName << endl; 
    cout << "Gioi tinh: " << sv1.gender << endl;
    cout << "Nam sinh: " << sv1.birthYear << endl;
    cout << "Diem tong ket: " << sv1.finalGrade << endl;
    
    if(insert(myStudentData,2,sv1))
    	cout << "Thanh cong chen sinh vien moi vao. ";
	else 
		cout << "Khong thanh cong khi chen  sinh vien." ;   
		 
   
   	insertStudentInto3rdPosition(myStudentData);
   	printStudentList(myStudentData);
   	
	selectionSortByName(myStudentData);
    printStudentList(myStudentData);
   	
   	
    return 0;
}

