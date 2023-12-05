char *ft_strupcase(char *str)
{
	while(*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str -= ('a' - 'A');
		}
		str++;
	}
	return (str);
}
