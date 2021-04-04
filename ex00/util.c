/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:09:32 by jinyoo            #+#    #+#             */
/*   Updated: 2021/04/04 10:46:57 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_one_to_four(char c)
{
	if (c >= '1' && c <= '4')
		return (1);
	return (0);
}

int		is_blank_null(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int		is_otf_blank(char c)
{
	if ((c >= '1' && c <= '4') || c == ' ')
		return (1);
	return (0);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}

int		is_exception(char *views)
{
	int i;

	i = 0;
	while (views[i])
	{
		if (!is_otf_blank(views[i]))
			return (1);
		if (is_blank_null(views[i]) && is_blank_null(views[i + 1]))
			return (1);
		i++;
	}
	if (i != 31)
		return (1);
	return (0);
}
