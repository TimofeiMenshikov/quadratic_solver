/*!
\file
functions, that work with strings: copy, comparison, research them
*/
#include <stdio.h>
#include <assert.h>
#include "functions_with_strings.h"

char* my_strcpy(char* const string_to_copy, const char* const source_string)
{
	assert(source_string != NULL);
	assert(string_to_copy != NULL);
	size_t string_number = 0;
	for (string_number = 0; source_string[string_number] != '\0'; string_number++)
	{
		assert(source_string[string_number] != '\0');
		string_to_copy[string_number] = source_string[string_number];
	}
	string_to_copy[string_number] = '\0';

	return string_to_copy;
}


int find_str_len(const char* const string)
{
	int string_number = 0;
	while (string[string_number] != '\0')
	{
		string_number++;
	}

	return string_number;
}


void string_research(const char* const string)
{
	for (size_t string_number = 0; string[string_number] != '\0'; string_number++)
	{
		printf("%c(%d)", string[string_number], string[string_number]);
	}
	printf("%c(%d)", '\0', '\0');
	printf("\n");
}


bool my_strcmd(const char* const string1, const char* const string2)
{
	size_t string_number = 0;
	for (string_number = 0; string1[string_number] != '\0' and string2[string_number] != '\0'; string_number++)
	{
		if (string1[string_number] != string2[string_number])
		{
			return false;
		}
	}

	return string2[string_number] == '\0';
}

