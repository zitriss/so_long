/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:53:28 by tlize             #+#    #+#             */
/*   Updated: 2025/04/13 15:27:02 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_printfc(int s);
int		ft_printfs(char *str);
int		ft_printfp(void *ptr);
int		ft_printfu(unsigned int n);
int		ft_printfx(unsigned int n, char format);
int		ft_printfd(int n);

#endif
