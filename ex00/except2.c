/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee <slee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:47:34 by slee              #+#    #+#             */
/*   Updated: 2021/04/04 14:52:09 by slee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_error();

int		non_edge_match(char *a, char *b, char *c)
{
	if (a[0] == '1' && b[0] != '1')
	{
		print_error();
		return (1);
	}
	if (a[3] == '1' && c[0] != '1')
	{
		print_error();
		return (1);
	}
	return (0);
}

int		non_edge_match2(char *a, char *b, char *c)
{
	if (a[0] == '1' && b[3] != '1')
	{
		print_error();
		return (1);
	}
	if (a[3] == '1' && c[3] != '1')
	{
		print_error();
		return (1);
	}
	return (0);
}

void	board_except2(char *colu, char *cold, char *rowl, char *rowr)
{
	if (non_edge_match(colu, rowl, rowr))
		return ;
	if (non_edge_match(rowl, colu, cold))
		return ;
	if (non_edge_match2(cold, rowl, rowr))
		return ;
	if (non_edge_match2(rowr, colu, cold))
		return ;
}
