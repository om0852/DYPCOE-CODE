

// 2.Develop a program in C++ to create a database of student's information system containing the
// following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact
// address, Telephone number, Driving license no. and other. Construct the database with
// suitable member functions. Make use of constructor, default constructor, copy constructor,
// destructor, static member functions, friend class, this pointer, inline code and dynamic
// memory allocation operators-new and delete as well as exception handling.


#include <iostream>
#include <cstring>

using namespace std;

class Student {
    // Member variables
    char *name;
    int rollNumber;
    string className;
    char division;
    string dob;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;

    // Static member variable
    static int studentCount;

public:
    // Default constructor
    Student() {
        name = new char[30];
        strcpy(name, "Unknown");
        rollNumber = 0;
        className = "Unknown";
        division = 'U';
        dob = "Unknown";
        bloodGroup = "Unknown";
        contactAddress = "Unknown";
        telephoneNumber = "Unknown";
        drivingLicenseNo = "Unknown";
        studentCount++;
    }

    // Parameterized constructor
    Student(const char *name, int rollNumber, string className, char division, string dob,
            string bloodGroup, string contactAddress, string telephoneNumber, string drivingLicenseNo) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->rollNumber = rollNumber;
        this->className = className;
        this->division = division;
        this->dob = dob;
        this->bloodGroup = bloodGroup;
        this->contactAddress = contactAddress;
        this->telephoneNumber = telephoneNumber;
        this->drivingLicenseNo = drivingLicenseNo;
        studentCount++;
    }

    // Copy constructor
    Student(const Student &other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        rollNumber = other.rollNumber;
        className = other.className;
        division = other.division;
        dob = other.dob;
        bloodGroup = other.bloodGroup;
        contactAddress = other.contactAddress;
        telephoneNumber = other.telephoneNumber;
        drivingLicenseNo = other.drivingLicenseNo;
        studentCount++;
    }

    // Destructor
    ~Student() {
        delete[] name;
        studentCount--;
    }

    // Inline function to display student info
    inline void displayInfo() const {
        cout << "\nStudent Information:\n";
        cout << "Name: " << name << "\n";
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Class: " << className << "\n";
        cout << "Division: " << division << "\n";
        cout << "Date of Birth: " << dob << "\n";
        cout << "Blood Group: " << bloodGroup << "\n";
        cout << "Contact Address: " << contactAddress << "\n";
        cout << "Telephone Number: " << telephoneNumber << "\n";
        cout << "Driving License No.: " << drivingLicenseNo << "\n";
    }

    // Friend class to access private members
    friend class Database;

    // Static member function to get student count
    static int getStudentCount() {
        return studentCount;
    }
};

// Initialize static member
int Student::studentCount = 0;

// Database class to manage multiple students
class Database {
    Student *students;
    int studentCapacity;

public:
    // Constructor to initialize the database
    Database(int capacity) {
        studentCapacity = capacity;
        students = new Student[capacity];
    }

    // Destructor to free the allocated memory
    ~Database() {
        delete[] students;
    }

    // Function to add student details
    void addStudent(int index) {
        if (index < 0 || index >= studentCapacity) {

        }
        char name[30];
        int rollNumber;
        string className, dob, bloodGroup, contactAddress, telephoneNumber, drivingLicenseNo;
        char division;

        cout << "Enter details for student " << index + 1 << ":\n";
        cout << "Name: ";
        cin.name;
        cout << "Roll Number: ";
        cin >> rollNumber;
        cout << "Class: ";
        cin >> className;
        cout << "Division: ";
        cin >> division;
        cout << "Date of Birth (dd/mm/yyyy): ";
        cin >> dob;
        cout << "Blood Group: ";
        cin >> bloodGroup;
        cout << "Contact Address: ";
        cin.ignore();
        getline(cin, contactAddress);
        cout << "Telephone Number: ";
        cin >> telephoneNumber;
        cout << "Driving License No.: ";
        cin >> drivingLicenseNo;

        students[index] = Student(name, rollNumber, className, division, dob, bloodGroup, contactAddress, telephoneNumber, drivingLicenseNo);
    }

    // Function to display all students
    void displayAllStudents() const {
        for (int i = 0; i < studentCapacity; ++i) {
            students[i].displayInfo();
        }
    }
};

int main() {
    int capacity;
    cout << "Enter the number of students: ";
    cin >> capacity;

    try {
        Database db(capacity);

        for (int i = 0; i < capacity; ++i) {
            db.addStudent(i);
        }

        cout << "\nDisplaying all student details:\n";
        db.displayAllStudents();
        cout << "\nTotal number of students: " << Student::getStudentCount() << endl;
    }
    catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
