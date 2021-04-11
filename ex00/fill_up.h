/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_up.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:55:11 by dbanfi            #+#    #+#             */
/*   Updated: 2021/03/21 15:20:02 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_UP_H
# define FILL_UP_H

int fillup_find_empty(int grid[4][4], int row[4], int colum[4]);
int	fillup_grid(int grid[4][4], int *change, char clues[2][4][2]);

#endif
