/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:58:23 by tlize             #+#    #+#             */
/*   Updated: 2025/04/07 19:52:53 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;
	char	*str_char;	

	if (!str)
		return(0);
	i = 0;
	str_char = (char *)str;
	while (str_char[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	char *chaine1 = "Test 1";
// 	char *chaine2 = "Test 2 123123";
// 	char *chaine3 = "   Test 3 abc ";
// 	assert(ft_strlen(chaine1) == strlen(chaine1));
// 	assert(ft_strlen(chaine2) == strlen(chaine2));
// 	assert(ft_strlen(chaine3) == strlen(chaine3));
// 	printf("OK");
// 	return (0);
// }
