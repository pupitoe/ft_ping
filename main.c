/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:44:05 by tlassere          #+#    #+#             */
/*   Updated: 2025/08/04 16:45:04 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "ft_args.h"

static void	ft_execut(t_args *args)
{
	if (args->opt.usage)
	{
		ft_print_args();
		args->ret = 2;
	}
	else if (args->domain)
	{
		printf("%s\n", args->domain);
	}
	else
	{
		fprintf(stderr, ERR_ADDR);
		args->ret = 1;
	}
}

int	ft_init_args(char **argv, t_args *args)
{
	
	memset(args, 0, sizeof(*args));
	while (*argv)
	{
		
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
