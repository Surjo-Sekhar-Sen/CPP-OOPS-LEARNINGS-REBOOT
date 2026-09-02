#include <iostream>
#include <string>
using namespace std;

class Student{
    public:
        int id;
        int age;
        string name;
        int backlogs;

        void study(){ // FUNCTIONS WHEN ALLOCATED OR MADE ONLY TAKES A SINGLE SPACE OR COPY!!
            cout << this->name << " " <<  this->id << " " << this->age <<" studying!!" << endl;
            return;
        }

        void bunk(){
            cout << this->name << " " << this->id << " " << this->age <<" bunking!!" << endl;
            return;
        }

        // THIS IS DEFAULT CONSTRUCTOR!! WE CAN MAKE CHANGES IN IT ACCORDING TO OUR WISH!!
        Student(){
            cout << this->id << "Default constructor call!!" << endl; // WEIRD BEHAVIOUR OF id!!
            id = 0; // DOING THIS WON'T CHANGE ANYTHING USUALLY AS THERE IS NO EXTRA LOCAL VARIABLE ALLOCATION!!
            age = 0; // MAKING this->id WORKS WHEN THE MEMBER VALUE IS SIMILAR TO THE LOCAL VARIABLE!!
            name = "Unknown";
            backlogs = 0;
            cout << this->id << "Default constructor call!!" << endl; // WEIRD BEHAVIOUR OF id!!

        }

        // WITH A DEFAULT CONSTRUCTOR, THERE MUST BE A DESTRUCTOR!!
        ~Student(){
            cout << this-> id << "Default destructor call!!" << endl;
        }
};

int main(){
    Student A; // THIS CALLS THE CONSTRUCTOR!!
    A.id = 1; // THE DEFAULT VALUE WAS 0, AND HERE WE UPDATED IT TO 1!!
    cout << A.id << " " << A.name << endl;
    // name WILL BE "unknown", AS IT WAS NOT UPDATED!!

    Student B;
    B.name = "Surjo";
    B.id = 2;
    B.study();
    return 0; // THIS CALLS THE DESTRUCTOR, THE VALUES ARE FILLED IN A STACK IN A BUCKET FORM!!
    // SO THE DESTRUCTION OF THE LATER CREATED CLASS WILL HAPPEN FIRST -> LIFO (LAST IN FIRST OUT)!!
}