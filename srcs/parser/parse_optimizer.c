/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_optimizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:41:27 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/08 17:32:12 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**delete room which can t connect to the endroom.
*/

void	delete_dead_end(t_lem_in *lem_in, t_room *dead_end)
{
	t_glist	*rooms;
	t_room	*curr;

	rooms = lem_in->rooms;
	while (rooms != NULL && dead_end)
	{
		curr = rooms->room;
		room_remove_link(curr, dead_end);
		rooms = rooms->next;
	}
}

/*
**	Remove all room that are a dead_end : whith no links to advance.
*/

void	parse_optimizer(t_lem_in *lem_in)
{
	t_glist		*tmp;
	t_glist		*curr;
	t_room		*room;

	room = NULL;
	curr = lem_in->rooms;
	while (curr)
	{
		room = curr->room;
		if (room->links_count <= 1 && room->type == standard)
		{
			delete_dead_end(lem_in, room);
			tmp = curr->next;
			lem_in_remove_room(lem_in, room);
			curr = tmp;
		}
		else
			curr = curr->next;
	}
}