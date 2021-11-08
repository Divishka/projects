#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

int		error(void);
int		check(char **s, char *c, int index);
int		check_two(char *str);
size_t	ft_count(const char *str);
char	**check_str(char **argv, int *argc, char *c);
int		ft_is_strdigit(char *str);
int		validate_value(char **argv, int size);
int		perfect_array(int *stack_a, int size);
int		min(int *stack_a, int size, int *index);
int		max(const int stack_a[], int size);
void	big_sorting(int *stack_a, int *stack_b, int size);
int		*atoi_array(char **argv, int size, char c);
int		find_hold_first(const int *stack_a, int size, int base, int *flag);
int		find_hold_second(const int stack_a[], int size, int *flag);
int		check_two(char *str);
size_t	ft_count(const char *str);
char	**check_str(char **argv, int *argc, char *c);
int		print_line_a(char *line, int *stack_a, int *stack_b, int size);
int		print_line_b(char *line, int *stack_a, int *stack_b, int size_b);
int		get_next_line(char **line);
int		result(char c);
int		print_double(char *line, int *stack_a, int *stack_b, int size);

void	sa(int *stack_a, char *str);
void	rra(int *stack_a, int size, char *str);
void	rb(int *stack_a, int size, char *str);
void	rrb(int *stack_a, int size, char *str);
void	ra(int *stack_a, int size, char *str);
void	pb(int *stack_a, int *stack_b, char *str);
void	pa(int *stack_a, int *stack_b, int size, char *str);
void	ss(int *stack_a, int *stack_b, char *str, int size);
void	sb(int *stack_b, int size, char *str);
void	rrr(int *stack_a, int *stack_b, int size, char *str);
void	rr(int *stack_a, int *stack_b, int size, char *str);
int		*push_swap(int *stack_a, int size);

#endif
