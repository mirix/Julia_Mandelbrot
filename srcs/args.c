/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:00:00 by emoman            #+#    #+#             */
/*   Updated: 2025/09/04 15:16:25 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	ft_printf("\nUsage: ./fractol <type> [options]\n");
	ft_printf("\n<type>:\n");
	ft_printf("  m              - Mandelbrot set (z^2 + c)\n");
	ft_printf("  m ship         - Burning Ship fractal\n");
	ft_printf("  m tricorn      - Tricorn fractal (Mandelbar)\n");
	ft_printf("  j [preset|c]   - Julia set (z^2 + c)\n");
	ft_printf("  j ship         - Julia set with Ship equation\n");
	ft_printf("  j tricorn      - Julia set with Tricorn equation\n");
	ft_printf("\nJulia Presets (use 'j' followed by a key):\n");
	ft_printf("  d - Dragon (c = -0.4 + 0.6i) (default)\n");
	ft_printf("  s - Dense Spirals (c = -0.7 + 0.27i)\n");
	ft_printf("  e - Elephant Valley (c = -0.835 - 0.232i)\n");
	ft_printf("  t - Thin Dendrite (c = 0.285 + 0.01i)\n");
	ft_printf("  l - Lightning Bolt (c = -0.1 + 0.651i)\n");
	ft_printf("  h - Seahorse (c = 0.0 + 0.8i)\n");
	ft_printf("\nJulia Custom (use 'j c' followed by values):\n");
	ft_printf("  c <real> <imag>   (e.g., j c -0.4 0.6)\n");
	ft_printf("     real: [-2.0 ... 2.0]\n");
	ft_printf("     imag: [-2.0 ... 2.0]\n");
	ft_printf("\nExamples:\n");
	ft_printf("  ./fractol m\n");
	ft_printf("  ./fractol m ship\n");
	ft_printf("  ./fractol j d\n");
	ft_printf("  ./fractol j c 0.42 0.42\n\n");
}

int	set_preset(char key, t_data *d)
{
	t_preset	presets[7];
	int			i;

	presets[0] = (t_preset){'d', {-0.4, 0.6}, "Dragon"};
	presets[1] = (t_preset){'s', {-0.7, 0.27}, "Dense Spirals"};
	presets[2] = (t_preset){'e', {-0.835, -0.232}, "Elephant Valley"};
	presets[3] = (t_preset){'t', {0.285, 0.01}, "Thin Dendrite"};
	presets[4] = (t_preset){'l', {-0.1, 0.651}, "Lightning Bolt"};
	presets[5] = (t_preset){'h', {0.0, 0.8}, "Seahorse"};
	presets[6] = (t_preset){0, {0, 0}, NULL};
	i = 0;
	while (presets[i].key)
	{
		if (presets[i].key == key)
		{
			d->julia_c = presets[i].c;
			d->preset_name = presets[i].name;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	parse_equation(int argc, char **argv, int *idx, t_data *d)
{
	if (*idx >= argc)
		return (0);
	if (ft_strncmp(argv[*idx], "ship", 5) == 0)
	{
		d->equation = BURNING_SHIP;
		*idx += 1;
	}
	else if (ft_strncmp(argv[*idx], "tricorn", 8) == 0)
	{
		d->equation = TRICORN;
		*idx += 1;
	}
	else
		return (0);
	return (1);
}

static int	parse_julia_args(int argc, char **argv, int *i, t_data *d)
{
	if (*i < argc && argv[*i][0] == 'c' && argv[*i][1] == '\0')
	{
		if (*i + 3 > argc || !is_valid_double(argv[*i + 1])
			|| !is_valid_double(argv[*i + 2]))
			return (0);
		d->julia_c.x = ft_atof(argv[*i + 1]);
		d->julia_c.y = ft_atof(argv[*i + 2]);
		d->preset_name = "Custom";
		*i += 3;
	}
	else if (*i < argc && argv[*i][0] && argv[*i][1] == '\0')
	{
		if (!set_preset(argv[*i][0], d))
			return (0);
		*i += 1;
	}
	else
		set_preset('d', d);
	if (*i < argc)
		return (parse_equation(argc, argv, i, d));
	return (1);
}

int	parse_args(int argc, char **argv, t_data *d)
{
	int	i;

	if (argc < 2)
		return (0);
	d->equation = Z_SQUARED;
	d->type = MANDELBROT;
	d->preset_name = "Default";
	i = 1;
	if (argv[i][0] == 'm' && argv[i][1] == '\0')
	{
		d->type = MANDELBROT;
		i++;
		if (i < argc)
			return (parse_equation(argc, argv, &i, d) && i == argc);
	}
	else if (argv[i][0] == 'j' && argv[i][1] == '\0')
	{
		d->type = JULIA;
		i++;
		if (!parse_julia_args(argc, argv, &i, d))
			return (0);
	}
	else
		return (0);
	return (i == argc);
}
