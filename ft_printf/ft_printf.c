/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataskin <ataskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:38:44 by ataskin           #+#    #+#             */
/*   Updated: 2023/02/06 21:38:46 by ataskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		index;
	int		len;

	len = 0;
	index = 0;
	va_start (args, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			len += ft_formats(args, str[index + 1]);
			index++;
		}
		else
		len += ft_putchar(str[index]);
		index++;
	}
	va_end(args);
	return (len);
}

// int main()
// {
// 	int a =22;
// 	char c='x';
// 	int lentgh = ft_printf("hadi be oglum %d%c", a, c);
// 	printf("%d", lentgh);
// }