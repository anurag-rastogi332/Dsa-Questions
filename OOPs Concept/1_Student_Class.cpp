#include <iostream>
#include <string>
using namespace std;

class student
{
public:
    // attributes
    int id;
    int age;
    string name;
    int nos;
    int *gpa;

    // constructor parameterised
    student(int id, int age, string name, int nos, float gpa)
    {
        cout << "student default constructor" << endl;
        this->id = id;
        this->age = age;
        this->name = name;
        this->nos = nos;
        this->gpa = new int(gpa);
    }

    // constructor copy
    student(const student &srcobj) // srcobj=>A
    {
        cout << "copy  constructor called" << endl;
        this->id = srcobj.id;
        this->age = srcobj.age;
        this->name = srcobj.name;
        this->nos = srcobj.nos;
    }

    // behaviour / methods /funtions
    void study()
    {
        cout << this->name << " student studying" << endl;
    }

    void sleep()
    {
        cout << this->name << " sleeping" << endl;
    }
    void bunk()
    {
        cout << this->name << " bunking" << endl;
    }
    // destructor
    ~student()
    {
        cout << this->name << "student default destructor" << endl;
        delete this->gpa;
    }
};

int main()
{

    // student A;
    // A.id = 1;
    // A.age = 18;
    // A.name = "krish ";
    // A.nos = 6;
    // A.study();

    // student B;
    // B.id = 2;
    // B.age = 22;
    // B.name = "GTA V ";
    // B.nos = 8;
    // B.bunk();

    // student A(1,15,"krish",6);
    // student B(2,18,"gta ",8);
    // cout << A.name << " " << A.age << endl;
    // A.bunk();
    // B.sleep();

    // copy constructor
    //  student C=A;
    // student C(A);
    // cout << C.name << " " << A.name << endl;

    // dynamic memory allocation
    student *A = new student(1, 14, "krish", 8, 9.8);
    cout << A->name << endl;
    cout << A->age << endl;
    A->study();
    delete A;

    return 0;
}