/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:12:53 by ajones            #+#    #+#             */
/*   Updated: 2023/02/06 23:31:08 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"

# define USAGE "Usage: ./asm [filename.s]\n"
# define EXT_S "Invalid file! Input file must have [.s] extension\n\n"
# define ASSEM "ERROR! Memory allocation of t_asm failed!\n"

# define LIVE 1
# define LD 2
# define ST 3
# define ADD 4
# define SUB 5
# define AND 6
# define OR 7
# define XOR 8
# define ZJMP 9
# define LDI 10
# define STI 11
# define FORK 12
# define LLD 13
# define LLDI 14
# define LFORK 15
# define AFF 16

typedef struct	s_asm
{
	char		*filename;
	char		*cor_name;
}				t_asm;

int		main(int argc, char **argv);

/*
	Initialising
*/

void	init_asm(t_asm *assem, char *file_input);

/*
	Errors
*/

void	error_exit(char *exit_str);

#endif