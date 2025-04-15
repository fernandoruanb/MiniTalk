/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:09:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 20:09:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "minitalk.h"

int	ft_printf(const char *format, ...);
int	parse_format(const char *format, va_list args);
int	handle_specifier(char specifier, va_list args);
int	print_char(va_list args);
int	print_str(va_list args);
int	print_percentage(void);
int	convert_int_to_str(va_list args);

#endif /* FT_PRINTF_H */
