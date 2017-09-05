/**
 * File:            factorial.h
 * Namespace:       z::math
 *
 * Description:     A simple function that returns the
 *                  factorial of the given input as an
 *                  (unsigned long long).
 *                  Note that this function is only
 *                  accurate to factorial(64).
 *
 *                  This function will return 0 if the
 *                  given input is negative or out of
 *                  the accurate range.
 *
 *
 * Author:          Zachary Westerman
 * Email:           zacharywesterman@yahoo.com
 * Last modified:   19 Jul. 2017
**/

#pragma once
#ifndef FACTORIAL_H_INCLUDED
#define FACTORIAL_H_INCLUDED

#include <cmath>

#define FACTORIAL_MAX_INPUT_INT 21
#define FACTORIAL_MAX_INPUT_DBL 21.439

namespace z
{
    namespace math
    {
        /**
         * \brief Calculate the factorial of the integer \b n.
         *
         * \param n a positive integer.
         *
         * \return The factorial of \b n, if <B>n>0</B>. \b -1 otherwise.
         */
        template<typename INT,
            typename = typename std::enable_if<std::is_integral<INT>::value>::type>
        INT factorial(INT n)
        {
            if ((n < 0) )//|| (n > FACTORIAL_MAX_INPUT_INT))
                return -1;


            INT result = 1;

            for (INT i=2; i<=n; i++)
            {
                result *= i;
            }

            return result;
        }
    }
}

#undef FACTORIAL_MAX_INPUT_INT
#undef FACTORIAL_MAX_INPUT_DBL

#endif // FACTORIAL_H_INCLUDED
