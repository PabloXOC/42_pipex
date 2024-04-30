/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:19:41 by pximenez          #+#    #+#             */
/*   Updated: 2024/03/03 16:15:17 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

int	ft_wait(pid_t frk1, pid_t frk2, int *pipe_fd)
{
	int	status1;
	int	status2;

	if (frk1 == -1 || frk2 == -1)
	{
		perror("creating fork");
		return (N_OK);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(frk1, &status1, 0);
	waitpid(frk2, &status2, 0);
	return (OK);
}

int	ft_pipes2(t_data *data, int *pipe_fd, char **envp)
{
	pid_t	frk1;
	pid_t	frk2;

	frk1 = fork();
	if (frk1 == 0)
	{
		if (ft_dup2(data, pipe_fd) == N_OK)
			return (N_OK);
		if (ft_child_process(data, envp) == N_OK)
			return (N_OK);
	}
	frk2 = fork();
	if (frk2 == 0)
	{
		if (ft_dup2_2(data, pipe_fd) == N_OK)
			return (N_OK);
		if (ft_child_process2(data, envp) == N_OK)
			return (N_OK);
	}
	return (ft_wait(frk1, frk2, pipe_fd));
}

int	ft_pipes(t_data *data, char **envp)
{
	int		pipe_fd[2];

	if (ft_pipe(pipe_fd) == N_OK)
		return (N_OK);
	if (ft_open(data, pipe_fd) == N_OK)
		return (N_OK);
	if (ft_pipes2(data, pipe_fd, envp) == N_OK)
		return (N_OK);
	return (OK);
}
