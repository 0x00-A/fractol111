/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:30:23 by aigounad          #+#    #+#             */
/*   Updated: 2022/10/14 04:42:56 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextnodeaddress;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		nextnodeaddress = (*lst)->next;
		del((*lst)->content);
		free (*lst);
		*lst = nextnodeaddress;
	}
}
