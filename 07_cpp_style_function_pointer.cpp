#include <iostream>
#include <string>
using namespace std;

class Student{
    public:
        string name;
        int id;
        int age;

        // CLASS MEMBER FUNCTION!!
        void print(){
            cout << "Student's id is: " << this->id << " and age is: " << this->age << endl;
            cout << "Student's name is: " << this->name << endl;
            return;
        }

        &Student::print();

        void study(){
            print();
        }
};

// REGULAR EXTERNAL FUNCTION!!
void ageadd(Student* s,int val){
    cout << "After 2 years " << s-> name << " will be of " << (s->age + 2) << " years!!" << endl; 
    return;
}