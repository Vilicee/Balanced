#include <stdio.h>

char	ft_up_or_low(char c)
{
	if (c <= 90)
		return (c + 32);
	return (c - 32);
}

static int ft_verify(char *str, int len)
{
	int i = 0;
	int ii = 0;
	int ret = 0;
	char c;
	char match;

	while (i < len)
	{
		c = str[i];
		match = ft_up_or_low(c);
		ii = 0;
		while (ii < len)
		{
			if (str[ii] == match)
			{
				ret++;
				break ;
			}
			ii++;
		}
		if (ii == len)
			break ;
		i++;
	}
	return (ret);
}

static int ft_find_match(char *str)
{
	int i = 0;
	int ii = 0;
	int ret = 0;
	char c;
	char match;

	if (str)
	{
		while (str[i])
		{
			ii = 0;
			c = str[i];
			match = ft_up_or_low(c);
			while (str[ii])
			{
				if (str[ii] == match)
				{
					ret++;
					break ;
				}
				ii++;
			}
			if (str[ii] == '\0')
			{
				ret = ft_verify(str, ret);
				break ;
			}
			i++;
		}
	}
	return (ret);
}

static int ft_balance(char *str)
{
	int i = 0;
	int count = 0;
	int ret = 0;

	if (str)
	{
		while (str[i])
		{
			ret = ft_find_match(str + i);
			if (ret > count)
				count = ret;
			if (ret > 0)
				i = i + ret;
			else
				i++;
		}
	}
	return (count);
}

int main(int argc, char **argv)
{
	int res = 0;

	if (argc == 2)
	{
		res = ft_balance(argv[1]);
		printf("Input = (%s), longest balanced string = (%d)\n", argv[1], res);
	}
	else
		printf("not enough arguments, need executable + one\n");
	return (0);
}
