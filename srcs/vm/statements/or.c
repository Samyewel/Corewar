/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:44 by sam               #+#    #+#             */
/*   Updated: 2023/03/17 14:58:39 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* -
*/
void	ft_or(t_carriage *carriage)
{
    uint8_t value_1;
    uint8_t value_2;
    uint8_t result;

    value_1 = fetch_value(carriage, carriage->args[0]);
    value_2 = fetch_value(carriage, carriage->args[1]);
    result = (value_1 | value_2);
    carriage->registers[carriage->args[2].value - 1] = result;
    if (result == 0)
        carriage->carry = 1;
    else
        carriage->carry = 0;
}
