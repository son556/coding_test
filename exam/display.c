/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:40:51 by chanson           #+#    #+#             */
/*   Updated: 2023/03/27 12:20:59 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

void	display_str(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		printf("NULL\n");
		return ;
	}
	while (1)
	{
		printf("%d: %s\n", i, str[i]);
		if (str[i] == NULL)
			break ;
		i++;
	}
}
