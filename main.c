#include "rush.h"
 void	ft_putchar(char c)
 {
 	write(1, &c, 1);
 }
 
 void	ft_error(void)
 {
 	write(1, "Error\n", 6);
 }
 
 void	ft_display_grid(int **arr, int max_value)
 {
 	int		x;
 	int		y;
 
 	x = 1;
 	while (x <= max_value)
 	{
 		y = 1;
 		while (y <= max_value)
 		{
 			ft_putchar(arr[x][y] + '0');
 			if (y != max_value)
 				ft_putchar(' ');
 			y++;
 		}
 		ft_putchar('\n');
 		x++;
 	}
 }
 
 int    main(int argc, char **argv)
 {
 	int		**arr;
 	int		max_value;
 
 	if (argc < 2)
 	{
 		ft_error();
 		return (1);
 	}
 	max_value = ft_get_max_value(argv[1]);
 	if (ft_param_is_valid(argv[1], max_value))
 	{
 		ft_error();
 		return (1);
 	}
 	if (!(arr = ft_create_tab(max_value, argv[1])))
 	{
 		ft_error();
 		return (1);
 	}
 	if (ft_resolve(arr, max_value, 1, 1))
 	{
 		ft_error();
 		return (1);
 	}
 	ft_display_grid(arr, max_value);
 	return (0);
 }