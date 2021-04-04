/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee <slee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:27:50 by slee              #+#    #+#             */
/*   Updated: 2021/04/04 14:55:21 by slee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_error(void);

int		col_row_four_match(char *a, char *b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (i == j)
			{
				j++;
				continue ;
			}
			if (a[i] == '4' && a[i] == b[j])
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		col_row_four_match2(char *a, char *b)
{
	int i;
	int j;

	i = 0;
	j = 3;
	while (i < 4)
	{
		while (j >= 0)
		{
			if ((i + j) == 3)
			{
				j--;
				continue ;
			}
			if (a[i] == '4' && a[i] == b[j])
				return (1);
			j--;
		}
		j = 3;
		i++;
	}
	return (0);
}

void	board_except3(char *colu, char *cold, char *rowl, char *rowr)
{
	if (col_row_four_match(colu, rowl))
		return ;
	if (col_row_four_match2(colu, rowr))
		return ;
	if (col_row_four_match(cold, rowr))
		return ;
	if (col_row_four_match2(cold, rowl))
		return ;
	if (col_row_four_match(rowl, colu))
		return ;
	if (col_row_four_match2(rowl, cold))
		return ;
	if (col_row_four_match(rowr, cold))
		return ;
	if (col_row_four_match2(rowr, colu))
		return ;
}
