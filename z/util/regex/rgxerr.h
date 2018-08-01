enum rgxerr
{
	RGX_NO_ERROR = 0,

	RGX_ERROR,
	RGX_PARENTH_MISMATCH,
	RGX_BRACKET_MISMATCH,
	RGX_BRACE_MISMATCH,
	RGX_BRACE_INVALID,

	RGX_LEX_FAIL,
	RGX_BAD_HEX,
	RGX_BAD_RANGE,
	RGX_BAD_COUNT_LOC,
	RGX_BAD_COUNT_FORM,
	RGX_BAD_GREED_LOC,
	RGX_GREED_INEFFECTIVE,

	RGX_BAD_LOOKAHEAD,
	RGX_BAD_LOOKBEHIND,

	RGX_BAD_NEG_FLAG,
	RGX_BAD_POS_FLAG,

	RGX_ERR_COUNT
};
