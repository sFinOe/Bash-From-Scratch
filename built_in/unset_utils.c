/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:45:49 by zkasmi            #+#    #+#             */
/*   Updated: 2022/09/25 18:46:52 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

t_export	*expo_delt(t_export *xtmp)
{
	if (xtmp->next->next == NULL)
		xtmp->next = NULL;
	else
		xtmp->next = xtmp->next->next;
	return (xtmp);
}

t_env	*env_delt(t_env *etmp)
{
	if (etmp->next->next == NULL)
		etmp->next = NULL;
	else
		etmp->next = etmp->next->next;
	return (etmp);
}
