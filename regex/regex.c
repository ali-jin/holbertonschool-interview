#include "regex.h"

/**
 * regex_match - checks whether str matches pattern
 * @str: the string to scan
 * @pattern: the regular expression
 * Return: return 1 if str matches the pattern, or 0 if not
 */
int regex_match(char const *str, char const *pattern)
{
	char const *string = str;
	char const *patn = pattern;

	if (*string == '\0' && *patn == '\0')
		return 1;

	if (*patn == '\0')
		return 0;

	if (*(patn + 1) != '*')
	{
		if (*string == *patn || (*patn == '.' && *string != '\0'))
			return (regex_match(string + 1, patn + 1));
		else
			return (0);
	}

	while (*string == *patn || (*patn == '.' && *string != '\0'))
	{
		if (regex_match(string, patn + 2))
			return (1);
		string++;
	}

	return (regex_match(string, patn + 2));
}
