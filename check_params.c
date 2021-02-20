#include "rush.h"
 int		is_digit(char c)
 {
 	if (c >= '0' && c <= '9')
 		return (0);
 	return (1);
 }
 
 int		is_space(char c)
 {
 	if (c == ' ')
 		return (0);
 	return (1);
 }
 
 int		total_of_digit(char *str)
 {
 	int		i;
 	int		n;
 
 	i = 0;
 	n = 0;
 	while (str[i])
 	{
 		if (!is_digit(str[i]))
 			n++;
 		i++;
 	}
 	return (n);
 }
 
 void	ft_remove_sp(char *str)
 {
 	int		i;
 	int		j;
 
 	i = 0;
 	j = 0;
 	while ((str[j - 1] && str[j]) || j == 0)
 	{
 		str[i] = str[j];
 		i++;
 		j += 2;
 	}
 	str[i] = '\0';
 }
 
 int		ft_param_is_valid(char *str, int max_value)
 {
 	int		i;
 
 	i = 0;
 	while (str[i])
 	{
 		if (i % 2 == 0)
 			if (!(str[i] <= max_value + 48 && str[i] >= '1'))
 				return (1);
 		i++;
 	}
 	i = (i + 1) / 2;
 	if (!(i == 12 || i == 16 || i == 20 || i == 24 || i == 28 || i == 32 ||
 				i == 36))
 		return (1);
 	ft_remove_sp(str);
 	return (0);
 }