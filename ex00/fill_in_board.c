/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_in_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:39:30 by jinyoo            #+#    #+#             */
/*   Updated: 2021/04/04 21:32:20 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern char g_board[4][4];
extern char g_column_up[4];
extern char g_column_down[4];
extern char g_row_left[4];
extern char g_row_right[4];
int g_flag;
char g_check[4] = {'0', '0', '0', '0'};

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

void	check_views(int y)
{
	char max_left;
	char max_right;

	max_left = g_check[0];
	max_left = g_check[3];

	if (check_view_controller(1, 1, max_lt, max_rt, y))
		fill_board();
}

int		check_views_controller(int cnt_lt, int cnt_rt, int max_lt, int max_rt, int y)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (max_lt < g_check[i])
		{
			max_lt = g_check[i];
			cnt_lt++;
		}
		if (max_rt < g_check[3 -i])
		{
			max_rt = g_check[3 - i];
			cnt_rt++;
		}
		i++;
	}
	if (cnt_lt != g_row_left[y])
		return (0);
	if (cnr_rt != g_row_right[y])
		return (0);
	return (1);
}

void	solution_row(int x, int y, int h, int line)
{
	if (x == 4)
		return ;
	if (line == 3)
	{
		check _views(y);
		return ;
	}
	if (g_board[y][x] == '0')
	{


		
		

}

void	fill_in_board(void)
{
	g_flag = 1;
	solution_row(0, 0, 1, 1);	
}
