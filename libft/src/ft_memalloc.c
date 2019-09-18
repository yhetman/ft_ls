/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:46:14 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/18 17:44:57 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memory;
	size_t	i;

	i = -1;
	if (!(memory = malloc(size)))
		return (NULL);
	ft_bzero(memory, sizeof(void));
	return (memory);
}
