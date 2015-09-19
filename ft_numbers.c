#include "evalexpr.h"

int		is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		is_operator(char c)
{
	if (c == '+' || c == '-' || c == '%' || c == '*' || c == '/')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int		sign;
	char	*cur;
	int		result;

	result = 0;
	cur = str;
	sign = (*cur == '-') ? -1 : 1;
	cur = (*cur == '+' || *cur == '-') ? cur + 1 : cur;
	while (is_number(*cur))
	{
		result = result * 10 + *cur - 48;
		cur++;
	}
	result *= sign;
	return (result);
}

int		get_length(int n)
{
	int i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
        n /= 10;
        i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;

	len = get_length(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	neg = n < 0;
	if (neg)
	{
		str[0] = '-';
		n = -n;
	}
	while (len-- > neg)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
