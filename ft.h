/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 10:12:11 by pdelefos          #+#    #+#             */
/*   Updated: 2015/08/27 21:40:22 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_list
{
	struct s_list	*next;
	char			*data;
}					t_list;

typedef struct		s_info
{
	int				line;
	int				column;
	char			empty_char;
	char			bloc_char;
	char			square_char;
}					t_info;

typedef struct		s_sq
{
	int				i;
	int				j;
	int				pos_x;
	int				pos_y;
	int				v;
}					t_sq;

int					ft_check_line_size(char **grid, int j);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
int					ft_strlen(char *str);
int					ft_atoi(char *str);
char				*ft_strdup(char *src);
int					ft_send_i(char *str_grid);
int					ft_send_t(char *str_grid, int i);
void				ft_putchar_err(char c);
void				ft_putstr_err(char *str);

void				ft_list_push_back(t_list **begin_list, char *data);
int					ft_size_list(t_list *list);
void				ft_print_bsq(char **bsq, t_info grid_info);
void				ft_list_clear(t_list **begin_list);

int					ft_check_error(char *str, t_info grid_info);
char				*ft_str_map(char *filename);
char				*ft_str_map_stdi(void);
t_info				ft_make_grid_info(char *str_grid);
char				**ft_make_grid(char *str_grid, t_info grid_info);
int					**ft_convert(char **grid, t_info grid_info);
int					**ft_resolve(int **grid, t_info grid_info);
char				**ft_square(int **grid, t_info grid_info);

void				ft_saruman(char *filename);
void				ft_sauron(void);

#endif
