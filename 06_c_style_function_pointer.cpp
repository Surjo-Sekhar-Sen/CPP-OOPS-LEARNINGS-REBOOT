#include <iostream>
#include <cstdio>
using namespace std;

typedef struct Student{
    int id;
    int age;
    void (*structfnptr)(Student*);
}Student;

void print(Student* S){
    printf("Student's id is: %d and age is: %d!!\n", S->id, S->age);
    return;
}

void func(int x){
    printf("%d x %d is: %d\n", 2, x, 2*x);
    return;
}

int main(){
    Student S1;
    S1.id = 1;
    S1.age = 21;
    S1.structfnptr = print; // WRITING print PASSES THE ADDRESS OF THE FUNCTION!!
    // USUALLY WRITING print() RETURNS THE VALUE, BUT WRITING print MEANS RESTURNING THE ADDRESS!!
    // OR BASICALLY IT MEANS A POINTER TO THE FUNCTION!!
    S1.structfnptr(&S1);

    void (*fnptr)(int) = func;
    (*fnptr)(20); // THIS IS ALSO SIMILAR TO THE FUNCTION POINTER!!
    return 0;
}