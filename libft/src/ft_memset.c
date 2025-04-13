/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:26:36 by tlize             #+#    #+#             */
/*   Updated: 2025/04/13 14:42:28 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s_char;

	s_char = (char *)s;
	while (n > 0)
	{
		s_char[n - 1] = c;
		n--;
	}
	return (s);
}
