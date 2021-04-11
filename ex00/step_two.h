/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_two.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanfi <dbanfi@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:55:11 by dbanfi            #+#    #+#             */
/*   Updated: 2021/03/21 18:01:26 by dbanfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STEP_TWO_H
# define STEP_TWO_H

int     alg_step_two_main(char clues[2][4][2], int grid[4][4], int *change);
void	get_line(int grid[4][4], int type, int place, int line[4]);

#endif
