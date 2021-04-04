/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 20:42:06 by jinyoo            #+#    #+#             */
/*   Updated: 2021/04/04 16:42:31 by slee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_one_to_four(char c);
int		is_blank_null(char c);
void	set_board(char *c_up, char *c_down, char *r_left, char *r_right);
//void	fill_in_board();

char g_numbers[17];
char g_column_up[4];
char g_column_down[4];
char g_row_left[4];
char g_row_right[4];

void	numbers_array(char *views)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (views[i])
	{
		if (is_one_to_four(views[i]) && is_blank_null(views[i + 1]))
			g_numbers[j++] = views[i];
		i++;
	}
}

void	divide_views(char *views)
{
	int i;

	i = 0;
	numbers_array(views);
	while (g_numbers[i])
	{
		if (i < 4)
			g_column_up[i] = g_numbers[i];
		else if (i >= 4 && i < 8)
			g_column_down[i - 4] = g_numbers[i];
		else if (i >= 8 && i < 12)
			g_row_left[i - 8] = g_numbers[i];
		else
			g_row_right[i - 12] = g_numbers[i];
		i++;
	}
}

void	rush(char *views)
{
	divide_views(views);
	set_board(g_column_up, g_column_down, g_row_left, g_row_right);
	//fill_in_board();
}
