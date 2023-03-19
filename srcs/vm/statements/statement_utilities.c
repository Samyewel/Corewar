/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statement_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:39:23 by tlahin            #+#    #+#             */
/*   Updated: 2023/03/19 16:01:26 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Clone the carriage that used fork or lfork.
*/
t_carriage	*clone_carriage(t_carriage *old, int pos)
{
	int				i;
	t_carriage		*new;

	new = (t_carriage *)ft_memalloc(sizeof(t_carriage));
	if (!new)
		exit_vm("Memory allocation failure in initialise_carriage.");
	new->player = old->player;
	new->id = old->id;
	new->pos = pos;
	new->carry = old->carry;
	new->cycles_until_exec = 0;
	new->dead = false;
	new->next = NULL;
	new->result_code = 0;
	new->last_live_cycle = old->last_live_cycle;
	i = 0;
	while (i < REG_NUMBER)
	{
		new->registers[i] = old->registers[i];
		i++;
	}
	return (new);
}

/*
* - Calculates the correct position.
*/
int	mod_calculator(int pos)
{
	if (pos < 0)
	{
		pos %= MEM_SIZE;
		pos += MEM_SIZE;
	}
	else
		pos %= MEM_SIZE;
	return (pos);
}

/*
* - Rewrites N amount of bites to the arena.
*/
void	write_n_byte(t_vm *vm, int index, int size, int data)
{
	index = mod_calculator(index);
	while ((int)size >= 0)
	{
		vm->arena[index % MEM_SIZE] = ((unsigned char *)&data)[size];
		size--;
		index++;
	}
}

/*
* - Gets the inside a registry.
*/
int	fetch_value(t_carriage *carriage, t_args *arg)
{
	if (arg->type == T_REG)
		return (carriage->registers[arg->value - 1]);
	return (arg->value);
}
