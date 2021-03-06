/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:55:58 by pperea-d          #+#    #+#             */
/*   Updated: 2020/07/14 17:04:43 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num(int nb)
{
	if (nb == 0)
		return (1);
	return (1 + num(nb / 10));
}

static char		*operate(char *s, int num, int i)
{
	unsigned int	l;

	l = 0;
	if (num == 0)
		*s = num + 48;
	else if (num < 0)
	{
		*s = '-';
		l = num * (-1);
	}
	else
		l = num;
	s[i + 1] = '\0';
	while (l != 0)
	{
		s[i] = l % 10 + 48;
		l = l / 10;
		i--;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*dst;

	if (n > 0)
		len = num(n) - 1;
	else
		len = num(n);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	return (operate(dst, n, len - 1));
}
