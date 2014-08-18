/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouliba <kcouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/17 02:51:16 by kcouliba          #+#    #+#             */
/*   Updated: 2014/08/18 21:00:53 by kcouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

static	char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*join;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(join = (char *)malloc(sizeof(*join) * len)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		join[i] = s2[j];
		++i;
		++j;
	}
	join[i] = '\0';
	return (join);
}

char			*ft_strappend(char *s1, char *s2)
{
	char	*reloc;

	reloc = NULL;
	if (!s1)
	{
		if (!(reloc = ft_strjoin("", s2)))
			return (NULL);
		return (reloc);
	}
	if (!(reloc = ft_strjoin(s1, s2)))
		return (NULL);
	free(s1);
	return (reloc);
}
