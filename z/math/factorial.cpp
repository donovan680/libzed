#include "factorial.h"

namespace z
{
	namespace math
	{
		long long factorial(long long n)
		{
			if (n < 0)
				return 0;


			long long result = 1;

			long long i = 2;
			while (i <= n)
			{
				long long newResult = result * i;

				if ((newResult == result) ||
					(newResult <= 0))
					return 0;

				result = newResult;
				i++;
			}

			return result;
		}

		long long factorial(long long n, bool& did_overflow)
		{
			if (n < 0)
			{
				did_overflow = false;
				return 0;
			}


			long long result = 1;

			long long i = 2;
			while (i <= n)
			{
				long long newResult = result * i;

				if ((newResult == result) ||
					(newResult <= 0))
				{
					did_overflow = true;
					return 0;
				}

				result = newResult;
				i++;
			}

			did_overflow = false;
			return result;
		}
	}
}