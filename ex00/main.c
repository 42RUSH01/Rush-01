/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 20:18:54 by jinyoo            #+#    #+#             */
/*   Updated: 2021/04/03 03:13:26 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_error(void);
void	rush(char *views);
int		is_exception(char *views);

int		main(int argc, char **argv)
{
	if (argc != 2 || is_exception(argv[1]))
	{
		print_error();
		return (0);
	}
	rush(argv[1]);
	return (0);
}
