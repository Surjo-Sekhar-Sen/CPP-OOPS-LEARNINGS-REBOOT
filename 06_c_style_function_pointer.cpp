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
    S1.structfnptr(&S1); // THIS IS MORE LIKE AN EASIER THING OR SYNTACTICAL SUGAR KIND OF SYNTAX!!
    (*(S1.structfnptr))(&S1); // THIS IS THE ACTUAL MAIN ONE -> ALSO IS SAME AND GIVES THE SAME RESULT!!
    // THUS THIS STUFF CAN ALSO BE WWRITTEN AS :->
    (*S1.structfnptr)(&S1); // BECAUSE OF PRECEDENCE THE BRACKET OPERATION WILL HAPPEN FIRST!!
    // SO THE DEREFENCING WILL HAPPEN FIRST AND THEN THE FUNCTION ARGUMENT TYPE OF THING WILL HAPPEN!!


    void (*fnptr)(int) = func;
    (*fnptr)(20); // THIS IS ALSO SIMILAR TO THE FUNCTION POINTER!!
    return 0;
}