/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylang <ylang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:59:47 by ylang             #+#    #+#             */
/*   Updated: 2025/10/08 20:52:24 by ylang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct s_node
{
	int				data;
	int				index;
	int				position;
	int				cost_to_top;
	int				cost_to_reinsert;
	int				total_cost;
	int				target_position_in_a;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

/* parse */
int					is_all_digit(char *s);
int					ft_atoi_with_overflow_check(char *s, int *error);
char				**ft_split(const char *s, char c);
void				free_split(char **split);

/* check validity */
void				check_dup_num(int size, int *numbers, char **strs,
						int should_free_strs);
void				check_strs_validity(char **strs, int should_free_strs,
						int *numbers);

/* errors */
void				exit_with_error(void);
void				free_and_exit_error(int *numbers, char **strs,
						int should_free_strs, int *tmp);
/* int utils*/
int					max(int a, int b);
int					min(int a, int b);

/*strs*/
void				ft_putstr(char *s);

/* stack operations */
void				sa(t_node **a, int p);
void				sb(t_node **b, int p);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				ra(t_node **a, int p);
void				rb(t_node **b, int p);
void				rra(t_node **a, int p);
void				rrb(t_node **b, int p);
void				rr(t_node **a, t_node **b);
void				rrr(t_node **a, t_node **b);

/* algo building blocks */
int					get_stack_len(t_node *x);
t_node				*create_stack(int *numbers, int *sorted, int size);
int					*dup_int_array(int *src, int size);
void				sort_int_arr(int *numbers, int size);
int					get_index(int value, int *sorted, int size);

/* Calculate position, cost*/
int					get_cost_to_top(int position, int current_size);
int					position_to_insert_to_a(t_node *a, t_node *b);
int					calcualte_reinsert_cost_to_a(t_node *a, t_node *b);
int					calculate_total_cost(int cost_to_top, int cost_to_reinsert);

void				update_position(t_node *a, t_node *b);
void				rotate_both_stacks_to_prepare(t_node **a, t_node **b,
						t_node *node);
void				reinsert_b_to_a(t_node **a, t_node **b);
void				rotate_a_to_correct_order(t_node **a);
void				push_to_b(t_node **a, t_node **b);

/*sort stack */
void				sort_a_2(t_node **stack_a);
void				sort_a_4(t_node **stack_a, t_node **stack_b);
void				sort_a_5(t_node **stack_a, t_node **stack_b);
void				sort_a_3(t_node **a);
void				sort_small_num(int len, t_node **a, t_node **b);
int					is_fully_sorted(t_node *a);
int					is_rotationaly_sorted(t_node *a);
void				free_stack(t_node *s);
void				sort_stack(t_node **a);

#endif
