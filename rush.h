#ifndef RUSH_H
 # define RUSH_H
 # include <unistd.h>
 # include <stdlib.h>
 int		ft_param_is_valid(char *str, int max_value);
 
 int		ft_get_max_value(char *str);
 
 int		ft_is_digit(char c);
 
 int		ft_is_space(char c);
 
 int		ft_total_digit(char *str);
 
 int		ft_resolve(int **arr, int i, int x, int y);
 
 void	ft_display_grid(int **arr, int max_value);
 
 int		**ft_create_tab(int max_value, char *params);
 
 int		ft_get_max_value(char *str);
 
 int		total_of_digit(char *str);
 
 #endif