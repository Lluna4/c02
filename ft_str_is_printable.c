int ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if (*str < ' ' || *str > '~')
		{
			return (0);
		}
		str++;
	}
	return (1);
}
