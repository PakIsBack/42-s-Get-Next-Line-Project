/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:55:00 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/09/09 20:54:45 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define GOOD 1
# define END_F 2
# define LEAVE 3

typedef struct s_list
{
	char			let;
	struct s_list	*next;
}					t_list;

typedef struct s_head
{
	int				fd;
	int				n_num;
	char			state;
	struct s_list	*next;
	struct s_head	*next_head;
}					t_head;

typedef struct s_hydra
{	
	struct s_head	*next_head;
}					t_hydra;

int					ft_init_hydra(t_hydra **hydra, t_head **hd, int fd);
void				*ft_cut_head(t_hydra **hydra, t_head **head, int state);
void				*ft_clear_head(t_head **head);
void				ft_take_out(t_head *head, t_list **nod, char *cad);
void				ft_take_in(t_head *head, t_list **next, char *cad);
char				*get_next_line(int fd);
char				*ft_calloc(int count, int size);
void				ft_read_and_save(t_head *head, int fd);
int					ft_next_line_length(t_head *head);

#endif
