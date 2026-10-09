#include <iostream>
using namespace std;

class Student{ 
    public:
        int id = 0; // WITH DEFAULT VALUE!!
        string name = "Unknown";

        Student() = default;
        Student(int id){ // PARAMETERISED CONSTRUCTOR!!
            this->id = id;
        };
};

class Teacher{
    public:
        int id;
        const string& name;
        
        // MEMBER INITIALISER LIST CONSTRUCTOR (BEST WAY!!)
        Teacher(int id, string& naam) : id(id), name(naam) {};

        void print(){
            cout << "Teacher id: " << this->id << " and name is: " << this->name << endl;;
        }
};

class principal{
    public:
    // MEMBER INITIALISER IS BEST FOR  CASES WITH CONSTANT AND REFERENCE VARIABLES!!
    // BECAUSE IT DOES MEMORY ALLOCATION AND BINDING OF VALUE IN A SINGLE PHASE!!
        const int id;
        string& name;

        principal(int id, string& naam) : id(id), name(naam) {};

        void print(){
            cout << "Principal id: " << this->id << " and name is: " << this->name << endl;;
        }
};

int main(){
    Student S1;
    cout << S1.id << " " << S1.name << endl;
    
    Student S2(1);
    cout << S2.id << " " << S2.name << endl;

    string tename = "Surjo";
    Teacher T1(1, tename); // HERE YOU CANNOT DIRECTLY WRITE "Surjo" BECAUSE THIS MEANS YOU ARE GIVING
    // A TEMPORARY VALUE TO IT AND A REFERENCE VARIABLE CANNOT BE POINTED TO A TEMPORARY RVALUE!!
    T1.print();

    string prname = "Turaif";
    principal P1(10, prname);
    P1.print();
    prname = "Adeal";
    P1.print();

    return 0;
}