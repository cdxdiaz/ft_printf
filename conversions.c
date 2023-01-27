/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsawatwa <wenai.sawatwathin@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:40:51 by wsawatwa          #+#    #+#             */
/*   Updated: 2023/01/27 07:57:29 by wsawatwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_print_str("(null)");
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_print_nbr(int nb)
{
	size_t	n;
	int			len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += ft_print_nbr(n / 10);
		len += ft_print_nbr(n % 10);
	}
	if (n < 10)
		len += ft_print_char(n + 48);
	return (len);
}

int	ft_print_adr(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_print_adr(nb / 16);
		len += ft_print_adr(nb % 16);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += ft_print_char(nb + '0');
		else
			len += ft_print_char(nb + 'a' - 10);
	}
	return (len);
}

int	ft_print_base(unsigned int n, unsigned int base, int l)
{
	int	len;

	len = 0;
	if (n >= base)
	{
		len += ft_print_base(n / base, base, l);
		len += ft_print_base(n % base, base, l);
	}
	if (n < base)
	{
		if (n < 10)
			len += ft_print_char(n + '0');
		else
		{
			if (l == 1)
				len += ft_print_char(n + 'a' - 10);
			else
				len += ft_print_char(n + 'A' - 10);
		}
	}
	return (len);
}