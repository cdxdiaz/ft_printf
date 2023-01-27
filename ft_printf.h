/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsawatwa <wenai.sawatwathin@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 03:36:51 by wsawatwa          #+#    #+#             */
/*   Updated: 2023/01/27 07:20:34 by wsawatwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_print_char(char c);
int	ft_print_str(char	*str);
int	ft_print_adr(unsigned long int nb);
int	ft_print_nbr(int nb);
int	ft_print_base(unsigned int n, unsigned int base, int l);
int	ft_checker(char c, va_list *ptr);
int	ft_printf(const char *format, ...);

#endif
