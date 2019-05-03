#include "character.h"
namespace z
{
	namespace util
	{
		namespace rgx
		{
			character::character(uint32_t value, bool insensitive, size_t min, size_t max, bool greedy):
				rule(min,max,greedy), value(value), insensitive(insensitive) {}

			bool character::match(uint32_t current) const
			{
				return current == value;
			}
		}
	}
}
