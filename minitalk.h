/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:13:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 19:43:30 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct sigaction	t_sigaction;

typedef struct s_data
{
	char	*message;
	char	character;
	int		bit_count;
}	t_data;

int	ft_strlen(const char *s);
int	ft_printf(const char *format, ...);
int	parse_format(const char *format, va_list args);
int	handle_specifier(char specifier, va_list args);
int	print_char(va_list args);
int	print_str(va_list args);
int	print_percentage(void);
int	convert_int_to_str(va_list args);

#endif /* TEST_MINITALK_H */
