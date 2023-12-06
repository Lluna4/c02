#include <unistd.h>

int	ft_putchar(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_isprint(int a)

{
	if (a >= 32 && a <= 126)
	{
		return (1);
	}
	return (0);
}

int	ft_hexlen(unsigned short n)
{
	int	ret;

	ret = 1;
	while (n >= 16)
	{
		ret++;
		n = n / 16;
	}
	return (ret);
}

int	ft_puthex(unsigned int n)
{
	int	ret;
	int	sum;

	ret = ft_hexlen(n);
	if (n >= 16)
	{
        if (ft_puthex(n / 16) == -1)
            return (-1);
		n = n % 16;
	}
	if (n > 9)
		if (ft_putchar(n + 87) == -1)
			return (-1);
	if (n <= 9)
		if (ft_putchar(n + '0') == -1)
			return (-1);
	return (ret);
}

int ft_put_pointer(unsigned long n)
{
	int	ret;
	int	sum;

	ret = ft_hexlen(n);
	if (n >= 16)
	{
        if (ft_put_pointer(n / 16) == -1)
            return (-1);
		n = n % 16;
	}
	if (n > 9)
		if (ft_putchar(n + 87) == -1)
			return (-1);
	if (n <= 9)
		if (ft_putchar(n + '0') == -1)
			return (-1);
	return (ret);
}

void print_bytes(void *ptr, int size) 
{
    unsigned char *p = ptr;
    int i;
    int total = 0;
    int max = 16;

    while (total < size)
    {
        for (i=total; i<max; i += 2) 
        {
            if (i % 16 == 0)
			{
               ft_put_pointer((unsigned long)&p[i]);
			   	ft_putchar(':');
				ft_putchar(' ');
			}
            if (ft_puthex((unsigned int)p[i]) < 2)
				ft_putchar('0');
            if (ft_puthex((unsigned int)p[i + 1]) < 2)
				ft_putchar('0');
            ft_putchar(' ');
            //printf("%02hhX%02hhX ",p[i], p[i+1]);
            total += 2;
        }
        for (i=total - 16; i<max; i++) 
        {
            if (ft_isprint(p[i]) == 0)
                ft_putchar('.');
            else
                ft_putchar(p[i]);
        }
        ft_putchar('\n');
        max += 16;
    }
}
 
int main()
{
    char *a = "This is very cool\n I'm having real fun here";
    print_bytes(a, 10);
}