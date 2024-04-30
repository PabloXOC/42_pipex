/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:45:18 by pximenez          #+#    #+#             */
/*   Updated: 2024/03/01 18:21:28 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

int	ft_pipex(char **argv, char **envp)
{
	t_data	*data;

	data = ft_get_paths(argv, envp);
	if (data->malloc_check == N_OK || data->execute_check == N_OK)
		return (N_OK);
	if (ft_pipes(data, envp) == N_OK)
		return (N_OK);
	return (OK);
}

int	main(int argc, char **argv, char **envp)
{
	argc--;
	argv++;
	if (argc == 4)
	{
		if (ft_pipex(argv, envp) == N_OK)
			return (1);
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
}
