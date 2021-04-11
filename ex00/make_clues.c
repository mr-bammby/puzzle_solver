/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_clues.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanfi <dbanfi@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:13:58 by sbienias          #+#    #+#             */
/*   Updated: 2021/03/21 17:42:21 by dbanfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "step_one.h"
#include "ft_printgrid.h"

int		ft_populate_clues(char *string, char *array)
{
	int		counter;
	int		clue_counter;

	clue_counter = 0;
	counter = 0;
	while (*(string + counter) != '\0')
	{
		if (*(string + counter) >= '1' && *(string + counter) <= '4')
		{
			if (clue_counter < 16)
				array[clue_counter] = *(string + counter);
			clue_counter++;
			counter++;
		}
		else if (*(string + counter) == ' ')
			counter++;
		else
			return (1);
	}
	if (counter != 31 || clue_counter != 16)
		return (1);
	return (0);
}

void	create_clues_array(char *array, char clues_array[2][4][2])
{
	int		i;
	int		j;
	int		k;
	int		clue_counter;

	clue_counter = 0;
	i = 1;
	while (i >= 0)
	{
		k = 0;
		while (k < 2)
		{
			j = 0;
			while (j < 4)
			{
				clues_array[i][j][k] = *(array + clue_counter);
				clue_counter++;
				j++;
			}
			k++;
		}
		i--;
	}
	return ;
}

void	grid_setup(int grid[4][4])
{
	int counter;
	int counter1;

	counter = 0;
	while (counter < 4)
	{
		counter1 = 0;
		while (counter1 < 4)
		{
			grid[counter][counter1] = 0;
			counter1++;
		}
		counter++;
	}
}

int		main(int argc, char **argv)
{
	int		grid[4][4];
	char	clues_array[2][4][2];
	char	clues[16];
	int		error;

	if (argc == 2)
	{
		error = ft_populate_clues(*(argv + 1), clues);
		if (error == 0)
		{
			create_clues_array(clues, clues_array);
			if (error == 0)
			{
				grid_setup(grid);
				error = alg_steps(clues_array, grid);
				if (error == 0)
				{
					ft_printgrid(grid);
					return (0);
				}
			}
		}
	}
	write(1, "Error\n", 6);
	return (1);
}
