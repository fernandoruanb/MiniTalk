/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:10:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 20:12:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_printf(const char *format, ...)
{
	int		total;
	va_list	args;

	if (!format)
		return (-1);
	total = 0;
	va_start(args, format);
	total += parse_format(format, args);
	va_end(args);
	return (total);
}
