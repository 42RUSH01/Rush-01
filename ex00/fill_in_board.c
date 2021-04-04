/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_in_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:39:30 by jinyoo            #+#    #+#             */
/*   Updated: 2021/04/04 16:34:12 by slee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern char g_board[4][4];
extern char g_column_up[4];
extern char g_column_down[4];
extern char g_row_left[4];
extern char g_row_right[4];
int g_flag;
int g_check[4] = {0, 0, 0, 0};

int	is_valid_box_height(int x, int y, char h)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (h == g_board[y][i])
			return (0);
		if (h == g_board[i][x])
			return (0);
	}
	return (1);
}

int	check_row_views(int y)
{

}

void	solution_row(int x, int y, int h)
{
	if (g_board[y][x] == '0')
	{
		if (!is_valid_box_height(x, y, h))
			solution_row(x, y, h + 1);    //ret 0
		else
		{
			board[y][x] = '0' + h;        //ret 1
			*g_check++ = h;
		}
	}
	if (g_check[3] != 0 && check_row_views(y))
		solution_column();
	if 

}

void	fill_in_board(void)
{
	g_flag = 1;
	solution_row(0, 0, 1);	
}
