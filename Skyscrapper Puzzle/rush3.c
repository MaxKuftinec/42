/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:57:57 by xquah             #+#    #+#             */
/*   Updated: 2024/01/21 14:02:23 by nsandrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_grid(int grid[4][4]);
void	print_array(int *arr);
void	put_str(char *str);
void	put_char(char c);

int	grid[4][4] = 
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}, 
		{0, 0, 0, 0} 
	};
int all_pos[24][4];
int count = 0;



void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generate_permutations(int arr[], int start, int end) {
    if (start == end) {
        // Store the current permutation in the global array
        int i = 0;
        while (i <= end) {
            all_pos[count][i] = arr[i];
            i++;
        }
        count++;
    } else {
        int i = start;
        while (i <= end) {
            // Swap the current element with the element at index 'start'
            swap(&arr[start], &arr[i]);
            // Recursively generate permutations for the remaining elements
            generate_permutations(arr, start + 1, end);
            // Backtrack: undo the swap to restore the original array
            swap(&arr[start], &arr[i]);
            i++;
        }
    }
}

int	duplicate_column(int column)
{
	int	seen[5] = {0};
	int i;
	i = -1;
	while (++i < 4)
	{
		if (seen[grid[i][column]] == 1)
			return (1);
		seen[grid[i][column]] = 1;
	}
	return (0);
}


int check_line(int arr[4], int left, int right)
{
	int i;
	int	counter;
	int	max;

	i = -1;
	counter = 0;
	max = 0;
	while (++i < 4)
	{
		if (arr[i] > max)
		{
			counter++;
			max = arr[i];
		}
	}
	if (counter != left)
		return (0);
	i = 4;
	counter = 0;
	max = 0;
	while (--i > -1)
	{
		if (arr[i] > max)
		{
			counter++;
			max = arr[i];	
		}
	}
	if (counter != right)
		return (0);
	return (1);
}

int check_column(int *povs[])
{
	int column, row;
	int arr[4];

	column = -1;
	while (++column < 4)
	{
		row = -1;
		while (++row < 4)
			arr[row] = grid[row][column];
		if (!check_line(arr, povs[0][column], povs[1][column]) || duplicate_column(column))
			return (0);
	}
	return (1);
}

int	recurse(int row, int *povs[])
{
	int i;
	int current_comb;

	current_comb = -1;
	if (row == 4)
	{
		if (check_column(povs) == 1)
			return (1);
		else
			return (0);
	}

	while (++current_comb < 24)
	{
		i = -1;
		while (++i < 4)
			grid[row][i] = all_pos[current_comb][i];	
		if (check_line(grid[row], povs[2][row], povs[3][row]))
		{
			if (recurse(row + 1, povs) == 1)
				return (1);
			else 
				continue;
		}
	}
	return (0);	
}

void	rush(int *povs[])
{
	int arr[] = {1, 2, 3, 4};
	int i;
	int side;

    generate_permutations(arr, 0, 3);
	recurse(0, povs);
	print_grid(grid);
}