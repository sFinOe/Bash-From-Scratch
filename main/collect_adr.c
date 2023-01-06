/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:55:20 by zkasmi            #+#    #+#             */
/*   Updated: 2022/09/28 17:59:48 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

void	free_adr(void)
{
	t_adr	*tmp;

	while (g_code_status.adr)
	{
		tmp = g_code_status.adr;
		g_code_status.adr = (g_code_status.adr)->next;
		if (tmp->ptr)
			free(tmp->ptr);
		free(tmp);
	}
}

t_adr	*new_adr(void *ptr)
{
	t_adr	*p;

	p = (t_adr *)malloc(sizeof(t_adr));
	if (!p)
		return (0);
	p->ptr = ptr;
	p->next = NULL;
	return (p);
}

t_adr	*lsadd_adr(t_adr *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	collect_adr(void *ptr)
{
	t_adr	*new;
	t_adr	*tmp;

	new = new_adr(ptr);
	if (g_code_status.adr)
	{
		tmp = lsadd_adr((g_code_status.adr));
		tmp->next = new;
	}
	else
		g_code_status.adr = new;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (ptr);
	collect_adr(ptr);
	ft_bzero(ptr, count * size);
	return (ptr);
}
