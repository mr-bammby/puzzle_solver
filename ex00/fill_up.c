/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanfi <dbanfi@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 07:27:25 by dbanfi            #+#    #+#             */
/*   Updated: 2021/03/21 18:16:49 by dbanfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "grid_manipulation.h"
#include "step_two.h"

/*
** calculates and reurns missing numbber in chosen line
** puts place of empty slot into *place
*/

int		find_missing_number(int grid[4][4], int type, int place, int *place2)
{
	int value;
	int counter;

	value = 10;
	counter = 0;
	while (counter < 4)
	{
		if (type == 0)
		{
			value = value - grid[place][counter];
			if (grid[place][counter] == 0)
				*place2 = counter;
		}
		else if (type == 1)
		{
			value = value - grid[counter][place];
			if (grid[counter][place] == 0)
				*place2 = counter;
		}
		counter++;
	}
	return (value);
}

/*
** Finds last empty spot in line and fills it
** change is is set to != 0
*/

int		fillup_line(int grid[4][4], int type, int place, char clues[2][4][2])
{
	int error;
	int place2;
	int value;
	int status[2];
	int line[4];

	value = find_missing_number(grid, type, place, &place2);
	if (type == 0)
	{
		error = grid_spot_fit(grid, place, place2, value);
		if (error == 0)
		{
			grid[place][place2] = value;
		}
	}
	else
	{
		error = grid_spot_fit(grid, place2, place, value);
		if (error == 0)
		{
			grid[place2][place] = value;
		}
	}
	get_line(grid, type, place, line);
	status[0] = check_clue(line, clues[type][place]);
	get_line(grid, (type - 1) * (-1), place2, line);
	status[1] = check_clue(line, clues[(type - 1) * (-1)][place2]);
	if (status[0] == 1 || status[1] == 1)
		return (1);
	return (error);
}

/*
** Fills up row and colum with number of empty slots
** Returns 1 if puzzle is full else returns 0
*/

int		fillup_find_empty(int grid[4][4], int row[4], int colum[4])
{
	int counter[4];
	int full;

	counter[0] = 0;
	full = 1;
	while (counter[0] < 4)
	{
		counter[1] = 0;
		counter[2] = 0;
		counter[3] = 0;
		while (counter[1] < 4)
		{
			if (grid[counter[0]][counter[1]] == 0)
				counter[2]++;
			if (grid[counter[1]][counter[0]] == 0)
				counter[3]++;
			counter[1]++;
		}
		row[counter[0]] = counter[2];
		colum[counter[0]] = counter[3];
		if ((counter[2] != 0) || (counter[3] != 0))
			full = 0;
		counter[0]++;
	}
	return (full);
}

/*
**	Fills up rows/lines with 3 numbers filled
** Change is set to number different from 0 if algorihem fills at least 1 spot
** Returns 1 for unsolvable, returns -1 for full puzzle else returns 0
*/

int		fillup_grid(int grid[4][4], int *change, char clues[2][4][2])
{
	int temp[2];
	int row[4];
	int colum[4];

	temp[0] = 0;
	temp[1] = fillup_find_empty(grid, row, colum);
	if (temp[1] != 0)
		return (0);
	while (temp[0] < 4)
	{
		if (row[temp[0]] == 1)
		{
			temp[1] = fillup_line(grid, 0, temp[0], clues);
			*change = 1;
		}
		else if (colum[temp[0]] == 1)
		{
			temp[1] = fillup_line(grid, 1, temp[0], clues);
			*change = 1;
		}
		if (temp[1] != 0)
			return (1);
		temp[0]++;
	}
	return (0);
}
