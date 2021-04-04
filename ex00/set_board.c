/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:45:52 by jinyoo            #+#    #+#             */
/*   Updated: 2021/04/04 17:20:39 by slee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char g_board[4][4] = {{'0', '0', '0', '0'}, {'0', '0', '0', '0'}, \
	{'0', '0', '0', '0'}, {'0', '0', '0', '0'}};

void	set_otf_in_board(int idx, char checker)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (checker == 'u')
			g_board[i][idx] = '0' + i + 1;
		if (checker == 'd')
			g_board[i][idx] = '0' + 4 - i;
		if (checker == 'l')
			g_board[idx][i] = '0' + i + 1;
		if (checker == 'r')
			g_board[idx][i] = '0' + 4 - i;
		i++;
	}
}

void	set_four_in_board(int idx, char checker)
{
	if (checker == 'u')
		g_board[0][idx] = '4';
	if (checker == 'd')
		g_board[3][idx] = '4';
	if (checker == 'l')
		g_board[idx][0] = '4';
	if (checker == 'r')
		g_board[idx][3] = '4';
}

void	four_setter(int idx, char checker)
{
	if (checker == 'u')
		g_board[1][idx] = '4';
	if (checker == 'd')
		g_board[2][idx] = '4';
	if (checker == 'l')
		g_board[idx][1] = '4';
	if (checker == 'r')
		g_board[idx][2] = '4';
}

void	view_four_handler(char *c_up, char *c_down, char *r_left, char *r_right)
{
	int four_idx;

	four_idx = 0;
	while (four_idx < 4)
	{
		if (c_up[four_idx] == '4')
			set_otf_in_board(four_idx, 'u');
		if (c_down[four_idx] == '4')
			set_otf_in_board(four_idx, 'd');
		if (r_left[four_idx] == '4')
			set_otf_in_board(four_idx, 'l');
		if (r_right[four_idx] == '4')
			set_otf_in_board(four_idx, 'r');
		four_idx++;
	}
}

void	view_one_handler(char *c_up, char *c_down, char *r_left, char *r_right)
{
	int one_idx;

	one_idx = 0;
	while (one_idx < 4)
	{
		if (c_up[one_idx] == '1')
			set_four_in_board(one_idx, 'u');
		if (c_down[one_idx] == '1')
			set_four_in_board(one_idx, 'd');
		if (r_left[one_idx] == '1')
			set_four_in_board(one_idx, 'l');
		if (r_right[one_idx] == '1')
			set_four_in_board(one_idx, 'r');
		one_idx++;
	}
}

void	view_two_three_handler(char *c_up, char *c_down, \
		char *r_left, char *r_right)
{
	int idx;

	idx = 0;
	while (idx < 4)
	{
		if (c_up[idx] == '2' && c_down[idx] == '3')
			four_setter(idx, 'u');
		if (c_down[idx] == '2' && c_up[idx] == '3')
			four_setter(idx, 'd');
		if (r_left[idx] == '2' && r_right[idx] == '3')
			four_setter(idx, 'l');
		if (r_right[idx] == '2' && r_left[idx] == '3')
			four_setter(idx, 'r');
		idx++;
	}
}

void	three_setter(int idx, char checker)
{
	if (checker == 'u')
		g_board[2][idx] = '3';
	if (checker == 'd')
		g_board[1][idx] = '3';
	if (checker == 'l')
		g_board[idx][2] = '3';
	if (checker == 'r')
		g_board[idx][1] = '3';
}

void	view_one_three_handler(char *c_up, char *c_down, \
		char *r_left, char *r_right)
{
	int idx;

	idx = 0;
	while (idx < 4)
	{
		if (c_up[idx] == '1' && c_down[idx] == '3')
			three_setter(idx, 'u');
		if (c_down[idx] == '1' && c_up[idx] == '3')
			three_setter(idx, 'd');
		if (r_left[idx] == '1' && r_right[idx] == '3')
			three_setter(idx, 'l');
		if (r_right[idx] == '1' && r_right[idx] == '3')
			three_setter(idx, 'r');
		idx++;
	}
}

void	one_two_setter(int idx, char checker)
{
	if (checker == 'u')
		g_board[3][idx] = '3';
	if (checker == 'd')
		g_board[0][idx] = '3';
	if (checker == 'l')
		g_board[idx][3] = '3';
	if (checker == 'r')
		g_board[idx][0] = '3';
}

void	view_one_two_handler(char *c_up, char *c_down, \
		char *r_left, char *r_right)
{
	int idx;

	idx = 0;
	while (idx < 4)
	{
		if (c_up[idx] == '1' && c_down[idx] == '2')
			one_two_setter(idx, 'u');
		if (c_down[idx] == '1' && c_up[idx] == '2')
			one_two_setter(idx, 'd');
		if (r_left[idx] == '1' && r_right[idx] == '2')
			one_two_setter(idx, 'l');
		if (r_right[idx] == '1' && r_left[idx] == '2')
			one_two_setter(idx, 'r');
		idx++;
	}
}


void	set_board(char *c_up, char *c_down, char *r_left, char *r_right)
{
	view_four_handler(c_up, c_down, r_left, r_right);
	view_one_handler(c_up, c_down, r_left, r_right);
	view_two_three_handler(c_up, c_down, r_left, r_right);
	view_one_three_handler(c_up, c_down, r_left, r_right);
	view_one_two_handler(c_up, c_down, r_left, r_right);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%c", g_board[i][j]);
		printf("\n");
	}
}
