/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:31:17 by emoman            #+#    #+#             */
/*   Updated: 2025/09/02 10:00:00 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	launch_threads(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->n_threads)
	{
		env->strips[i].y0 = i * (H / env->n_threads);
		env->strips[i].y1 = (i + 1) * (H / env->n_threads);
		env->strips[i].depth = env->depth;
		env->strips[i].d = env->d;
		pthread_create(&env->t_id[i], NULL, render_strip, &env->strips[i]);
		i++;
	}
}

static void	join_threads(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->n_threads)
	{
		pthread_join(env->t_id[i], NULL);
		i++;
	}
}

void	threaded_render(t_data *d, int depth)
{
	t_env	env;

	env.d = d;
	env.depth = depth;
	env.n_threads = sysconf(_SC_NPROCESSORS_ONLN);
	if (env.n_threads < 1)
		env.n_threads = 1;
	env.t_id = malloc(sizeof(pthread_t) * env.n_threads);
	env.strips = malloc(sizeof(t_strip) * env.n_threads);
	if (!env.t_id || !env.strips)
	{
		free(env.t_id);
		free(env.strips);
		return ;
	}
	launch_threads(&env);
	join_threads(&env);
	free(env.t_id);
	free(env.strips);
}
