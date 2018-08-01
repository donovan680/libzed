#pragma once

#include <z/core/timeout.h>
#include <z/core/string.h>
#include <z/core/stream.h>
#include <z/core/array.h>

namespace z
{
	namespace util
	{
		#include "regex/rgxid.h"
		#include "regex/rgxerr.h"
		#include "regex/rgxss.h"
		#include "regex/rgxsesc.h"
		#include "regex/rgxscan.h"
		#include "regex/rgxll.h"
		#include "regex/rgxlex.h"

		/**
		 * \brief A template class for parsing and matching regular expressions.
		 *
		 * Note that because the class requires seeking locations in a stream,
		 * it will not work nicely with the system::console class.
		 */
		template <encoding E>
		class regex
		{
		private:
			rgxll* root;
			rgxerr parseError;

		public:
			regex();
			regex(const core::string<E>& pattern);

			bool good() const;
			bool bad() const;
			rgxerr error() const;
			core::string<E> errstr() const;
		};

		template <encoding E>
		regex<E>::regex() : root(0), parseError(RGX_NO_ERROR) {}

		template <encoding E>
		regex<E>::regex(const core::string<E>& pattern)
		{
			root = 0;
			core::array<rgxss> symbols; //intermediate

			parseError = rgxscan(pattern, symbols);
			if (!parseError)
			{
				parseError = rgxlex(symbols, root);
			}
		}

		template <encoding E>
		bool regex<E>::good() const
		{
			return (bool)root;
		}

		template <encoding E>
		bool regex<E>::bad() const
		{
			return !root;
		}

		template <encoding E>
		rgxerr regex<E>::error() const
		{
			return parseError;
		}

		template <encoding E>
		core::string<E> regex<E>::errstr() const
		{
			const char* msgs[] =
			{
				"No errors",
				"Regex error",
				"Mismatched parentheses",
				"Mismatched brackets",
				"Mismatched braces",
				"Braces contain invalid characters",
				"Unable to parse pattern",
				"Invalid hexadecimal characters",
				"Improper character range",
				"Bad position for count struct",
				"Improper count struct format",
				"Misplaced greed suppressor",
				"Ineffective greed suppressor",
				"Invalid lookahead symbol",
				"Invalid lookbehind symbol",
				"Unknown negative flag",
				"Unknown positive flag",
			};

			return msgs[parseError];
		}
	}
}
