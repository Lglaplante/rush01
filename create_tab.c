#include "rush.h"
 int		ft_get_max_value(char *str)
 {
 	return (total_of_digit(str) / 4);
 }
 
 void	ft_fill_tab(int **arr, int max_value, char *params)
 {
 	int		i;
 
 	i = 0;
 	while (++i <= max_value)
 		arr[0][i] = params[i - 1] - '0';
 	i = 0;
 	while (++i <= max_value)
 		arr[max_value + 1][i] = params[i + 3] - '0';
 	i = 0;
 	while (++i <= max_value)
 		arr[i][0] = params[i + 7] - '0';
 	i = 1;
 	while (i <= max_value)
 	{
 		arr[i][max_value + 1] = params[i + 11] - '0';
 		i++;
 	}
 }
 
 int		**ft_create_tab(int max_value, char *params)
 {
 	int		i;
 	int		j;
 	int		**arr;
 
 	if (!(arr = (int **)malloc(sizeof(int *) * max_value + 2)))
 		return (0);
 	i = 0;
 	while (i < max_value + 2)
 	{
 		if (!(arr[i] = (int *)malloc(sizeof(int) * max_value + 2)))
 			return (0);
 		i++;
 	}
 	i = -1;
 	while (++i < max_value + 2)
 	{
 		j = -1;
 		while (++j < max_value + 2)
 			arr[i][j] = 0;
 	}
 	ft_fill_tab(arr, max_value, params);
 	return (arr);
 }