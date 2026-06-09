/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:52 by akurochk          #+#    #+#             */
/*   Updated: 2023/11/16 12:48:52 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>

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

// parse and utils
void	ck_and_parse(int ac, char **av, t_stk *stack);
void	error_exit(void);
void	ck_empty_str(char *arg, char *s);
size_t	count_numbs(char **numbs);
void	free_numbs(char **numbs);
void	prepare_stack(t_stk *stack, int *tab, int len);

// do_op
int		s_comp(const char *s1, const char *s2);
int		op_r(t_list **head, size_t size, int is_rrx);
int		op_s(t_list **head, size_t size);
int		op_p(t_list **head1, size_t *size1, t_list **head2, size_t *size2);

// GNL
char	*get_next_line(int fd);

// utils

void	add_rank(t_list *ptr, int size);

// stack
void	fill_stack(int num, t_list **ptr_a, int *tab);
int		is_sorted(t_list *ptr);
void	free_stack(t_list *ptr);

// libft
size_t	ft_strlen(const char *s);
char	*ft_strjoin_with_space(char const *s1, char const *s2, int space);
int		ft_isdigit(int c);
int		ft_atoi_ck_int(const char *s, char **numbs, int *tab);
void	ft_putstr_fd(char *s, int fd);

// split
char	**ft_split(char const *s, char c);

#endif
