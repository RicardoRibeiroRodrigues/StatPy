#include <stdarg.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>

#include "buildins.h"

extern "C" DECLSPEC int printvalue(int val)
{
   std::cout << "IDEBUG: " << val << "\n";
   return 1;
}

extern "C" DECLSPEC double printdouble(double val)
{
   std::cout << "DDEBUG: " << val << "\n";
   return 1.;
}

extern "C" DECLSPEC void print(char* str, ...)
{
   va_list argp;
   va_start(argp, str);
   vprintf(str, argp);
   va_end(argp);
}

extern "C" DECLSPEC void println(char* str, ...)
{
   char*   outstr;
   va_list argp;
   va_start(argp, str);
   outstr = (char*)malloc(strlen(str) + 2);
   strcpy(outstr, str);
   strcat(outstr, "\n");
   vprintf(outstr, argp);
   va_end(argp);
   free(outstr);
}

extern "C" DECLSPEC double sinus(double val)
{
   return std::sin(val);
}

extern "C" DECLSPEC double cosinus(double val)
{
   return std::cos(val);
}

// Square root of a number
extern "C" DECLSPEC double builtin_sqrt(double val)
{
   return std::sqrt(val);
}

extern "C" DECLSPEC double builtin_pow(double val, double exp)
{
   return std::pow(val, exp);
}

// Get current time in seconds
extern "C" DECLSPEC double builtin_time()
{
   return (double)clock() / CLOCKS_PER_SEC;
}

// Random number from 0 to 1
extern "C" DECLSPEC double builtin_rand()
{
   return (double)rand() / RAND_MAX;
}

// Double to int
extern "C" DECLSPEC int builtin_double_to_int(double val)
{
   return (int)val;
}

// Int to double
extern "C" DECLSPEC double builtin_int_to_double(int val)
{
   return (double)val;
}
