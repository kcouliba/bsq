/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouliba <kcouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 20:07:45 by kcouliba          #+#    #+#             */
/*   Updated: 2014/08/18 23:32:04 by kcouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define	BUF_SIZE		4096
# define	EXIT_SUCCESS	0
# define	EXIT_FAILURE	1
# define	SUCCESS			0
# define	FAIL			1
# define	EMPTY			0
# define	BLOCK			1
# define	FULL			2

typedef	struct	s_grid
{
	char	**grid;
	char	*line;
	int		rows;
	char	valid_chars[3];
}				t_grid;

typedef	struct	s_point
{
	int		x;
	int		y;
}				t_point;

char			*ft_strappend(char *s1, char *s2);

char			**ft_strsplit(char *s, char sep);

int				ft_pow(int nb, int exp);
int				ft_strlen(char *s);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(char *str);
int				ft_check_grid(t_grid *grid);

void			ft_print_error(char *errmsg);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);

#endif
