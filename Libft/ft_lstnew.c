/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:49:49 by zkasmi            #+#    #+#             */
/*   Updated: 2022/09/25 15:41:08 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/minishell.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*block;

	block = ft_calloc(sizeof(t_list), 1);
	if (!block)
		return (NULL);
	block->content = content;
	block->next = NULL;
	return (block);
}
