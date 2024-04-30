/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:21:15 by pximenez          #+#    #+#             */
/*   Updated: 2024/03/03 16:14:05 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_free_list(char **list, int check)
{
	int	i;

	i = 0;
	if (check == 0)
	{
		while (list[i] != 0)
		{
			free(list[i]);
			i++;
		}
	}
	else
	{
		while (i < check)
		{
			if (list[i] != 0)
				free(list[i]);
			i++;
		}
	}
	free(list);
	return ;
}

int	ft_count_flags(char *str)
{
	int	i;
	int	counter;

	i = 1;
	counter = 0;
	while (str[i])
	{
		if (str[i - 1] == ' ' && str[i] == '-')
			counter++;
		i++;
		if (str[i - 1] == ' ' && str[i] != ' ' && str[i] != '-')
			return (counter);
	}
	return (counter);
}

int	ft_split_count(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	*ft_pointer(char *str, int counter)
{
	int	i;
	int	c;

	i = 1;
	c = 0;
	while (str[i])
	{
		if (str[i - 1] == ' ' && str[i] == '-')
			c++;
		if (c == counter)
			break ;
		i++;
	}
	while (str[i] != ' ')
		i++;
	while (str[i] == ' ')
		i++;
	return (&str[i]);
}

void	ft_fix1(int splitcount, int counter, t_data *data, char *string)
{
	int		i;
	char	*str;

	i = 1;
	while (counter + i < splitcount)
	{
		free(data->commands1[counter + i]);
		data->commands1[counter + i] = 0;
		i++;
	}
	str = ft_pointer(string, counter);
	data->commands1[counter + 1] = ft_strdup(str);
}
