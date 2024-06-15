/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:59:07 by xquah             #+#    #+#             */
/*   Updated: 2024/01/20 11:59:14 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	print_array(int *arr)
{
	int i;
	
	i = -1;
	while (++i < 4)
	{
		put_char(arr[i] + '0');
		put_char(' ');
	}
	put_char('\n');
}

void	print_grid(int grid[4][4])
{
	int	row, k;
	int	column;
	int test[4] = {4, 1, 2, 3};

	row= -1;
	k = 0;
	while(++row < 4)
	{
		column = -1;
		while (++column < 4)
		{
			if (grid[row][column] == test[column])
				k++;
			
		}
	}

	row = -1;
	while (++row < 4)
	{
		column = -1;
		while (++column < 4)
		{
			if (grid[row][column] == 0 || k == 16)
			{
				write(1, "Error", 5);
				write(1, "\n", 1);
				return;
			}
		}
	}
	
	
	row = -1;
	while (++row < 4)
	{
		column = -1;
		while (++column < 4)
		{
			put_char(grid[row][column] + '0');
			put_char(' ');
		}
		put_char('\n');
	}
}

void	put_str(char *str)
{
	int	i;
	
	i = -1;
	while (str[++i] != '\0')
	{
		put_char(str[i]);
	}
}