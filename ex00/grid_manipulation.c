/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanfi <dbanfi@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:06:42 by dbanfi            #+#    #+#             */
/*   Updated: 2021/03/20 16:16:59 by dbanfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** puts line into the grid
*/

void	grid_put_line(int grid[4][4], int type, int place, int line[4])
{
	int counter;

	counter = 0;
	while (counter < 4)
	{
		if (type == 0)
		{
			if (line[counter] == 0)
			{
				line[counter] = grid[place][counter];
			}
			grid[place][counter] = line[counter];
		}
		else if (type == 1)
		{
			if (line[counter] == 0)
			{
				line[counter] = grid[counter][place];
			}
			grid[counter][place] = line[counter];
		}
		counter++;
	}
}

int		check_clue(int row[4], char clue[2])
{
	int counter[3];
	int big_num[2];

	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0;
	big_num[0] = 0;
	big_num[1] = 0;
	while (counter[0] <= 3)
	{
		if (row[counter[0]] == 0)
		{
			return (0);
		}
		if (row[counter[0]] > big_num[0])
		{
			big_num[0] = row[counter[0]];
			counter[1]++;
		}
		if (row[3 - counter[0]] > big_num[1])
		{
			big_num[1] = row[3 - counter[0]];
			counter[2]++;
		}
		counter[0]++;
	}
	if (counter[1] == (clue[0] - '0') && counter[2] == (clue[1] - '0'))
		return (0);
	return (1);
}

/*
**	returns 1 if it doesn't fit returns 0 if it does
*/

int		grid_spot_fit(int grid[4][4], int row, int colum, int value)
{
	int empty;
	int cnt;

	cnt = 0;
	while (cnt < 4)
	{
		empty = grid[row][cnt] * value;
		if ((empty != 0) && (grid[row][colum] != value) && (cnt == colum))
		{
			return (1);
		}
		else if ((empty != 0) && (grid[row][cnt] == value) && (cnt != colum))
		{
			return (1);
		}
		empty = grid[cnt][colum] * value;
		if ((empty != 0) && (grid[cnt][colum] == value) && (cnt != row))
		{
			return (1);
		}
		cnt++;
	}
	return (0);
}

/*
**	returns number of spots that can't fit
*/

int		grid_line_fit(int grid[4][4], int type, int place, int line[4])
{
	int counter;
	int check;
	int out;

	counter = 0;
	check = 0;
	if (type == 0)
	{
		while (counter < 4)
		{
			out = grid_spot_fit(grid, place, counter, line[counter]);
			check = check + out;
			counter++;
		}
	}
	else if (type == 1)
	{
		while (counter < 4)
		{
			out = grid_spot_fit(grid, counter, place, line[counter]);
			check = check + out;
			counter++;
		}
	}
	return (check);
}
