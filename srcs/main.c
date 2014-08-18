/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouliba <kcouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/16 16:30:23 by kcouliba          #+#    #+#             */
/*   Updated: 2014/08/18 23:34:16 by kcouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

static	char	*ft_stdin(void)
{
	char	*str;
	int		ret;
	char	buf[BUF_SIZE + 1];

	str = NULL;
	while ((ret = read(0, buf, BUF_SIZE)) < 0)
		;
	if (ret < 0)
		ft_print_error("error while reading\n");
	buf[ret] = '\0';
	str = ft_strappend(str, buf);
	return (str);
}

static	char	*ft_store_grid(char *file)
{
	char	*str;
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	str = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strappend(str, buf);
	}
	if (ret < 0)
		ft_print_error("error while reading\n");
	if (close(fd) < 0)
		ft_print_error("error while closing\n");
	return (str);
}

int				main(int argc, char **argv)
{
	t_grid	grid;
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if ((!(grid.line = ft_store_grid(argv[i])))
				|| (ft_check_grid(&grid) == FAIL))
				ft_putstr_fd("map error\n", 2);
			++i;
		}
	}
	else
	{
		if (!(grid.line = ft_stdin()))
			ft_print_error("can't read from standard input\n");
	}
	return (0);
}
