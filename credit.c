#include <stdio.h>
#include <cs50.h>
#include <math.h>

/* Credit CS50 Project
   by James Meehan */

int main(void)
{
    // prompt user for CC number//
    long long CC_number, i;
    int sumproduct, sum;
    do
    {
    printf("Number: ");
    CC_number = get_long_long();
    } while (CC_number < 0);
  
 
  //Double every other digit starting with the second to last //
  //Sum each individual digit of the products//
  for (i=CC_number/10, sumproduct=0; i > 0; i /= 100)
  {
     if ( 2 * (i % 10) > 9)
    {
     sumproduct += (2 * (i % 10))/10;
     sumproduct += ((2 * (i % 10)) % 10);
    }
    else 
    sumproduct += (2 * (i % 10));
  }

  //Sum every other digit starting with the last//
  for (i=CC_number, sum=0; i > 0; i /= 100)
  {
     sum = sum + (i % 10);
  }
 
 //Check to make sure CC is valid according to Luhn's algorith, has the appropriate digits, and is in the appropriate range//
 //Determine if CC is AMEX, MASTERCARD, VISA, or INVALID//
  int digits = ((floor(log10(CC_number)))+1);
  double x = CC_number/(pow(10, digits-1));
  int x2 = x;
  
  if ((sum + sumproduct) % 10 != 0 || (digits) == 14 || (digits) < 13 || (digits) > 16)  
  {
      printf("INVALID\n");
  }
  else if (digits == 15 && ((CC_number >= 340000000000000 && CC_number < 350000000000000) || (CC_number >= 370000000000000 && CC_number <380000000000000)))
  {
      printf("AMEX\n");
  }
  else if (digits == 16 && CC_number >= 5100000000000000 && CC_number < 5600000000000000)
  {
      printf("MASTERCARD\n");
  }
  else if ((digits == 13 || digits == 16) && (x2==4))
  {
     printf("VISA\n");
  }
  else
     printf("INVALID\n");
}
