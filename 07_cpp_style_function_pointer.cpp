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

        // Student::print(); // ALL THESE THINGS ARE NOT ALLOWED AS INSIDE A CLASS 
        // WE CAN ONLY DECLARE FUNCTIONS, VARIABLES; BUT NOT CALL A FUNCTION OR VALUE OR SO!!
        // &Student::print();
        // &Student::print;

        void study(){
            auto val = Student::print;
            cout << val << endl;
            print(); // NO ERROR WHILE CALLING INSIDE A FUNCTION OR ASKING FOR AN ADDRESS!!
            Student::print(); // GIVES SAME RESULT LIKE print()!! WE JUST EXPLICITELY TOLD THE COMPILER
            // THAT IT IS INSIDE THE Student SCOPE!!
            &Student::print(); // THIS CREATES A PROBLEM!!
            return;
        }
};

// REGULAR EXTERNAL FUNCTION!!
void ageadd(Student* s,int val){
    cout << "After 2 years " << s-> name << " will be of " << (s->age + 2) << " years!!" << endl; 
    return;
}