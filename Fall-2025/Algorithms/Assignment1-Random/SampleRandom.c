//--------------------------------------------------
// Dr. Art Hanna
// Sample random-related client application program 
// SampleRandom.c
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Random.h"

//--------------------------------------------------
int main()
//--------------------------------------------------
{
   printf("RAND_MAX = %d\n\n",RAND_MAX);

   SetRandomSeed();

   for (int i = 1; i <= 7; i++)
   {
      printf("RandomInt(1,6)        = %d\n",RandomInt(1,6));
      printf("RandomDouble()        = %.2f\n",RandomDouble());
      printf("RandomBool(0.5)       = %s\n",RandomBool(0.5) ? "true" : "false");
      printf("RandomChar(\"ABCDE\",5) = %c\n\n",RandomChar("ABCDE",5));
   }

   return( 0 );
}
