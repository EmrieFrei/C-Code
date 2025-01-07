#include<stdio.h>
#include<stdlib.h>
#include "lab4test.h"

int variable1;
int main(void){
    variable1 = 0;
    int i = 100;
    for (int i = 0; i < 8; i++){
        printf("The value of variable1 is: %d\n", variable1);
        variable1++;
    }

    i = test1(variable1);

    return EXIT_SUCCESS;
}

/*
QUESTION 1:
The scope of the variable named 'variable1' is the entire file. Since it is
outside of the function definition it is a global variable.

QUESTION 2:
No they are not the same variable. In each program the variable is defined 
on its own this means that they are separate variables.

QUESTION 3:
No since they are not the same variable, if one is affected, the other one
will not be affected.

QUESTION 4:
There are two variables named 'i'. The first one is on line 8 which has the
scope of the entire function named 'main' and the other one is exclusively 
inside the for loop. The first 'i' is hidden once the for loop begins.

QUESTION 5:
There is only one distinct variable named 'variable1' which has the scope of
the entire function.

QUESTION 6: 
No they are not the same variable since they are separately defined in both
functions.
*/