#include "lookbehind.h"
namespace z
{
	namespace util
	{
		namespace rgx
		{
			lookbehind::lookbehind(size_t width, bool negate, size_t min, size_t max, bool greedy):
				compound(min,max,greedy), negate(negate), width(width){}

			bool lookbehind::match(core::inputStream& stream) const
			{
				size_t pos = stream.tell();

				size_t charw;
				switch (stream.format())
				{
					case utf32:
						charw = 4;
						break;
					case utf16:
						charw = 2;
						break;
					default:
						charw = 1;
				}

				charw *= width;
				if (pos < charw) return negate;
				stream.seek(charw);

				for (auto& child : children)
				{
					//Lookbehind is assumed to have constant width, so only match minimum.
					if (!matchMin(child, stream))
					{
						stream.seek(pos);
						return negate;
					}
				}

				stream.seek(pos);
				return !negate;
			}

#			ifdef DEBUG
			void lookbehind::print(core::outputStream& stream, int level)
			{
				if (negate)
					(zpath().padLeft(" ",(level)<<1)+"?<!").writeln(stream);
				else
					(zpath().padLeft(" ",(level)<<1)+"?<").writeln(stream);

				for (auto& child : children)
				{
					child->print(stream,level+1);
				}
			}
#			endif
		}
	}
}
