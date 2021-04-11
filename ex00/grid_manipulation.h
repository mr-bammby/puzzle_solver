/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_manipulation.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:55:11 by dbanfi            #+#    #+#             */
/*   Updated: 2021/03/21 09:00:49 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_MANIPULATION_H
# define GRID_MANIPULATION_H

void	grid_put_line(int grid[4][4], int type, int place, int line[4]);
int		grid_spot_fit(int grid[4][4], int row, int colum, int value);
int		grid_line_fit(int grid[4][4], int type, int place, int line[4]);
int		check_clue(int row[4], char clue[2]);

#endif
