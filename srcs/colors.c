/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:13:52 by emoman            #+#    #+#             */
/*   Updated: 2025/09/03 15:16:31 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color_profile	*build_color_table(void)
{
	static t_color_profile	table[9] = {
	{"Classic Rainbow", 1.0, 0.0, 1.0, 0.2, 1.0, 0.4},
	{"Electric Blue & Gold", 1.0, 0.5, 1.2, 0.6, 1.5, 0.7},
	{"Fiery Nebula", 0.6, 0.0, 0.4, 0.1, 0.2, 0.2},
	{"Psychedelic Greens", 2.0, 0.8, 3.0, 0.1, 2.5, 0.3},
	{"Frozen Tundra", 1.5, 0.9, 1.0, 0.5, 0.5, 0.1},
	{"Vaporwave Sunset", 0.8, 0.3, 1.3, 0.7, 1.8, 0.9},
	{"Cosmic Lavender", 0.5, 0.1, 0.8, 0.5, 1.0, 0.8},
	{"Gothic Dusk", 0.3, 0.5, 0.6, 0.8, 0.9, 0.2},
	{NULL, 0, 0, 0, 0, 0, 0}
	};

	return (table);
}

int	count_color_profiles(void)
{
	t_color_profile	*p;
	int				i;

	p = build_color_table();
	i = 0;
	while (p[i].name)
		i++;
	return (i);
}

t_color_profile	*get_color_profile(int idx)
{
	t_color_profile	*p;
	int				i;
	int				count;

	p = build_color_table();
	count = count_color_profiles();
	if (idx < 0 || idx >= count)
		return (&p[0]);
	i = 0;
	while (p[i].name)
	{
		if (i == idx)
			return (&p[i]);
		++i;
	}
	return (&p[0]);
}

int	get_color(double i, int max, t_data *d)
{
	double			t;
	t_color_profile	*p;
	int				r;
	int				g;
	int				b;

	if (i >= max)
		t = 1.0;
	else
		t = i / max;
	p = d->color;
	r = 128 + 127 * cos(2 * M_PI * (p->freq_r * t + p->phase_r + d->time));
	g = 128 + 127 * cos(2 * M_PI * (p->freq_g * t + p->phase_g + d->time));
	b = 128 + 127 * cos(2 * M_PI * (p->freq_b * t + p->phase_b + d->time));
	return ((r << 16) | (g << 8) | b);
}
