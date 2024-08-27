/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:44:05 by tlassere          #+#    #+#             */
/*   Updated: 2024/08/27 23:45:18 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "ft_args.h"
#include <string.h>
#include <stdio.h>

static void	ft_execut(t_args *args)
{
	if (args->info)
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

int	main(int argc, char **argv)
{
	t_args	args;

	memset(&args, 0, sizeof(args));
	if (ft_pars_arg(argc, argv, &args) == SUCCESS)
		ft_execut(&args);
	return (args.ret);
}
