/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:12:49 by asapar            #+#    #+#             */
/*   Updated: 2024/03/13 15:12:49 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*sub;
	char	*subassign;

	str_len = ft_strlen(s);
	if (start > str_len)
		start = str_len;
	if ((str_len - start) > len)
		sub = (char *)malloc((len + 1) * sizeof(char));
	else
		sub = (char *)malloc((str_len - start + 1) * sizeof(char));
	if (!sub)
		return (0);
	subassign = sub;
	while (len-- && s[start])
		*subassign++ = s[start++];
	*subassign = 0;
	return (sub);
}
