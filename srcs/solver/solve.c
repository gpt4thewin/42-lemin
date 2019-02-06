/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:33:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/06 14:59:32 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Core problem solving function.
*/

void	solve(t_lem_in *lem_in, t_solution *solution)
{
	t_glist		*routes;
	t_glist		*groups;
	t_group		*best_group;

	groups = NULL;
	routes = create_routes(lem_in);
	create_groups(&groups, routes);
	best_group = select_best_group(groups);
	sort_routes(best_group);
	build_solution(solution, best_group, lem_in->total_ants);
	ft_glstdel(&routes, route_free);
	ft_glstdel(&groups, group_free);
}
