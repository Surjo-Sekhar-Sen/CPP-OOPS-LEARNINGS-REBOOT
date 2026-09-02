#include <iostream>
#include <string>
using namespace std;

class teacher{
    public:
        int id;
        int age;

    teacher(int t_id, int t_age){ // HERE WE GAVE DIFFERENT NAMES TO LOCAL VARIABLES!!
        cout << "Teacher constructor call!!" << endl;
        id = t_id; // SO BEACUSE OF THIS WE DON'T NEED TO USE this POINTER HERE!!
        age = t_age;
    }

    void teaching(){
        cout << this->id << " is teaching" << endl;
        return;
    }

    ~teacher(){
        cout << "Teacher destructor call!!" << endl;
    }
};

class student{
    public:
    int id;
    int age;

    student(int id, int age){ // THE MEMBER VARIABLE OF THE CLASS AND THE LOCAL VARIABLE HERE,
        // BOTH HAVE THE SAME SO HERE WE DO HAVE TO USE this POINTER 
        // TO EXPLICITLEY TELL THE COMPILER WHAT IS WHAT!! 
        cout << "Student constructor call!!" << endl;
        this->id = id; // USED this POINTER!!
        this->age = age;
    }

    void studying(int time){
        cout << this->id << " studied for: " << time << " hours!!" << endl;
        return;
    }

    void bunking(){
        cout << this->id << " is bunking the class!!" << endl;
        return;
    }

    // DID NOT CREATE ANY CORRESPONDING DESTRUCTOR, 
    // SO THE COMPILER CALLS THE DEFAULT BEHIND THE SCENES DESTRUCTOR!!
};

int main(){
    teacher A(1, 30);
    A.teaching();

    student S(1, 15); // WHILE NAMING OBJECTS, REMEMBER TO NOT USE SAME NAMES!!
    student B(2, 16);
    B.studying(2);
    S.bunking();
    return 0;
}