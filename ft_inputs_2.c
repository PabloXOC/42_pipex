/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:21:15 by pximenez          #+#    #+#             */
/*   Updated: 2024/03/03 16:06:25 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

int	ft_strchrif(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (TRUE);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (TRUE);
	return (FALSE);
}

char	*ft_right_format(char **argv, char **paths, int i, int j)
{
	char	*str;
	char	*str2;
	char	**noarg;

	str = ft_strjoin(paths[i], "/");
	if (!(str))
		return (NULL);
	if (ft_strchrif(argv[j], ' ') == TRUE)
	{
		noarg = ft_split(argv[j], ' ');
		if (!(noarg))
		{
			free(str);
			return (NULL);
		}
		str2 = ft_strjoin(str, noarg[0]);
		free(noarg);
	}
	else
		str2 = ft_strjoin(str, argv[j]);
	free(str);
	return (str2);
}

t_data	*ft_set_data(void)
{
	t_data	*data;

	data = (t_data *) malloc (sizeof(t_data));
	if (!(data))
		return (NULL);
	data->fd_in = 0;
	data->fd_out = 0;
	data->found_c = 0;
	data->malloc_check = OK;
	data->execute_check = OK;
	data->found1 = N_OK;
	data->found1 = N_OK;
	return (data);
}

t_data	*ft_access2(t_data *data, char *full_path, int j)
{
	if (access(full_path, F_OK) == 0)
	{
		(data->found_c)++;
		if (j == 1)
		{
			data->found1 = OK;
			data->full_address1 = full_path;
		}
		if (j == 2)
		{
			data->found2 = OK;
			data->full_address2 = full_path;
		}
	}
	else
		free(full_path);
	return (data);
}

t_data	*ft_access(t_data *data, char **paths, char **argv, int j)
{
	char	*full_path;
	int		i;
	int		count;

	i = 0;
	while (paths[i] != 0)
	{
		full_path = ft_right_format(argv, paths, i, j);
		if (full_path == NULL)
		{
			perror("Malloc error");
			data->malloc_check = N_OK;
			return (data);
		}
		count = data->found_c;
		data = ft_access2(data, full_path, j);
		if (data->found_c > count)
			return (data);
		i++;
	}
	return (data);
}
