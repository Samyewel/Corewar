/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:16:55 by egaliber          #+#    #+#             */
/*   Updated: 2023/03/16 15:39:41 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	check_reg_validity(t_carriage *carriage, t_vm *vm, int offset)
{
	int	reg;

	reg = vm->arena[carriage->pos + offset];
	if (reg > 16 || reg < 1)
		return (0);
	return (1);
}

int	arg_validity(t_carriage *carriage)
{
	int i;
	int type;

	i = 0;
	while (i < g_op_tab->arg_num)
	{
		type = carriage->args[i].type;
		if (!(g_op_tab[carriage->op_code - 1].arg_type[i] & type))
			return (0);
		i++;
	}
	return (1);
}

int8_t get_bit_pair(int byte, u_int8_t nth_pair)
{
	if (nth_pair == 1)
		return ((byte >> 6) & 3);
	else if (nth_pair == 2)
		return ((byte >> 4) & 3);
	else if (nth_pair == 3)
		return ((byte >> 2) & 3);
	return (0);
}

int check_result_code(t_carriage *carriage)
{
	int	i;
	int	bit_pair;

	i = 0;
	while(i < g_op_tab[carriage->op_code].arg_num)
	{
		bit_pair = get_bit_pair(carriage->pos + 1, i + 1);
		if (bit_pair == IND_CODE)
			bit_pair = T_IND;
		carriage->args[i].type = bit_pair;
		i++;
	}
	return (arg_validity(&carriage));
}

int		check_args_validity(t_carriage *carriage)
{
	if (!g_op_tab[carriage->op_code - 1].arg_type_code)
		return (1);
	else
		return (check_result_code(&carriage));
}

