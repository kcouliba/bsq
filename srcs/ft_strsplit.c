/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouliba <kcouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 21:28:02 by kcouliba          #+#    #+#             */
/*   Updated: 2014/08/18 23:00:03 by kcouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

static	int		ft_size(char *s, char sep)
{
	int		size;
	int		i;

	if (!s)
		return (0);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == sep)
			++size;
		++i;
	}
	return (size);
}

static	char	*ft_strndup(char *s, int n)
{
	int		i;
	char	*ndup;

	if (!s)
		return (NULL);
	i = 0;
	if (!(ndup = (char *)malloc(sizeof(*ndup) * ft_strlen(s) + 1)))
		return (NULL);
	while (i < n)
	{
		ndup[i] = s[i];
		++i;
	}
	ndup[i] = '\0';
	return (ndup);
}

char			**ft_strsplit(char *s, char sep)
{
	int		i;
	int		j;
	int		size;
	char	**split;

	size = ft_size(s, sep);
	if (!(split = (char **)malloc(sizeof(**split) * ft_strlen(s) * size + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i++])
	{
		if (s[i] == sep)
		{
			if (!(split[j++] = ft_strndup(s, i)))
				return (NULL);
			s += (i + 1);
			i = 0;
		}
	}
	split[j] = NULL;
	return (split);
}
