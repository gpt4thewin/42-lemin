/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:41:27 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/28 20:21:09 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define MAX_NB_SIZE 10

/*
**	Function for parsing the input and create the information for the progams
*/

void	parse(t_lem_in *lem_in)
{
	char *line;

	line = NULL;
	parse_ants_count(lem_in, &line);
	parse_rooms(lem_in, &line);
	parse_links(lem_in, &line);
	ft_strdel(&line);
}

/*
**	Function of parsing which read and test the number of ants
*/

void	parse_ants_count(t_lem_in *lem_in, char **line)
{
	int i;

	i = 0;
	if ((i = gnl_no_comm(0, line)) != -1)
	{
		if (ft_strlen(*line) <= MAX_NB_SIZE && (i = ft_atoi(*line)) > 0)
			lem_in->total_ants = i;
		else
			lem_in_die();
	}
	ft_strdel(line);
}

/*
** Function which is parsing the line and create one rooms
*/

int		read_room_line(t_lem_in *lem_in, char **line, t_roomtype type)
{
	if (gnl_no_comm(0, line) == -1)
		return (0);
	parse_room_line(lem_in, *line, type);
	return (1);
}

int		parse_room_line(t_lem_in *lem_in, char *line, t_roomtype type)
{
	int		x;
	int		y;
	char	**tab;
	t_room	*new;

	if ((tab = ft_strsplit(line, ' ')) == NULL
			|| tab[1] == NULL || tab[2] == NULL
			|| ft_strlen(tab[1]) > MAX_NB_SIZE
			|| ft_strlen(tab[2]) > MAX_NB_SIZE)
	{
		ft_free_tab(&tab);
		return (0);
	}
	x = ft_atoi(tab[1]);
	y = ft_atoi(tab[2]);
	if ((new = room_new(tab[0], type, x, y)) != NULL)
	{
		lem_in_add_room(lem_in, new);
	}
	ft_free_tab(&tab);
	return (new == NULL ? 0 : 1);
}

/*
** Function which read line and create the rooms
*/

t_bool	parse_rooms(t_lem_in *lem_in, char **line)
{
	int		i;
	int		state;
	char	**tab;

	state = 1;
	tab = NULL;
	while (state != 0 && (i = gnl_no_comm(0, line)) != -1 && line != NULL)
	{
		if (ft_strlen(*line) == 0 || ft_strindex(*line, '-') != -1)
		{
			break ;
		}
		else if (ft_strnequ("##", *line, 2))
		{
			if (ft_strnequ("##start", *line, 7))
				state = read_room_line(lem_in, line, start);
			else if (ft_strnequ("##end", *line, 5))
				state = read_room_line(lem_in, line, end);
		}
		else
			state = parse_room_line(lem_in, *line, standard);
	}
	if (*line == NULL || ft_strlen(*line) == 0 || i < 0)
		lem_in_die();
	return ((state == 0) ? false : true);
}

/*
**	Function of parsing to add the links to the room
*/

void	parse_links(t_lem_in *lem_in, char **line)
{
	char	*s1;
	char	*s2;
	int		i;

	i = 1;
	s1 = NULL;
	s2 = NULL;
	(void)lem_in;
	while (1)
	{
		if ((i = ft_strindex(*line, '-')) == -1)
		{
			return ;
		}
		else
		{
			s1 = ft_strsub(*line, 0, i);
			s2 = ft_strsub(*line, i + 1, ft_strlen(*line) - i);
			free(s1);
			free(s2);
		}
		if (i == 0 || (i = gnl_no_comm(0, line)) == -1 || line == NULL)
			break ;
	}
}
