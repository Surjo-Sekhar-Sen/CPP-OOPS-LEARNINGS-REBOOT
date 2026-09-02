#include <iostream>
#include <string>
using namespace std;

class student{
    public:
        int id;
        int *age;
        
        student(int s_id, int age){
            cout << "Student constructor call!!" << endl;
            id = s_id;
            this->age = new int(age);
        }

        ~student(){ // IN THIS CASE WE DEFINITELY NEED DESTRUCTOR TO BE CALLED!!
            // DEFAULT DESTRUCTOR WILL ONLY REMOVE THE OBJECT FROM THE MEMORY,
            // THE age POINTER POINTS TO HEAP MEMORY ADDRESS AND THAT MEMORY ADDRESS NEEDS TO BE DELETED TOO!!
            cout << "Student destructor call!!" << endl;
            delete age;
        }
};

int main(){

    student A(1, 21);
    student B(2, 22);
    return 0;
}