
#include <stdio.h>

int	match(char *s1, char *s2)
{
	if (*s2 == 0)
		return (*s1 == 0);
	else if (*s2 == '*')
	{
		while (*s1)
		{
			if (match(s1++, s2 + 1))
				return (1);
		}
		return (match(s1, s2));
	}
	else if (*s1 != *s2)
		return (0);
	else
		return (match(s1 + 1, s2 + 1));
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		printf("Usage: <phrase to find> <pattern>\n");
	else
		printf("%d", match(argv[1], argv[2]));
	return (0);
}
