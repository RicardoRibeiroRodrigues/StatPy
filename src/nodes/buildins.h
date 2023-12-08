#pragma once

#if defined(_MSC_VER)
#define DECLSPEC __declspec(dllexport) 
#else
#define DECLSPEC 
#endif

/*
 *! some helper/debug function
 */


/*! Prints an integer value.
 * \param[in] val Integer value to be printed.
 * \return Always one FIXME
 */
extern "C" DECLSPEC int printvalue( int val );

/*! Prints a double value.
 * \param[in] val Double value to be printed.
 * \return Always one FIXME
 */
extern "C" DECLSPEC double printdouble(double val);

/*! Built in print function
 * it works like the C printf function and uses the same format string definition.
 * \param[in] str  The format string.
 */
extern "C" DECLSPEC void print(char* str, ...);

/*! Prints formated string like printf but with a cr/lf
 * \param[in] str  The format string.
 */
extern "C" DECLSPEC void println(char* str, ...);

/*! Calculates a sinus.
 */
extern "C" DECLSPEC double sinus(double val);

/*! Calculates a cosinus.
 */
extern "C" DECLSPEC double cosinus(double val);

/*! Calculates a square root.
 */
extern "C" DECLSPEC double builtin_sqrt(double val);

/*! Calculates a power.
 */
extern "C" DECLSPEC double builtin_pow(double val, double exp);

// Get current time in seconds
extern "C" DECLSPEC double builtin_time();

// Get random number
extern "C" DECLSPEC double builtin_rand();

extern "C" DECLSPEC int builtin_double_to_int(double val);

extern "C" DECLSPEC double builtin_int_to_double(int val);