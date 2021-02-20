#include "rush.h"
 int		ft_check_cols_up(int **arr, int x, int max_value)
 {
 	int		cpt;
 	int		y;
 	int		i;
 
 	y = 1;
 	cpt = 1;
 	i = 1;
 	while (y + i <= max_value)
 	{
 		if (arr[x][y] < arr[x][y + i])
 		{
 			cpt++;
 			y += i;
 			i = 1;
 		}
 		else
 			i++;
 	}
 	if (cpt == arr[x][0])
 		return (0);
 	else
 		return (1);
 }
 
 int		ft_check_cols_down(int **arr, int x, int max_value)
 {
 	int		cpt;
 	int		y;
 	int		i;
 
 	y = max_value;
 	cpt = 1;
 	i = 1;
 	while (y - i >= 1)
 	{
 		if (arr[x][y] < arr[x][y - i])
 		{
 			cpt++;
 			y -= i;
 			i = 1;
 		}
 		else
 			i++;
 	}
 	if (cpt == arr[x][max_value + 1])
 		return (0);
 	else
 		return (1);
 }
 
 int		ft_check_row_left(int **arr, int y, int max_value)
 {
 	int		cpt;
 	int		x;
 	int		i;
 
 	x = 1;
 	cpt = 1;
 	i = 1;
 	while (x + i <= max_value)
 	{
 		if (arr[x][y] < arr[x + i][y])
 		{
 			cpt++;
 			x += i;
 			i = 1;
 		}
 		else
 			i++;
 	}
 	if (cpt == arr[0][y])
 		return (0);
 	else
 		return (1);
 }
 
 int		ft_check_row_right(int **arr, int y, int max_value)
 {
 	int		cpt;
 	int		x;
 	int		i;
 
 	x = max_value;
 	cpt = 1;
 	i = 1;
 	while (x - i >= 1)
 	{
 		if (arr[x][y] < arr[x - i][y])
 		{
 			cpt++;
 			x -= i;
 			i = 1;
 		}
 		else
 			i++;
 	}
 	if (cpt == arr[max_value + 1][y])
 		return (0);
 	else
 		return (1);
 }
 
 int		ft_check_view_point(int **arr, int max_value)
 {
 	int		i;
 
 	i = 1;
 	while (i <= max_value)
 	{
 		if (ft_check_cols_up(arr, i, max_value))
 			return (1);
 		if (ft_check_cols_down(arr, i, max_value))
 			return (1);
 		if (ft_check_row_left(arr, i, max_value))
 			return (1);
 		if (ft_check_row_right(arr, i, max_value))
 			return (1);
 		i++;
 	}
 	return (0);
 }
 
 int		check(int **arr, int i, int x, int y, int max_value)
 {
 	int row;
 	int column;
 
 	row = 1;
 	column = 1;
 	while (row <= max_value)
 	{
 		if (i == arr[row][y])
 			return (1);
 		row++;
 	}
 	while (column <= max_value)
 	{
 		if (i == arr[x][column])
 			return (1);
 		column++;
 	}
 	return (0);
 }
 
 int		ft_resolve(int **arr, int max_value, int x, int y)
 {
 	int i;
 
 	i = 1;
 	while (1)
 	{
 		while (i <= max_value && check(arr, i, x, y, max_value))
 			i++;
 		if (i <= max_value)
 			arr[x][y] = i;
 		else
 		{
 			arr[x][y] = 0;
 			return (1);
 		}
 		if (x == max_value && y == max_value)
 		{
 			if (ft_check_view_point(arr, max_value))
 			{
 				if (i >= max_value)
 				{
 					arr[x][y] = 0;
 					return (1);
 				}
 				else
 				{
 					continue;
 				}
 			}
 			else
 				return (0);
 		}
 		if (x == max_value)
 		{
 			if (ft_resolve(arr, max_value, 1, y + 1))
 				continue;
 			return (0);
 		}
 		else
 		{
 			if (ft_resolve(arr, max_value, x + 1, y))
 				continue;
 			return (0);
 		}
 	}
 }