/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanfi <dbanfi@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 08:21:50 by dbanfi            #+#    #+#             */
/*   Updated: 2021/03/21 18:15:04 by dbanfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** make copy of grid into frid_cpy
*/
#include "fill_up.h"
#include "grid_manipulation.h"
#include "step_one.h"
#include "step_two.h"
#include "ft_printgrid.h"
#include <unistd.h>

void	copy_grid(int grid[4][4], int grid_cpy[4][4])
{
	int counter[2];

	counter[0] = 0;
	while (counter[0] < 4)
	{
		counter[1] = 0;
		while (counter[1] < 4)
		{
			grid_cpy[counter[0]][counter[1]] = grid[counter[0]][counter[1]];
			counter[1]++;
		}
		counter[0]++;
	}
}

/*
** Find and return best spot for step 3
*/

void	find_next_spot(int grid[4][4], int place[2])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (grid[i][j] == 0)
			{
				place[0] = i;
				place[1] = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	alg_step_three(char clues[2][4][2], int grid[4][4])
{
	int status;
	int status2[2];
	int old_grid[4][4];
	int place[2];
	int num;
	int line[4];

	write(1, "step3\n", 6);
	ft_printgrid(grid);
	copy_grid(grid, old_grid);
	find_next_spot(grid, place);
	num = 1;
	while (num <= 4)
	{	
		status = grid_spot_fit(grid, place[0], place[1], num);
		get_line(grid, 0, place[0], line);
		status2[0] = check_clue(line, clues[0][place[0]]);
		get_line(grid, 1, place[1], line);
		status2[1] = check_clue(line, clues[1][place[1]]);
		if (status == 1 || status2[0] == 1 || status2[1] == 1)
			num++;
		else
		{
			grid[place[0]][place[1]] = num;
			write(1, "befor2\n", 7);
			ft_printgrid(grid);
			status = alg_step_two(clues, grid);
			write(1, "after2\n", 7);
			ft_printgrid(grid);
			if (status == 0)
			{
				status = alg_step_three(clues, grid);
				if (status == 0)
					return (0);
				else
					copy_grid(old_grid, grid);
					num++;
			}
			else if (status == 1)
			{
				copy_grid(old_grid, grid);
				num++;
			}
			else
				return (0);
		}
	}
	return (1);
}
