/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:57:40 by sam               #+#    #+#             */
/*   Updated: 2023/03/19 15:23:29 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Updates the carriage to contain the code at the given arena position.
* - Converts the op_code at the position into an integer. If this integer
*   correlates to one of the registry statements, the carriage grabs the cycles
*   until its execution from the op_table and stores it.
*/
void	apply_statement(t_vm *vm, t_carriage *carriage)
{
	int	byte_as_int;

	byte_as_int = vm->arena[carriage->pos];
	if (DEBUG == true)
		ft_printf(" | %.2x : %3d", carriage->op_code, byte_as_int);
	if (byte_as_int >= 1 && byte_as_int <= 16)
	{
		carriage->op_code = byte_as_int;
		carriage->cycles_until_exec = g_op_tab[byte_as_int - 1].cycles;
		if (DEBUG == true)
			ft_printf(" | Cycles until execution: %2d", \
			carriage->cycles_until_exec);
	}
	else
		carriage->pos = (carriage->pos + 1) % MEM_SIZE;
}

/*
* - Executes the statement correlating to the op code at the arena position.
* - We first make sure that statement is between 1 and 16. If it is, its saved.
* - Otherwise we skip a byte. Then we save the binary code (result code).
* - We then start validating and checking arg values for that statement.
* - After that we count how many bytes we need to move to the next statement.
* - Finally we move the carriage to the next statement.
*/
void	execute_statement(t_vm *vm, t_carriage *carriage, t_corewar *cw)
{
	int	position;

	if (DEBUG == true)
		ft_printf(" | Executing...");
	position = vm->arena[carriage->pos];
	if (position >= 1 && position <= 16)
	{
		carriage->op_code = position;
		carriage->result_code = (vm->arena[(carriage->pos + 1) % MEM_SIZE]);
		if (check_args_validity(carriage))
		{
			if (reg_check(carriage, vm))
				get_arg_values(carriage, vm, cw);
		}
		count_bytes_to_skip(carriage);
		move_to_next_statement(carriage);
	}
}
