/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:27 by sam               #+#    #+#             */
/*   Updated: 2023/03/17 14:13:34 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** handle_fork:
** - Makes a copy of the given carriage, putting it onto the arena in the given
**   placement.
*/
void	ft_fork(t_carriage *carriage, t_vm *vm)
{
	int			pos;
	t_carriage	*new;

	pos = carriage->pos + carriage->args[0].value % IDX_MOD;
	pos = mod_calculator(pos);
	new_carriage(&(vm->carriages), clone_carriage(carriage, pos));
}
