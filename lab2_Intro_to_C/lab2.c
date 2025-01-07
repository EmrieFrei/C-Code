//SYSC 2006 - Lab 2 Solution template

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include the necessary header for _Bool
#include "lab2.h"

/* Replace these lines with your information */ 
  const char* author = "Emrie Frei"; 
  const char* student_number = "101297809"; 

// Type your solution to exercise 1 inside the body of the function. You need to update the return statement
int alarm_clock(int day, _Bool vacation){
  if ((day == 0 || day == 6) && vacation == false){
    return 10;
  }
  else if ((day != 0 && day != 6) && vacation == false) {
    return 7;
  } 
  else if ((day == 0 || day == 6) && vacation == true) {
    return -1;
  }
  else if ((day != 0 && day != 6) && vacation == true) {
    return 10;
  }
}
// Type your solution to exercise 2 inside the body of the function.
void count_replace(int value){
  for (int i = 1; i <= value; i++){
    if (i % 3 == 0 && i % 5 == 0){
      printf("%s", "FizzBuzz ");
    }
    else if (i % 3 == 0) {
      printf("%s", "Fizz ");
    }
    else if (i % 5 == 0){
      printf("%s", "Buzz ");
    }
    else {
      printf("%i ", i);

    }
  }
}
// Type your solution to exercise 3 inside the body of the function. You need to update the return statement
_Bool is_prime(int value){
  if (value > 0) {
    if (value < 2){
      return (false);
    }
    for (int i = 2; i <= value; i++){
      if (value % i == 0){
        return (false);
      }
      else {
        return (true);
      }
    }
  }
}
// Type your solution to exercise 4 inside the body of the function. You need to update the return statement

int sum_even(int value){
  int x = 0;
  for (int i = 0; i <= value; i += 2) {
    x += i;
  }
  return(x);
}

