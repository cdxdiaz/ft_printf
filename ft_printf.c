/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsawatwa <wenai.sawatwathin@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:04:24 by wsawatwa          #+#    #+#             */
/*   Updated: 2023/01/27 07:19:55 by wsawatwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(char c, va_list *ptr)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_print_char(va_arg(*ptr, int));
	if (c == 's')
		len += ft_print_str(va_arg(*ptr, char *));
	if (c == 'd' || c == 'i')
		len += ft_print_nbr(va_arg(*ptr, int));
	if (c == 'u')
		len += ft_print_base(va_arg(*ptr, unsigned int), 10, 1);
	if (c == 'x')
		len += ft_print_base(va_arg(*ptr, unsigned int), 16, 1);
	if (c == 'X')
		len += ft_print_base(va_arg(*ptr, unsigned int), 16, 0);
	if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_print_adr(va_arg(*ptr, unsigned long int));
	}
	if (c == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ptr;

	len = 0;
	i = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		if (format[i] == '%')
		{
			len += ft_checker(format[i + 1], &ptr);
			i++;
		}
		i++;
	}
	va_end(ptr);
	return (len);
}
