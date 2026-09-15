#include <iostream>
#include <cstdio>
#include <cstring>
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

        void (Student::*classptr)(int) = &Student::study;

        void funcaddress(){
            unsigned long long value;
            memcpy(&value, &(this->classptr), sizeof(value));
            printf("Address of the study function through class function is: 0x%llx\n", value);
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
    // WELL IT DOESN'T GIVE THE OFFSET VALUE INSTEAD GIVES A BOOLEAN VALUE OF TRUE OR 1 !!
    // THIS MAINLY HAPPENS BECAUSE THE COUT CANNOT PRINT THIS ADDRESS!!
    // USUALLY THE MEMBER FUNCTION'S ADDRESS OF A CLASS IS NOT 8 BYTE ADDRESS INSTEAD CONTAINS META DATA ABOUT THE CLASS
    // AND VIRTUAL DEFINITION AND ELSE WHICH MAKES IT'S ADDRESS OF 16 BYTES!!
    // THIS NORMALLY CANNOT BE PRINTED BY COUT!!

    // FOR THIS TO ACTUALLY PRINT THE REAL VALUE WE DESIRE LIKE THE MAIN ADDRESS VALUE:
    // WE NEED TO USE REINTERPRET_CAST FOR CHANGING THIS ADDRESS TO SOME POINTER ADDRESS VALUE!!

    int Student::*ptr = &Student::id; // SAVING THE OFFSET ADDRESS TYPE WHICH USUALLY COMES AS AN INT VALUE!!
    cout << A.*ptr << endl; // GIVES THE VALUE AT THE ADDRESS THAT IS LIKE ADDED TO THE BASE ADDRESS OF A AND THEN THE
    // OFFSET ADDRESS IS ADDED!!
    cout << &(A.*ptr) << endl; // GIVES THE ADDRESS!!

    cout << &Student::study << endl; // GIVES THE ADDRESS OF THE study FUNCTION IN THE CODE SEGMENT OF RAM!! 
    // SAME CASE HERE TOO JUST PRINTS 1 AS IT BASICALLY MEANS THERE IS SOMETHING IN THIS ADDRESS SO IN BOOLEAN VALUE
    // IT CONVERTS TO 1!!
    cout << &Student::funcaddress << endl;
    // HERE FOR THE MEMBER FUNCTION ADDRESS WE CAN USE MEMCPY AND USE NORMAL PRINTF STATEMENT!!
    // INSTEAD OF USING COUT!!

    void (Student::*testptr)(int) = &Student::study;
    unsigned long long address; // THIS CONTAINS UNSIGNED INT VALUE OF 8 BYTES!!
    memcpy(&address, &testptr, sizeof(address));
    printf("Address of the study function is: 0x%llx\n", address);

    void (Student::*funcptr)() = &Student::funcaddress;

    A.study(2);
    B.study(3);
    A.funcaddress(); // GIVES THE SAME ADDRESS!!
    B.funcaddress(); // GIVES THE SAME ADDRESS AS THE FUNCTION IS ACTUALLY STORED AS A SINGLE COPY IN RAM!!
    (A.*funcptr)(); // JUST ANOTHER WAY OF DOING THE SAME THING!!

    return 0;
}