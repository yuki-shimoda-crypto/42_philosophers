#include <stdio.h>
#include <string.h>

void	ft_str1(char *str)
{
	str = strdup("str1");
}

void	ft_str2(char **str)
{
	*str = strdup("str2");
}

int main(void)
{
	char	*str1;
	char	*str2;

	str1 = strdup("test");
	str2 = strdup("test");
	printf("%s\n", str1);
	printf("%p\n", str1);
	printf("%s\n", str2);
	printf("%p\n", str2);
	printf("%s\n", "-----");
	ft_str1(str1);
	ft_str2(&str2);
	printf("%s\n", str1);
	printf("%p\n", str1);
	printf("%s\n", str2);
	printf("%p\n", str2);
	return (0);
}