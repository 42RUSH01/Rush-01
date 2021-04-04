/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee <slee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:32:05 by slee              #+#    #+#             */
/*   Updated: 2021/04/04 14:50:52 by slee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_error(void);

int		near_one_error(char *a)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < 3)
	{
		while (j < 4)
		{
			if (a[i] == '1' && a[i] == a[j])
			{
				print_error();
				return (1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int		near_four_error(char *a)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < 3)
	{
		while (j < 4)
		{
			if (a[i] == '4' && a[i] == a[j])
			{
				print_error();
				return (1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int		non_match(char *a, char *b)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (a[i] == '4' && b[i] != '1')
		{
			print_error();
			return (1);
		}
		if (a[i] == '3' && b[i] == '3')
		{
			print_error();
			return (1);
		}
		if ((a[i] == '1' && b[i] == '1') || (a[i] == '4' && b[i] == '4'))
		{
			print_error();
			return (1);
		}
		i++;
	}
	return (0);
}

void	board_except(char *colu, char *cold, char *rowl, char *rowr)
{
	if (near_one_error(colu) || near_one_error(cold))
		return ;
	if (near_one_error(rowl) || near_one_error(rowr))
		return ;
	if (near_four_error(colu) || near_four_error(cold))
		return ;
	if (near_four_error(rowl) || near_four_error(rowr))
		return ;
	if (non_match(colu, cold) || non_match(cold, colu))
		return ;
	if (non_match(rowl, rowr) || non_match(rowr, rowl))
		return ;
}
