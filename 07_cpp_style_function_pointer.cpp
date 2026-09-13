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

        void (Student::*classmemfnptr)() = &Student::print;

        // Student::print(); // ALL THESE THINGS ARE NOT ALLOWED AS INSIDE A CLASS 
        // WE CAN ONLY DECLARE FUNCTIONS, VARIABLES; BUT NOT CALL A FUNCTION OR VALUE OR SO!!
        // &Student::print();
        // &Student::print;

        void study(){
            auto val = &Student::print;
            cout << val << endl;
            print(); // NO ERROR WHILE CALLING INSIDE A FUNCTION OR ASKING FOR AN ADDRESS!!
            Student::print(); // GIVES SAME RESULT LIKE print()!! WE JUST EXPLICITELY TOLD THE COMPILER
            // THAT IT IS INSIDE THE Student SCOPE!!
            // &Student::print(); // THIS CREATES A PROBLEM!! THIS IS NOT ALLOWED AS WHEN YOU WRITE &Student::print
            // THIS PART GETS INTERPRETED AS A POINTER TO MEMBER ADDRESS AND THEN YOU PUT () WHICH MAKES IT WORSE 
            // AS IT DOES NOT MAKE ANY SENSE BECAUSE THE ADDRESS ISN'T STORED ANYWHERE TO BE ACCESSED AND THEN DEREFERENCED 
            // AND THEN FUNCTION CALL!!
            return;
        }
};

// REGULAR EXTERNAL FUNCTION!!
void ageadd(Student* s,int val){
    cout << "After 2 years " << s-> name << " will be of " << (s->age + 2) << " years!!" << endl; 
    return;
}

int main(){
    Student S1;
    S1.age = 21;
    S1.id = 1;
    S1.name = "Surjo";
    S1.print(); // DIRECT CALL TO MEMBER FUNCTION!!

    // (*(S1.classmemfnptr))();
    // THIS GIVES ERROR AS THIS S1.classmemfnptr IS ACTUALLY AN ADDRESS RIGHT!!
    // AND IN C++ FOR GOING INSIDE THE OBJECT'S MEMBER AS THE POINTER VARIABLE WHICH STORES THIS ADDRESS 
    // IS A VARIABLE, SO WE NEED TO WRITE S1.*S1.classmemfnptr -> THIS MEANS S1. GOING INSIDE S1 
    // THEN INSIDE THAT WE DEREFERNCE THE ADDRESS STORED IN THE S1.classmemfnptr VALUE!!

    // S1.(*S1.classmemfnptr)(); // THIS IS WRONG AS () HAS MORE PRECEDNECE!! 
    // S1.study() WHENEVER IS WRITTEN, THIS GETS CHANGED TO Student::study(&S1) RIGHT!!
    // SO ULTIMATELY THE ADDRESS IS PASSED AS AN ARGUMENT TO THE ADDRESS OF study FUNCTION RIGHT??
    // THIS IS WHY WE BASICALLY NEED TO FIRST BIND THE OBJECT AND THE POINTER VARIABLE TOGETHER 
    // BEFORE PASSING THE FUNCTION CALL!! 
    // S1.*S1.classmemfnptr(); // WRONG TOO!!
    (S1.*S1.classmemfnptr)(); // THIS IS CORRECT AS S1 .* S1.classmemfnptr GETS BROKEN 
    // AND .* MEANS POINTER TO THE MEMBER, SO THE DEREFERENCING OF THE ADDRESS IS DONE THEN INSIDE THE 
    // OBJECT'S REFERENCE WE GO THEN WE CALL THE FUNCTION ACCORDING TO THE OBJECT REFERENCE RIGHT!!

    void (*fnaddptr)(Student*, int) = ageadd;

    (*fnaddptr)(&S1, 20);

    S1.study();
    return 0;
}