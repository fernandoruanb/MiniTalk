/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:10:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 20:03:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	handle_specifier(char specifier, va_list args)
{
	int	printed;

	printed = 0;
	if (specifier == 'c')
		printed = print_char(args);
	else if (specifier == 's')
		printed = print_str(args);
	else if (specifier == 'd' || specifier == 'i')
		printed = convert_int_to_str(args);
	else if (specifier == '%')
		printed = print_percentage();
	else
	{
		write(1, "%", 1);
		return (-1);
	}
	return (printed);
}
