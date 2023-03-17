/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:12:14 by sam               #+#    #+#             */
/*   Updated: 2023/03/17 14:27:14 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Reads the given amount of bytes.
*/
int	get_n_byte(uint32_t n, unsigned char *data, uint32_t idx)
{
	uint32_t	i;
	int			value;

	value = 0;
	i = 0;
	if (data)
	{
		while (i < n)
			value = (value * 0x100) + data[idx + i++];
	}
	return (value);
}

/*
* - Reads the given arguments, counting how many .cor files are provided.
*/
void	get_player_count(int ac, char **av, uint32_t *player_count)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strstr(av[i], ".cor") != NULL)
			*player_count += 1;
		i++;
	}
}
