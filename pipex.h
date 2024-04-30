/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:01:07 by pablo             #+#    #+#             */
/*   Updated: 2024/04/17 12:53:45 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//libft
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

# define N_OK 0
# define OK 1

typedef struct s_data
{
	char	*full_address1;
	char	*full_address2;
	char	**commands1;
	char	**commands2;
	char	*input_f;
	char	*output_f;
	int		fd_in;
	int		fd_out;
	int		found_c;
	int		found1;
	int		found2;
	int		malloc_check;
	int		execute_check;
}		t_data;

//input functions

t_data	*ft_get_paths(char **envp, char **argv);
t_data	*ft_command_data(char **argv, char **paths);
void	ft_separate(t_data *data, char **argv);
void	ft_fix2(int splitcount, int counter, t_data *data, char *string);

//input2 functions
int		ft_strchrif(const char *s, int c);
char	*ft_right_format(char **argv, char **paths, int i, int j);
t_data	*ft_set_data(void);
t_data	*ft_access2(t_data *data, char *full_path, int j);
t_data	*ft_access(t_data *data, char **paths, char **argv, int j);

//input3 functions
void	ft_fix1(int splitcount, int counter, t_data *data, char *string);
char	*ft_pointer(char *str, int counter);
int		ft_split_count(char **array);
int		ft_count_flags(char *str);
void	ft_free_list(char **list, int check);

int		ft_child_process(t_data *data, char **envp);
int		ft_child_process2(t_data *data, char **envp);

//pipe functions
int		ft_wait(pid_t frk1, pid_t frk2, int *pipe_fd);
int		ft_pipes2(t_data *data, int *pipe_fd, char **envp);
int		ft_pipes(t_data *data, char **envp);

//pipe2 functions
int		ft_pipe(int *pipe_fd);
int		ft_open(t_data *data, int *pipe_fd);
int		ft_dup2(t_data *data, int *pipe_fd);
int		ft_dup2_2(t_data *data, int *pipe_fd);

#endif
