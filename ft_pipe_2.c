/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:19:41 by pximenez          #+#    #+#             */
/*   Updated: 2024/03/03 16:17:39 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

int	ft_pipe(int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
	{
		perror("opening pipe");
		return (N_OK);
	}
	return (OK);
}

int	ft_open(t_data *data, int *pipe_fd)
{
	data->fd_in = open(data->input_f, O_RDONLY);
	if (data->fd_in == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		perror("opening the file1");
		return (N_OK);
	}
	data->fd_out = open(data->output_f, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->fd_out == -1)
	{
		close(data->fd_in);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		perror("opening the file2");
		return (N_OK);
	}
	return (OK);
}

int	ft_dup2(t_data *data, int *pipe_fd)
{
	if (dup2(data->fd_in, STDIN_FILENO) == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(data->fd_in);
		perror("failed dup2");
		return (N_OK);
	}
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(data->fd_in);
		perror("failed dup2");
		return (N_OK);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(data->fd_in);
	return (OK);
}

int	ft_dup2_2(t_data *data, int *pipe_fd)
{
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(data->fd_out);
		perror("failed dup2");
		return (N_OK);
	}
	if (dup2(data->fd_out, STDOUT_FILENO) == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(data->fd_out);
		perror("failed dup2");
		return (N_OK);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(data->fd_out);
	return (OK);
}
