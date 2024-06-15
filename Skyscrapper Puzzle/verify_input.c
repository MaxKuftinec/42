/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:36:36 by xquah             #+#    #+#             */
/*   Updated: 2024/01/20 19:36:37 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	put_str(char *str);
void	rush(int **pov);
void	print_array(int *arr);

int *pov[4];

int    *process_input(char str[], int range1, int range2)
{
    int i;
    int *arr;
    int counter;

    arr = (int *) malloc(4);
    str += range1 * 2;
    i = range1 - 1;
    counter = 0;
    while (++i <= range2)
    {
        arr[counter] = *str - '0';
        str += 2;
        counter++;
    }
    return arr;
}

int	check_correct_input(char str[])
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (i % 2 == 0 && (str[i] <= '0' || str[i] >= '9'))
		{
			return (0);
		}
		else if (i % 2 != 0 && (str[i] != ' '))
		{
			return (0);
		}
	}
	if (i == 31)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int **verify(int argc, char *argv[])
{	
	if (argc != 2)
	{
		put_str("Error");
		put_str("\n");    
		return pov;
	}	
	if (!check_correct_input(argv[1]))
	{
		put_str("Error");
		put_str("\n");
		return pov;
	}
	pov[0] = process_input(argv[1], 0, 3);
	pov[1] = process_input(argv[1], 4, 7);
	pov[2] = process_input(argv[1], 8, 11);
	pov[3] = process_input(argv[1], 12, 15);
	return pov;
}


//Just to print out the
/*
	print_array(pov[0]);
	print_array(pov[1]);
	print_array(pov[2]);
	print_array(pov[3]);
*/