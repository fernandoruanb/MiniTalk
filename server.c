/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:12:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/18 10:41:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_data	g_data = {NULL, 0, 0};

static char	*ft_strcpy(char *dest, const char *src, char c)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = c;
	dest[index + 1] = '\0';
	return (dest);
}

static void	append_char(char c)
{
	char	*new_str;
	int		length;

	if (g_data.message)
		length = ft_strlen(g_data.message);
	else
		length = 0;
	new_str = (char *)malloc(length + 2);
	if (!new_str)
		return ;
	if (g_data.message)
	{
		new_str = ft_strcpy(new_str, g_data.message, c);
		free(g_data.message);
		g_data.message = new_str;
	}
	else
	{
		g_data.message = new_str;
		g_data.message[length] = c;
		g_data.message[length + 1] = '\0';
	}
}

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;
	g_data.character = g_data.character << 1;
	if (signal == SIGUSR2)
		g_data.character |= 1;
	g_data.bit_count++;
	if (g_data.bit_count == 8)
	{
		append_char(g_data.character);
		if (g_data.character == '\0')
		{
			ft_printf("%s\n", g_data.message);
			if (g_data.message)
			{
				free(g_data.message);
				g_data.message = NULL;
				kill(info->si_pid, SIGUSR1);
			}
		}
		g_data.character = 0;
		g_data.bit_count = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t		pid;
	t_sigaction	new_connection;

	pid = getpid();
	ft_printf("Welcome to Fernando's server. =D\n");
	ft_printf("The server PID is: %d\n", pid);
	new_connection.sa_sigaction = handle_signal;
	new_connection.sa_flags = SA_SIGINFO;
	sigemptyset(&new_connection.sa_mask);
	sigaction(SIGUSR1, &new_connection, NULL);
	sigaction(SIGUSR2, &new_connection, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
