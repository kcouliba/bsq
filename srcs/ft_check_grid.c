/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouliba <kcouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 21:25:39 by kcouliba          #+#    #+#             */
/*   Updated: 2014/08/18 23:15:47 by kcouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

static	int		init_grid(t_grid *grid)
{
	int		len;

	if (!(grid->grid = ft_strsplit(grid->line, '\n')))
		return (FAIL);
	if ((len = ft_strlen(grid->grid[0])) < 4)
		return (FAIL);
	grid->valid_chars[EMPTY] = grid->grid[0][len - 3];
	grid->valid_chars[BLOCK] = grid->grid[0][len - 2];
	grid->valid_chars[FULL] = grid->grid[0][len - 1];
	grid->grid[0][len - 3] = '\0';
	if ((grid->rows = ft_atoi(grid->grid[0])) < 1)
		return (FAIL);
	return (SUCCESS);
}

static	int		ft_check_row(char *row, char *cmp)
{
	int		i;
	int		j;
	int		found;

	i = 0;
	while (row[i])
	{
		j = 0;
		found = 0;
		while (cmp[j])
		{
			if (row[i] == cmp[j])
				found = 1;
			++j;
		}
		if (!found)
			return (FAIL);
		++i;
	}
	return (SUCCESS);
}

int				ft_check_grid(t_grid *grid)
{
	int		i;
	int		len;

	if (init_grid(grid) == FAIL)
		return (FAIL);
	i = 1;
	if ((len = ft_strlen(grid->grid[i])) < 1)
		return (FAIL);
	while (grid->grid[i])
	{
		if (ft_strlen(grid->grid[i]) != len)
			return (FAIL);
		if (ft_check_row(grid->grid[i], grid->valid_chars) == FAIL)
			return (FAIL);
		++i;
	}
	if (grid->rows != (i - 1))
		return (FAIL);
	return (SUCCESS);
}
