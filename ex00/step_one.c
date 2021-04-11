/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanfi <dbanfi@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:37:28 by dbanfi            #+#    #+#             */
/*   Updated: 2021/03/21 18:17:40 by dbanfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid_manipulation.h"
#include "step_two.h"
#include "step_three.h"
#include "ft_printgrid.h"
#include "fill_up.h"

#define NUMBER_OF_CHECKS_ST1  8
#define NUMBER_OF_CHECKS_ST2  20

char	g_cst1[NUMBER_OF_CHECKS_ST1][2][4] = {
	{{"1400"}, {"4321"}},
	{{"4100"}, {"1234"}},
	{{"1200"}, {"4003"}},
	{{"2100"}, {"3004"}},
	{{"1300"}, {"4000"}},
	{{"3100"}, {"0004"}},
	{{"2300"}, {"0400"}},
	{{"3200"}, {"0040"}}
};

int		check_clues_s1(char clue_pair[2], int line_out[4])
{
	int counter;

	counter = 0;
	while (counter < NUMBER_OF_CHECKS_ST1)
	{
		if (clue_pair[0] == g_cst1[counter][0][0])
		{
			if (clue_pair[1] == g_cst1[counter][0][1])
			{
				line_out[0] = g_cst1[counter][1][0] - '0';
				line_out[1] = g_cst1[counter][1][1] - '0';
				line_out[2] = g_cst1[counter][1][2] - '0';
				line_out[3] = g_cst1[counter][1][3] - '0';
				return (1);
			}
		}
		counter++;
	}
	return (0);
}

int		alg_step_one(char clues[2][4][2], int grid[4][4])
{
	int	cnter[4];
	int	out[4];

	cnter[0] = 0;
	while (cnter[0] < 2)
	{
		cnter[1] = 0;
		while (cnter[1] < 4)
		{
			cnter[2] = check_clues_s1(clues[cnter[0]][cnter[1]], out);
			if (cnter[2] == 1)
			{
				cnter[3] = grid_line_fit(grid, cnter[0], cnter[1], out);
				if (cnter[3] != 0)
					return (1);
				grid_put_line(grid, cnter[0], cnter[1], out);
			}
			cnter[1]++;
		}
		cnter[0]++;
	}
	return (0);
}

void	helper_fun_alg_s2(char clues[2][4][2], int grid[4][4], int change[3])
{
	change[0] = 0;
	change[2] = alg_step_two_main(clues, grid, &change[0]);
	change[1] = change[1] + change[0];
}

int		alg_step_two(char clues[2][4][2], int grid[4][4])
{
	int		change[3];
	int		dummy[2][4];

	change[0] = 1;
	while (change[0] != 0)
	{
		change[0] = 0;
		change[2] = fillup_grid(grid, &change[0], clues);
		if (change[2] == 1)
			return (1);
	}
	change[0] = 1;
	change[1] = 0;
	while (change[0] != 0)
	{
		helper_fun_alg_s2(clues, grid, change);
		if (change[2] == 1)
			return (1);
	}
	if (change[1] != 0)
		alg_step_two(clues, grid);
	change[2] = fillup_find_empty(grid, dummy[0], dummy[1]);
	if (change[2] == 1)
		return (-1);
	return (0);
}

int		alg_steps(char clues[2][4][2], int grid[4][4])
{
	int status;

	status = alg_step_one(clues, grid);
	ft_printgrid(grid);
	if (status == 0)
	{
		status = alg_step_two(clues, grid);
		ft_printgrid(grid);
		if (status == 1)
			return (1);
		else if (status == 0)
		{
			status = alg_step_three(clues, grid);
			ft_printgrid(grid);
			if (status == 1)
				return (1);
		}
	}
	else
		return (1);
	return (0);
}
