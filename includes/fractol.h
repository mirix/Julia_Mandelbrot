/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:23:46 by emoman            #+#    #+#             */
/*   Updated: 2025/09/04 14:54:43 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>

# define M_PI 3.14159265358979323846
# define W 1280
# define H 960
# define MAX_ZOOM 10000000000000.0
# define MAX_DEPTH 1000
# define ZOOM_FACTOR 1.1

typedef enum e_type
{
	JULIA,
	MANDELBROT
}	t_type;

typedef enum e_fractal_eq
{
	Z_SQUARED,
	BURNING_SHIP,
	TRICORN
}	t_fractal_eq;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_color_profile
{
	char	*name;
	double	freq_r;
	double	phase_r;
	double	freq_g;
	double	phase_g;
	double	freq_b;
	double	phase_b;
}	t_color_profile;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	double				*iter;
	int					line_length;
	int					bits_per_pixel;
	int					endian;
	double				zoom;
	double				offset_x;
	double				offset_y;
	int					depth;
	t_complex			julia_c;
	char				*preset_name;
	t_color_profile		*color;
	int					color_idx;
	int					num_colors;
	int					shift_colors;
	int					needs_recompute;
	double				time;
	t_type				type;
	t_fractal_eq		equation;
	struct s_data		*julia_d;
	struct s_data		*parent_d;
}	t_data;

typedef struct s_strip
{
	int		y0;
	int		y1;
	int		depth;
	t_data	*d;
}	t_strip;

typedef struct s_preset
{
	char		key;
	t_complex	c;
	char		*name;
}	t_preset;

typedef struct s_env
{
	pthread_t	*t_id;
	t_strip		*strips;
	t_data		*d;
	int			depth;
	long		n_threads;
}	t_env;

// main.c
// julia_inter.c
int				launch_julia_window(t_data *m_data, t_complex c);
int				julia_close_hook(t_data *j_data);
void			append_julia_info(char *dst, int *i, t_data *d);
// hooks.c
int				close_hook(t_data *d);
int				mouse_hook(int button, int x, int y, t_data *d);
int				mouse_motion_hook(int x, int y, t_data *d);
int				timer_hook(t_data *d);
// key_hooks
int				key_hook(int keycode, t_data *d);
void			handle_key_press(int keycode, t_data *d);
// draw.c
void			draw_fractal(t_data *d);
void			redraw_image(t_data *d);
t_complex		map(int px, int py, t_data *d);
void			*render_strip(void *arg);
t_complex		apply_equation(t_complex z, t_complex c, t_data *d);
// iter.c
double			smooth_iteration(t_complex z, int i);
double			iter_julia(t_complex z0, t_complex c, int depth, t_data *d);
double			iter_mandelbrot(t_complex c, int depth, t_data *d);
// threads.c
void			threaded_render(t_data *d, int depth);
// colors.c
t_color_profile	*get_color_profile(int idx);
t_color_profile	*build_color_table(void);
int				count_color_profiles(void);
int				get_color(double i, int max, t_data *d);
// args.c
void			print_usage(void);
int				parse_args(int argc, char **argv, t_data *d);
int				set_preset(char key, t_data *d);
// utils.c
void			my_mlx_pixel_put(t_data *d, int x, int y, int color);
double			ft_atof(const char *str);
int				is_valid_double(const char *str);
void			build_title(char *dst, t_data *d);

#endif
