/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouliba <kcouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/11 18:17:09 by kcouliba          #+#    #+#             */
/*   Updated: 2014/08/18 22:14:38 by kcouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

static	int	ft_isnum(char c)
{
	if ((c < 48) || (c > 57))
		return (0);
	return (1);
}

int			ft_atoi(char *str)
{
	int		atoi;
	int		neg;
	int		i;
	int		len;

	if (!str)
		return (0);
	neg = ((*str == '-') ? -1 : 1);
	str += (((*str == '-') || (*str == '+')) ? 1 : 0);
	atoi = 0;
	len = 0;
	i = 0;
	while (ft_isnum(str[len]))
		++len;
	while (i < len)
	{
		atoi += (ft_pow(10, (len - i - 1)) * (str[i] - 48));
		++i;
	}
	atoi *= neg;
	return (atoi);
}
