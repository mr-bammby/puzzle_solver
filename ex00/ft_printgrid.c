/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printgrid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanfi <dbanfi@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 09:57:21 by ahellema          #+#    #+#             */
/*   Updated: 2021/03/21 18:09:39 by dbanfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printchar(int c)
{
	if (c != 3)
		write(1, " ", 1);
	else
		write(1, "\n", 1);
}

void	ft_printgrid(int grid[4][4])
{
	int		row;
	int		column;
	int		print;

	row = 0;
	column = 0;
	while (row <= 3)
	{
		while (column <= 3)
		{
			print = grid[row][column] + 48;
			write(1, &print, 1);
			ft_printchar(column);
			column++;
		}
		column = 0;
		row++;
	}
	write(1,"\n", 1);
}
