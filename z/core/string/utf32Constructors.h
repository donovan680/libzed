#pragma once

namespace z
{
	namespace core
	{
		template <>
		string<utf32>::string()
		{
			data = new uint8_t[4];
			*((uint32_t*)data) = 0;

			data_len = 4;
			character_ct = 0;
		}

		template <>
		string<utf32>::string(char chr)
		{
			data = new uint8_t[4];
			uint32_t* data32 = (uint32_t*)data;

			data32[0] = chr;
			data32[1] = 0;

			data_len = 8;
			character_ct = 1;
		}

		template <>
		string<utf32>::string(wchar_t chr)
		{
			data = new uint8_t[4];
			uint32_t* data32 = (uint32_t*)data;

			data32[0] = chr;
			data32[1] = 0;

			data_len = 8;
			character_ct = 1;
		}

		template <>
		string<utf32>::string(const uint32_t& chr)
		{
			data = new uint8_t[4];
			uint32_t* data32 = (uint32_t*)data;

			data32[0] = chr;
			data32[1] = 0;

			data_len = 8;
			character_ct = 1;
		}

		template <>
		string<utf32>::string(const char* str)
		{
			if (str)
			{
				size_t len = 0;
				while (str[len]) len++;

				character_ct = len;
				data = new uint8_t[(++len)<<2];
				data_len = len<<2;

				uint32_t* data32 = (uint32_t*)data;

				for (size_t i=0; i<len; i++)
					data32[i] = str[i];
			}
			else
			{
				data = new uint8_t[4];
				*((uint32_t*)data) = 0;

				data_len = 4;
				character_ct = 0;
			}
		}

		template <>
		string<utf32>::string(const wchar_t* str)
		{
			if (str)
			{
				size_t len = 0;
				while (str[len]) len++;

				character_ct = len;
				data = new uint8_t[(++len)<<2];
				data_len = len<<2;

				uint32_t* data32 = (uint32_t*)data;

				for (size_t i=0; i<len; i++)
					data32[i] = str[i];
			}
			else
			{
				data = new uint8_t[4];
				*((uint32_t*)data) = 0;

				data_len = 4;
				character_ct = 0;
			}
		}

		template <>
		string<utf32>::string(const string<ascii>& other)
		{
			data_len = (other.character_ct + 1) << 2;
			character_ct = other.character_ct;

			data = new uint8_t[data_len];
			uint32_t* data32 = (uint32_t*)data;

			for (size_t i=0; i<=character_ct; i++)
				data32[i] = other.data[i];
		}

		template <>
		string<utf32>::string(const string<utf8>& other)
		{
			character_ct = 0;
			for (size_t i=0; i<other.character_ct; i+=lenFromUTF8(&other.data[i]))
				character_ct++;

			data_len = (character_ct + 1) << 2;
			data = new uint8_t[data_len];

			uint32_t* data32 = (uint32_t*)data;
			data32[character_ct] = 0;

			size_t pos = 0;
			for (size_t i=0; i<character_ct; i++)
			{
				uint32_t val = fromUTF8(&other.data[pos]);
				pos += lenFromUTF8(&other.data[pos]);

				data32[i] = val;
			}
		}

		template <>
		string<utf32>::string(const string<utf16>& other)
		{
			data_len = (other.character_ct + 1) << 2;
			character_ct = other.character_ct;

			data = new uint8_t[data_len];

			uint32_t* data32 = (uint32_t*)data;
			uint16_t* data16 = (uint16_t*)other.data;

			for (size_t i=0; i<=character_ct; i++)
				data32[i] = data16[i];
		}

		template <>
		string<utf32>::string(const string<utf32>& other)
		{
			data_len = (other.character_ct + 1) << 2;
			character_ct = other.character_ct;

			data = new uint8_t[data_len];

			uint32_t* data32 = (uint32_t*)data;
			uint32_t* other32 = (uint32_t*)other.data;

			for (size_t i=0; i<=character_ct; i++)
				data32[i] = other32[i];
		}
	}
}