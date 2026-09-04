#include <iostream>
#include <cstdio>
using namespace std;

struct Student{
    int id;
    int age; // WE CAN WRITE AND CREATE Structures USING struct KEYWORD!!
    // THIS IS SIMALR TO class BUT VERY VERY DIFFERENT!!
    // IN structures WE ARE NOT ALLOWED TO CREATE MEMBER FUNCTIONS!! <- IMPORTANT!!
    // IN structures WE CAN MAKE USE OF MEMEBER VARIABLES ONLY, AND THEY ALL ARE ACCESSIBLE FROM ANYWHERE!!
    // THEY ARE ALL PUBLIC!!
    // Student IS NOT A TYPE, INSTEAD struct Student IS CONSIDERED A TYPE!! <- IMPORTANT!!
};

// IF WE WANT TO USE THE MEMBER VARIABLES OF THE STRUCTURE, WE NEED TO PASS THE ADDRESS OF THE STRUCTURE!!
// AND ALSO SINCE THERE IS NO AUTOMATIC this POINTER WHICH PASSES THE OBJECT'S REFERENCE, WE NEED TO PASS 
// A PARAMETER OF THE TYPE WITH ITS ADDRESS OR REFERENCE TO MAKE IT WORK!!

void printstud(struct Student* S){ //struct Student IS A TYPE, INSTEAD OF Student!!
    printf("Student's id is: %d and age is: %d!!\n", S->id, S->age);
    // S->id MEANS S IS A POINTER THAT GETS THE ADDRESS OF THE STRUCTURE WE PASS AS AN ARGUMENT!!
    // AND SINCE IT IS A POINTER TO THE OBJECT/STRUCTURE WE CANNOT ACCESS THE VARIABLES USING (.) OPERATOR!!
    return;
}

typedef struct Teacher{ // HERE USING typedef ALLOWED US TO CREATE A TYPE WITH THE NAME Teacher;
    int id;
    int age;
} Teacher; // WE HAVE TO WRITE THE TYPE NAME HERE!!
// WELL THE MODERN C++ COMPILERS CAN AUTOMATICALLY DETECT STRUCTURES AND TYPES NOWADAYS!!
// SO PUTTING typedef IS AN EXTRA ELEMENT WE PUT HERE!!

void printteach(Teacher* T){
    printf("Teacher's id is: %d and age is: %d!!\n", T->id, T->age);
}

int main(){
    struct Student S1;
    S1.id = 1;
    S1.age = 20;
    printstud(&S1); // WE PASSED THE ADDRESS AND SINCE WE CANNOT DECLARE ANY FUNCTION INSIDE THE STRUCTURE,
    // IT BECOMES UNREALISTIC!!

    struct Student S2;
    S2.id = 2;
    S2.age = 21;
    printstud(&S2);

    Teacher T1;
    T1.id = 1;
    T1.age = 40;
    printteach(&T1);

    Teacher T2;
    T2.id = 2;
    T2.age = 45;
    printteach(&T2);
    return 0;
}