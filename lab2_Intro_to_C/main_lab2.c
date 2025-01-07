//SYSC 2006 - Lab 2 Template

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include the necessary header for _Bool
#include "lab2.h"

/* Replace these lines with your information */ 
  const char* author_main = "Emrie Frei"; 
  const char* student_number_main = "101297809"; 

int main(void){
  // Tests exercise 1 - Complete for a comprehensive test harness
  int expected_week_non_vac = 7;
  for(int day = 1; day <=5; day++){
    int alarm_time = alarm_clock(day, false);
    if (alarm_time == expected_week_non_vac) {
      printf("\nDay %d, Non vacation: TEST PASS.\n", day);
    } else {
      printf("\nDay %d, Non vacation: TEST FAIL.\n", day);
    } 
  }
  
  int expected_week_vac = 10;
  for(int day = 1; day <= 5; day ++){
    int alarm = alarm_clock(day, true);
    if (alarm == expected_week_vac){
      printf("\nDay %d, Vacation: TEST PASS.\n", day);
    } else {
      printf("\nDay %d, Vacation: TEST FAIL. \n", day);
    }
  }

  int expected_weekend_non_vac = 10;
  for(int day = 0; day <= 6; day += 6){
    int alarm = alarm_clock(day, false);
      if (alarm == expected_weekend_non_vac){
        printf("\nDay %d, Weekend Non Vacation: TEST PASS. \n", day);
      } else {
        printf("\nDay %d, Weekend Non Vacation: TEST FAIL. \n", day);
      }
    }

  int expected_weekend_vac = -1;
  for(int day = 0; day <= 6; day += 6){
    int alarm = alarm_clock(day, true);
    if (alarm == expected_weekend_vac){
      printf("\nDay %d, Weekend Vacation: TEST PASS. \n", day);
    } else {
      printf("\nDay %d, Weekend Vacation: TEST FAIL. \n", day);
    }
  }
  

  // Type your test cases for exercise 2. Make sure to include border line cases
  printf("\n Expected Result:\n%s \n", "1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16");
  count_replace(16);

  printf("\n Expected Result:\n%s \n", "1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11");
  count_replace(11);

  printf("\n Expected Result:\n%s \n", "1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz Fizz 22 23 Fizz Buzz 26 Fizz 28 29 FizzBuzz");
  count_replace(30);

  printf("\n Expected Result:\n%s \n", "1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz Fizz 22 23 Fizz");
  count_replace(24);

  // Type your test cases for exercise 3. Make sure to include border line cases
  bool is_prime_test1 = false;
  if (is_prime(10) == is_prime_test1){
    printf("\nPrime: TEST PASS\n");
  } else {
    printf("\nPrime: TEST FAIL\n");
  }

  bool is_prime_test2 = true;
  if (is_prime(13) == is_prime_test2){
    printf("\nPrime: TEST PASS\n");
  } else {
    printf("\nPrime: TEST FAIL\n");
  }

  bool is_prime_test3 = false;
  if (is_prime(60) == is_prime_test3){
    printf("\nPrime: TEST PASS\n");
  } else {
    printf("\nPrime: TEST FAIL\n");
  }

  bool is_prime_test4 = true;
  if (is_prime(83) == is_prime_test4){
    printf("\nPrime: TEST PASS\n");
  } else {
    printf("\nPrime: TEST FAIL\n");
  }

  // Type your test cases for exercise 4. Make sure to include border line cases
  int sum_even_test1 = 30;
  if (sum_even(10) == sum_even_test1){
    printf("\nSum Even: TEST PASS\n");
  } else {
    printf("\nSum Even: TEST FAIL\n");
  }
  
  int sum_even_test2 = 30;
  if (sum_even(11) == sum_even_test2){
    printf("\nSum Even: TEST PASS\n");
  } else {
    printf("\nSum Even: TEST FAIL\n");
  }

  int sum_even_test3 = 156;
  if (sum_even(24) == sum_even_test3){
    printf("\nSum Even: TEST PASS\n");
  } else {
    printf("\nSum Even: TEST FAIL\n");
  }

  int sum_even_test4 = 0;
  if (sum_even(0) == sum_even_test4){
    printf("\nSum Even: TEST PASS\n");
  } else {
    printf("\nSum Even: TEST FAIL\n");
  }

  printf("\nTest harness finished\n");
  return EXIT_SUCCESS;
}


