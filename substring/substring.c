#include "substring.h"

/**
 * check_substring - Check if a substring is a valid concatenation of words
 * @s: The string to check
 * @words: Array of words
 * @nb_words: Number of words
 * @word_len: Length of each word
 * @used: Array to track used words
 * @start: Starting index
 * Return: 1 if valid, 0 otherwise
 */
int check_substring(char const *s, char const **words, int nb_words,
					int word_len, int *used, int start)
{
	int i, j, found;
	char *temp_word;

	for (i = 0; i < nb_words; i++)
		used[i] = 0;

	temp_word = malloc((word_len + 1) * sizeof(char));
	if (!temp_word)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		strncpy(temp_word, s + start + i * word_len, word_len);
		temp_word[word_len] = '\0';

		found = 0;
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] && strcmp(temp_word, words[j]) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}

		if (!found)
		{
			free(temp_word);
			return (0);
		}
	}

	free(temp_word);
	return (1);
}

/**
 * find_substring - finds all the possible substrings
 * containing a list of words
 *
 * @s: string to scan
 * @words: array of words all substrings must be a concatenation arrangement of
 * @nb_words: number of elements in the array words
 * @n: holds the address at which to store the number of elements
 * Return: return an allocated array, storing each index in s,
 *         at which a substring was found or NULL if failed
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *indices = NULL;
	int *used = NULL;
	int word_len, s_len, i, count = 0;
	int max_indices;

	if (!s || !words || nb_words <= 0 || !n)
		return (NULL);
	word_len = strlen(words[0]);
	s_len = strlen(s);
	max_indices = s_len - (nb_words * word_len) + 1;
	if (max_indices <= 0)
	{
		*n = 0;
		return (NULL);
	}
	indices = malloc(max_indices * sizeof(int));
	used = malloc(nb_words * sizeof(int));
	if (!indices || !used)
	{
		free(indices);
		free(used);
		return (NULL);
	}
	for (i = 0; i <= s_len - (nb_words * word_len); i++)
	{
		if (check_substring(s, words, nb_words, word_len, used, i))
		{
			indices[count] = i;
			count++;
		}
	}
	free(used);
	if (count == 0)
	{
		free(indices);
		indices = NULL;
	}
	else
	{
		int *temp = realloc(indices, count * sizeof(int));
		if (temp)
			indices = temp;
	}
	*n = count;
	return (indices);
}
