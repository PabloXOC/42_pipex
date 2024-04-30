/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:19:41 by pximenez          #+#    #+#             */
/*   Updated: 2024/03/02 11:09:11 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

int	ft_child_process(t_data *data, char **envp)
{
	if (execve(data->full_address1, data->commands1, envp) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(data->commands1[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		return (N_OK);
	}
	return (OK);
}

int	ft_child_process2(t_data *data, char **envp)
{
	if (execve(data->full_address2, data->commands2, envp) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(data->commands2[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		return (N_OK);
	}
	return (OK);
}
