/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt_print_help.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:51:20 by agoulas           #+#    #+#             */
/*   Updated: 2019/03/15 18:19:31 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Prints command line error.
*/

void	print_unknow(char *s)
{
	ft_fprintf(2, " ____________________________________");
	ft_fprintf(2, "____________________________________\n");
	ft_fprintf(2, "|                                    ");
	ft_fprintf(2, "                                    |\n\n");
	ft_fprintf(2, "	Error arg : '%s' is not a valid command.\n\n", s);
	printf_help();
	ft_fprintf(2, "\n");
	ft_fprintf(2, "|___________________________________");
	ft_fprintf(2, "____________________________________|\n\n");
	lem_in_die();
}

/*
**	Prints command line help.
*/

void	printf_help(void)
{
	ft_fprintf(2, "	 ______________________________________________\n");
	ft_fprintf(2, "	| HELP                                         |\n");
	ft_fprintf(2, "	|  Usage: lem_in <options>                     |\n");
	ft_fprintf(2, "	|    -help,-h: Show help.                      |\n");
	ft_fprintf(2, "	|    -r,--rooms: print rooms of the graph.     |\n");
	ft_fprintf(2, "	|    -R,--route: print the route used by ant.  |\n");
	ft_fprintf(2, "	|    -g,--groups: print the group chosen.      |\n");
	ft_fprintf(2, "	|    -n,--nblines: print total of lines.       |\n");
	ft_fprintf(2, "	|    -d,--debug: print all for debug.          |\n");
	ft_fprintf(2, "	|   extra info on stderr (2)                   |\n");
	ft_fprintf(2, "	|______________________________________________|\n");
}
