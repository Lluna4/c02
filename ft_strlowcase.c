char *ft_strlowcase(char *str)
{
	while(*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str += ('a' - 'A');
		}
		str++;
	}
	return (str);
}
