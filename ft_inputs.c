/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:21:15 by pximenez          #+#    #+#             */
/*   Updated: 2024/03/03 16:07:46 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_fix2(int splitcount, int counter, t_data *data, char *string)
{
	int		i;
	char	*str;

	i = 1;
	while (counter + i < splitcount)
	{
		free(data->commands2[counter + i]);
		data->commands2[counter + i] = 0;
		i++;
	}
	str = ft_pointer(string, counter);
	data->commands2[counter + 1] = ft_strdup(str);
}

void	ft_separate(t_data *data, char **argv)
{
	int	counter1;
	int	counter2;
	int	splitcount1;
	int	splitcount2;

	counter1 = ft_count_flags(argv[1]);
	counter2 = ft_count_flags(argv[2]);
	data->commands1 = ft_split(argv[1], ' ');
	data->commands2 = ft_split(argv[2], ' ');
	splitcount1 = ft_split_count(data->commands1);
	splitcount2 = ft_split_count(data->commands2);
	if (splitcount1 > counter1 + 1)
		ft_fix1(splitcount1, counter1, data, argv[1]);
	if (splitcount2 > counter2 + 1)
		ft_fix2(splitcount2, counter2, data, argv[2]);
	if (data->commands1 == NULL || data->commands2 == NULL)
	{
		perror("Malloc error");
		data->malloc_check = N_OK;
	}
	data->input_f = argv[0];
	data->output_f = argv[3];
}

t_data	*ft_command_data(char **argv, char **paths)
{
	int		i;
	char	*full_path;
	t_data	*data;

	data = ft_set_data();
	if (data == NULL)
		return (N_OK);
	ft_access(data, paths, argv, 1);
	ft_access(data, paths, argv, 2);
	if (data->found1 == N_OK)
	{
		data->commands1 = ft_split(argv[1], ' ');
		data->full_address1 = data->commands1[0];
	}
	if (data->found2 == N_OK)
	{
		data->commands2 = ft_split(argv[2], ' ');
		data->full_address2 = data->commands2[0];
	}
	ft_separate(data, argv);
	return (data);
}

t_data	*ft_get_paths(char **argv, char **envp)
{
	t_data	*data;
	char	**paths;
	int		i;

	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(ft_strchr(envp[i], '/'), ':');
			break ;
		}
		i++;
	}
	data = ft_command_data(argv, paths);
	ft_free_list(paths, 0);
	return (data);
}
