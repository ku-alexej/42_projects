/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:50:29 by akurochk          #+#    #+#             */
/*   Updated: 2023/11/16 12:50:29 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

typedef struct s_list
{
	int				num;
	size_t			rank;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct s_stk
{
	struct s_list	*a;
	size_t			size_a;
	struct s_list	*b;
	size_t			size_b;
}				t_stk;

typedef struct s_combo
{
	size_t	nb_ra;
	size_t	nb_rra;
	size_t	nb_rb;
	size_t	nb_rrb;
	size_t	nb_rr;
	size_t	nb_rrr;
	size_t	qty;
	size_t	num;
}				t_combo;

typedef struct s_score
{
	t_list	*scroll_a;
	t_list	*scroll_b;
	size_t	qty[4];
	size_t	size_ab;
	int		i;
	int		i1;
	int		i2;
}				t_score;

typedef struct s_scroll
{
	struct s_list	*ptr;
	struct s_list	*ptr_min;
	struct s_list	*ptr_max;
}				t_scroll;

// stack
void	fill_stack(int num, t_list **ptr, int *tab);
void	free_stack(t_list *ptr);
int		is_sorted(t_list *ptr);

// parse and it's utils
void	error_exit(void);
void	ck_empty_str(char *arg, char *s);
size_t	count_numbs(char **numbs);
void	free_numbs(char **numbs);
void	prepare_stack(t_stk *stack, int *tab, int len);
void	ck_and_parse(int ac, char **av, t_stk *stack);

// common
void	add_rank(t_list *ptr, int size);

// third_sort
void	third_sort(t_stk *stack);

// utils
void	do_op(char *mvt, t_stk *stack);
int		min(int a, int b);
int		max(int a, int b);
void	set_extremes(t_list *ptr, size_t *min, size_t *max);

// libft
char	*ft_strjoin_space(char const *s1, char const *s2);
int		ft_isdigit(int c);
int		ft_atoi_ck_int(const char *s, char **numbs, int *tab);
void	ft_putstr_fd(char *c, int fd);
char	**ft_split(char const *s, char c);
#endif
