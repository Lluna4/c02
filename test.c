#include "ft_strlcpy.c"
#include <stdio.h>


int main()
{
	char a[] = "hola que tal!";
	char b[5];
	ft_strlcpy(b, a, 5);
	printf("%s\n", b);
}
