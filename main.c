/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:44:05 by tlassere          #+#    #+#             */
/*   Updated: 2025/08/05 12:14:22 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "ft_args.h"

static void	ft_execut(t_args *args)
{
	if (args->domain)
	{
		printf("%s\n", args->domain);
	}
	else
	{
		fprintf(stderr, ERR_ADDR);
		args->ret = 1;
	}
}

int	single_car(char *str, t_args *args)
{
	while (*str)
	{
		switch (*str)
		{
			case ('v'):
				args->opt.v = true;
				break;
			case ('?'):
				ft_print_args(args);
				return (FAIL);
				break;
			default:
				fprintf(stderr, "ping: option requires an argument -- '%c'\n", *str);
				ft_print_args(args);
				return (FAIL);
				break;
		}
		str++;
	}
	return (SUCCESS);
}

int	put_arg(char *str, t_args *args)
{
	if (str[0] == '-' && str[1])
	{
		if (str[1] == '-' && str[2])
			return (SUCCESS); // return parameter multie caracters
		return (single_car(str + 1, args));
	}
	return (SUCCESS); // return destination address
}

int	ft_init_args(char **argv, t_args *args)
{
	
	memset(args, 0, sizeof(*args));
	while (*argv)
	{
		if (put_arg(*argv, args) != SUCCESS)
			return (FAIL);
		argv++;
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (ft_init_args(++argv, &args) == SUCCESS)
		ft_execut(&args);
	(void)argc;
	return (args.ret);
}
