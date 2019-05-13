#pragma once
#include "rule.h"
#include <z/core/array.h>

namespace z
{
	namespace util
	{
		namespace rgx
		{
			class compound : public rule
			{
			protected:
				bool matchRule(rule* rgxRule, core::inputStream& stream) const;
				bool matchMin(rule* rgxRule, core::inputStream& stream) const;

			public:
				~compound();

				compound(size_t min=1, size_t max=1, bool greedy=true): rule(min,max,greedy){}

				bool base() const {return false;};
				bool parent() const {return true;};

				core::array<rule*> children;

#			ifdef DEBUG
				virtual void print(core::outputStream& stream, int level=0)
				{
					(void)stream;
					(void)level;
				}
#			endif
			};
		}
	}
}
