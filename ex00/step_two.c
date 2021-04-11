/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanfi <dbanfi@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:37:28 by dbanfi            #+#    #+#             */
/*   Updated: 2021/03/21 18:07:44 by dbanfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid_manipulation.h"

#define NUMBER_OF_CHECKS_ST2  19

char	g_cst2[NUMBER_OF_CHECKS_ST2][3][4] = {
	{{"3200"}, {"2040"}, {"2341"}},
	{{"3200"}, {"0043"}, {"1243"}},
	{{"3200"}, {"0240"}, {"1243"}},
	{{"2300"}, {"0402"}, {"1432"}},
	{{"2300"}, {"3400"}, {"3421"}},
	{{"2300"}, {"0420"}, {"3421"}},
	{{"2200"}, {"0042"}, {"3142"}},
	{{"2200"}, {"2400"}, {"2413"}},
	{{"2200"}, {"0041"}, {"3241"}},
	{{"2200"}, {"1400"}, {"1423"}},
	{{"2200"}, {"0402"}, {"3412"}},
	{{"2200"}, {"2040"}, {"2143"}},
	{{"2200"}, {"2400"}, {"2413"}},
	{{"2200"}, {"0043"}, {"2143"}},
	{{"2200"}, {"3400"}, {"3412"}},
	{{"2200"}, {"1000"}, {"1423"}},
	{{"2200"}, {"0001"}, {"3241"}},
	{{"1300"}, {"4200"}, {"4231"}},
	{{"3100"}, {"0024"}, {"1324"}},
};

int		check_comb(int line[4], int test)
{
	int found;
	int i;

	found = 0;
	i = 0;
	while (i < 4)
	{
		if ((line[i] + '0') != g_cst2[test][1][i])
		{
			found = 1;
		}
		i++;
	}
	return (found);
}

int		check_clues_s2(int line[4], char clue_pair[2], int line_out[4])
{
	int counter;
	int found;

	counter = 0;
	while (counter < NUMBER_OF_CHECKS_ST2)
	{
		if (clue_pair[0] == g_cst2[counter][0][0])
		{
			if (clue_pair[1] == g_cst2[counter][0][1])
			{
				found = check_comb(line, counter);
				if (found == 0)
				{
					line_out[0] = g_cst2[counter][2][0] - '0';
					line_out[1] = g_cst2[counter][2][1] - '0';
					line_out[2] = g_cst2[counter][2][2] - '0';
					line_out[3] = g_cst2[counter][2][3] - '0';
					return (1);
				}
			}
		}
		counter++;
	}
	return (0);
}

void	get_line(int grid[4][4], int type, int place, int line[4])
{
	int counter;

	counter = 0;
	if (type == 0)
	{
		while (counter < 4)
		{
			line[counter] = grid[place][counter];
			counter++;
		}
	}
	else if (type == 1)
	{
		while (counter < 4)
		{
			line[counter] = grid[counter][place];
			counter++;
		}
	}
}

int		alg_step_two_main(char clues[2][4][2], int grid[4][4], int *change)
{
	int	cnter[5];
	int	out[4];
	int	line[4];

	cnter[0] = 0;
	while (cnter[0] < 2)
	{
		cnter[1] = 0;
		while (cnter[1] < 4)
		{
			get_line(grid, cnter[0], cnter[1], line);
			cnter[2] = check_clues_s2(line, clues[cnter[0]][cnter[1]], out);
			if (cnter[2] == 1)
			{
				cnter[3] = grid_line_fit(grid, cnter[0], cnter[1], out);
				if (cnter[3] != 0)
					return (1);
				cnter[4] = 0;
				while (cnter[4] < 4)
				{
					get_line(grid, (cnter[0] - 1) * (-1), cnter[5], line);
					cnter[3] = check_clue(line, clues[(cnter[0] - 1) * (-1)][cnter[5]]);
					if (cnter[3] != 0)
						return (1);
					cnter[5]++;
				}
				grid_put_line(grid, cnter[0], cnter[1], out);
				*change = 1;
			}
			cnter[1]++;
		}
		cnter[0]++;
	}
	return (0);
}
