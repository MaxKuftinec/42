/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:04:31 by asapar            #+#    #+#             */
/*   Updated: 2024/03/13 15:04:33 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s);
	if (s == NULL || set == NULL)
		return (NULL);
	while (ft_strchr(set, s[i]) && s[i] != '\0')
		i++;
	while (ft_strchr(set, s[j - 1]) && j > i)
		j--;
	str = (char *) malloc(sizeof(char) * (j - i + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[i], j - i + 1);
	return (str);
}
