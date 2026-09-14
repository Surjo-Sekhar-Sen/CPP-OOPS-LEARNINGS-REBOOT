#include <iostream>
#include <string>
using namespace std;

class Student{
    public:
        string name;
        int id;
        int age;

        void study(int time){
            cout << this->name << " studied for: " << time << " hours!!" << endl;
            return;
        }

        void funcaddress(){
            cout << &Student::study << endl;
            return;
        }

    Student(int id, int age, string name){
        cout << "Student constructor call!!" << endl;
        this->id = id;
        this->age = age;
        this->name = name;
    }

    ~Student(){
        cout << "Student destructor call!!" << endl;
    }
};

int main(){
    Student A(1, 21, "Surjo");
    Student B(2, 21, "Sekhar");
    cout << &A.id << " " << &A.age << " " << &A.name << endl; // GIVES THE ACTUAL ADDRESS OF THE VALUE
    // INSIDE THE OBJECT'S ADDRESS!!

    cout << &Student::id << endl; // GIVES THE OFFSET VALUE FROM THE BLUEPRINT OF THE CLASS!!
    int Student::*ptr = &Student::id; // SAVING THE OFFSET ADDRESS TYPE WHICH USUALLY COMES AS AN INT VALUE!!
    cout << A.*ptr << endl; // GIVES THE ADDRESS AS IT BASICALLY ADDS THE INITIAL ADDRESS OF A'S BASE ADDRESS
    // TO THE OFFSET ADDRESS!!

    cout << &Student::study << endl; // GIVES THE ADDRESS OF THE study FUNCTION IN THE CODE SEGMENT OF RAM!! 
    cout << &Student::funcaddress << endl;
    void (Student::*funcptr)() = &Student::funcaddress;

    A.study(2);
    B.study(3);
    A.funcaddress();
    B.funcaddress();

    (A.*funcptr)();
    return 0;
}