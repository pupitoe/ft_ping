/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:44:05 by tlassere          #+#    #+#             */
/*   Updated: 2025/08/09 15:58:32 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "ft_args.h"

static void	ft_exec(t_args *args)
{
	printf("domain: %s\n", args->domain);
	printf("type: %d\n", args->domain_type);
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (ft_init_args(++argv, &args) == SUCCESS)
		ft_exec(&args);
	free_args(&args);
	(void)argc;
	return (args.ret);
}
