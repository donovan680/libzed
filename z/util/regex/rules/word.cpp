#include "word.h"
#include <z/core/charFunctions.h>
namespace z
{
	namespace util
	{
		namespace rgx
		{
			bool word::match(uint32_t current) const
			{
				return ('_' == current) || core::isAlphaNumeric(current);
			}

#			ifdef DEBUG
			void word::print(core::outputStream& stream, int level)
			{
				(zpath().padLeft(" ",(level)<<1)+"\\w").writeln(stream);
			}
#			endif
		}
	}
}
