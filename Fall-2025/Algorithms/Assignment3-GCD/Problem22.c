// Dr. Art Hanna
// Problem #22
// Problem22.c
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <assert.h>
#include <math.h>

#define MAXFACTORS 512

// Commented-out in lieu of using <stdbool.h> definition of the bool data type
// typedef enum { false = 0,true = 1 } boolean;

typedef struct FACTORIZATION
{
int size;
int factor[MAXFACTORS+1];
int exponent[MAXFACTORS+1];
} FACTORIZATION;

//--------------------------------------------------
int main()
//--------------------------------------------------
{
  int GCD1(int m,int n);
  int GCD2(const int m,const int n);
  int GCD3(const int m,const int n);
  int GCD4(const int m,const int n);

  int m,n;

  printf("m? ");
  while ( scanf("%d",&m) != EOF )
  {
    printf("n? "); scanf("%d",&n);

    assert( (m >= 0) && (n >= 0) );

    printf("GCD1(m,n) = %d\n",GCD1(m,n));
    printf("GCD2(m,n) = %d\n",GCD2(m,n));
    printf("GCD3(m,n) = %d\n",GCD3(m,n));
    printf("GCD4(m,n) = %d\n",GCD4(m,n));
    printf("m? ");
  }

  return( 0 );
}

//--------------------------------------------------
int GCD1(int m,int n)   // my code
//--------------------------------------------------
{
  assert(m != 0 || n != 0);

  int r;
  while(n != 0) {
    r = m % n;
    m = n;
    n = r;
  }
  return m;
}

//--------------------------------------------------
int GCD2(const int m,const int n)   // my code
//--------------------------------------------------
{
  assert(m != 0 && n != 0);

  int t = (m < n)? m : n;

  while(m % t != 0 || n % t != 0) {
    t--;
  }
  return t;
}

//--------------------------------------------------
int GCD3(const int m,const int n)
//--------------------------------------------------
{
  void FindFactorization(int x,FACTORIZATION *factorization);
  void DisplayFactorization(const int x,const FACTORIZATION factorization);

  FACTORIZATION mFactorization;
  FACTORIZATION nFactorization;
  int p,mi,ni;

  // You should ensure the pre-condition ((m  0) and (n  0)) is satisfied
  // using an assertion (see *FYI #11*).
  assert(m != 0 && n != 0);

  // Step 1.
  FindFactorization(m,&mFactorization);
  DisplayFactorization(m,mFactorization);
  // Step 2.
  FindFactorization(n,&nFactorization);
  DisplayFactorization(n,nFactorization);

  // Steps 3 and 4.  // my code
  int result = 1;
  // can skip i = 0 since all will be 1, which does not affect multiplication
  for(mi = 1; mi < mFactorization.size; mi++) {
    for(ni = 1; ni < nFactorization.size; ni++) {
      // common factor found
      if(mFactorization.factor[mi] == nFactorization.factor[ni]) {
        // min(pm, pn)
        if(mFactorization.exponent[mi] < nFactorization.exponent[ni]) {
          p = mFactorization.exponent[mi];
        } else {
          p = nFactorization.exponent[ni];
        }
        result *= pow(mFactorization.factor[mi], p);
      }
    }
  }
  return result;
}

//--------------------------------------------------
void FindFactorization(int x, FACTORIZATION *factorization)   // my code
//--------------------------------------------------
{
  int NextPrime(int x);

  int i = 0;  // initialize iterator for factorization
  int current_prime_factor = 2;  // initialize prime factors (starting at 2)

  // initialize factorization to index 0 = 1
  factorization->size = 1;
  factorization->factor[i] = 1;
  factorization->exponent[i] = 1;


  while(x > 1) {
    if(x % current_prime_factor != 0) {
      current_prime_factor = NextPrime(current_prime_factor);
    } else {
      // if new factor
      if(factorization->factor[i] != current_prime_factor) {
        i++;  // next factor index
        factorization->size++;  // added a new factor -> size increment
        factorization->factor[i] = current_prime_factor;
        factorization->exponent[i] = 0;
      }
      // increment current exponent and divide while x is divisible by current factor
      factorization->exponent[i]++;
      x = x / current_prime_factor;
    }
  }
}

//--------------------------------------------------
void DisplayFactorization(const int x,const FACTORIZATION factorization)
//--------------------------------------------------
{
  printf("%d = ",x);
  for (int i = 0; i < factorization.size; i++)
  {
    printf("%d",factorization.factor[i]);
    if ( factorization.exponent[i] > 1 )
      printf("^%d",factorization.exponent[i]);
    printf(" ");
    if ( i < factorization.size - 1 )
      printf("* ");
    else
      printf("\n");
  }
}

//--------------------------------------------------
int NextPrime(int x)
//--------------------------------------------------
{
  bool IsPrime(const int x);

  do
    x++;
  while ( !IsPrime(x) );
  return( x );
}

//--------------------------------------------------
bool IsPrime(const int x)
//--------------------------------------------------
{
  bool r = true;

  for (int i = 2; (i <= (int)sqrt(x)) && r; i++)
    r = r && ((x % i) != 0);
  return( r );
}

//--------------------------------------------------
int GCD4(const int m,const int n)   // my code
//--------------------------------------------------
{
  assert(m != 0 || n != 0);

  if(n == 0) {
    return m;
  } else {
    GCD4(n, m % n);
  }
}
