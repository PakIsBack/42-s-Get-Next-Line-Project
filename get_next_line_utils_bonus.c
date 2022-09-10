/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 05:11:08 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/09/10 14:18:12 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* Clasical calloc function emulation                                        */
char	*ft_calloc(int count, int size)
{
	char	*p;
	int		i;

	p = (char *)malloc(count * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

/* If there is no 'hydra', it initializes it. When it's done, it searchs the */
/* 'head' linked to that 'fd'. If there isn't, it will be created and        */
/* initialized. A memory error will return LEAVE flag, to be managed         */
int	ft_init_hydra(t_hydra **hydra, t_head **hd, int fd)
{
	if (!(*hydra))
	{
		(*hydra) = (t_hydra *)malloc(sizeof(t_hydra));
		if (!(*hydra))
			return (LEAVE);
		(*hydra)->next_head = NULL;
	}
	(*hd) = (*hydra)->next_head;
	while ((*hd) && ((*hd)->fd != fd))
		(*hd) = (*hd)->next_head;
	if (!(*hd))
	{
		(*hd) = (t_head *)malloc(sizeof(t_head));
		if (!(*hd))
			return (LEAVE);
		(*hd)->n_num = 0;
		(*hd)->fd = fd;
		(*hd)->state = GOOD;
		(*hd)->next = NULL;
		(*hd)->next_head = (*hydra)->next_head;
		(*hydra)->next_head = (*hd);
	}
	return (GOOD);
}

/* It will cut and free every nod in 'head' structure, then also 'head'.     */
void	*ft_clear_head(t_head **head)
{
	t_list	*tmp;

	if (*head)
	{
		while ((*head)->next)
		{
			tmp = (*head)->next;
			(*head)->next = (*head)->next->next;
			free(tmp);
		}
		free(*head);
		*head = NULL;
	}
	return (NULL);
}

/* With 'state' flag in LEAVE (error in memory), it will cut and free every  */
/* 'head', and then also 'hydra', and return NULL.                           */
/* With 'state' flag in GOOD, it will just cut and free current 'head'.      */
void	*ft_cut_head(t_hydra **hydra, t_head **head, int state)
{
	t_head	*tmp;

	if (state == LEAVE || (*head)->state == LEAVE)
	{
		while ((*hydra)->next_head)
			ft_cut_head(hydra, &((*hydra)->next_head), GOOD);
	}
	else
	{	
		if ((*hydra)->next_head == (*head))
			(*hydra)->next_head = (*head)->next_head;
		else
		{
			tmp = (*hydra)->next_head;
			while (tmp->next_head != (*head))
				tmp = tmp->next_head;
			tmp->next_head = (*head)->next_head;
		}
	}
	if (!((*hydra)->next_head))
	{
		free(*hydra);
		*hydra = NULL;
	}
	return (ft_clear_head(head));
}

/* It will count and return the length of next line in structure, that will  */
/* end with a '\n' char or end of structure.                                 */
int	ft_next_line_length(t_head *head)
{
	int		i;
	t_list	*nodo;

	i = 0;
	nodo = head->next;
	while (nodo && (nodo->let != '\n'))
	{
		i++;
		nodo = nodo->next;
	}
	if (nodo && (nodo->let == '\n'))
		i++;
	return (i);
}
