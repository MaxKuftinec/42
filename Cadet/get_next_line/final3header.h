/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:53:46 by asapar            #+#    #+#             */
/*   Updated: 2024/06/11 17:53:49 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

enum e_num
{
	offset = 2 * sizeof(int)
};

void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_realloc(char *memory_block, char *buffer, size_t index, size_t last_index);
char	*get_next_line(int fd);

#endif
