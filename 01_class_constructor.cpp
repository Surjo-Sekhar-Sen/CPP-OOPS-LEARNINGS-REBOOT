#include <iostream>
#include <string>
using namespace std;

class Student{
    // ATRIBUTES/ DATA

    // IF YOU WRITE IT LIKE THIS!! THEN IT WON'T BE ACCESSIBLE IN main!!
    // AS BY DEFAULT THE access specifier FIX THESE TO private!!
    // ALSO FOR THE FUNCTIONS/ BEHAVIOUR YOU WRITE!!
    // int id; 
    // int age;
    // string name;
    // int backlogs;

    public:
        int id;
        int age;
        string name;
        int backlogs;

        // BEHAVIOUR/ METHODS/ FUNCTIONS
        void study(){
            cout << this->name << " " << this->id << " " << this->age <<" studying!!" << endl; //this IS A NECESSARY KEYWORD AND ACTS 
            // AS A POINTER TO THE CURRENT OBJECT'S ATTRIBUTE OR VALUE!!
            return;
        }

        void sleep(){
            cout << this->name << " " <<  this->id << " " << this->age <<" sleeping!!" << endl;
            return;
        }

        void bunk(){
            cout << this->name << " " << this->id << " " << this->age <<" bunking!!" << endl;
            return;
        }

    // EVEN IF WE DON'T WRITE CONSTRUCTOR AND DESTRUCTOR OURSELVES,
    // IT WILL BE DONE ITSELF IN THE BACKGROUND!!
};

int main(){
    Student S1;
    S1.id = 1;
    S1.name = "Surjo";
    S1.age = 21;
    S1.backlogs = 0;

    S1.study();

    Student S2;
    S2.id = 2;
    S2.sleep(); // IF YOU DON'T PUT A VALUE TO THE int VALUE IT GIVES 0 AS DEFAULT!!
    // AND FOR STRING IT RETURNS EMPTY OR NULL!!
    // WELL WRONG!! -> THIS IS TOTALLY NOT A DEFAULT VALUE..IT ACTUALLY RETURNS A GARBAGE VALUE FOR INT TYPES
    // AND EMPTY STRING "" FOR STRINGS!!
    return 0;
}