#include <unistd.h>
#include <ctype.h>

int	ft_putchar(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_hexlen(unsigned long long int n)
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

int	ft_puthex(unsigned long long n, char may, int iter)
{
	int	ret;
	int	sum;

	if (may == 'X')
		sum = 55;
	else
		sum = 87;
	ret = ft_hexlen(n);
	if (n >= 16)
	{
        if (ft_puthex(n / 16, may, iter++) == -1)
            return (-1);
		n = n % 16;
	}
	if (n == 0 && iter == 0)
		return (ft_putchar('0'));
	if (n > 9)
		if (ft_putchar(n + sum) == -1)
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
               ft_puthex((unsigned long long)&p[i], 'a', 0);
            ft_puthex((unsigned long long)p[i], 'a', 0);
            ft_puthex((unsigned long long)p[i + 1], 'a', 0);
            ft_putchar(' ');
            //printf("%02hhX%02hhX ",p[i], p[i+1]);
            total += 2;
        }
        for (i=total - 16; i<max; i++) 
        {
            if (isalnum(p[i]) == 0)
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
    char *a = "askjakkkkkkkk";
    print_bytes(a, 16);
}