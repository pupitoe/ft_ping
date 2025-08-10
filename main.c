/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:44:05 by tlassere          #+#    #+#             */
/*   Updated: 2025/08/10 13:03:35 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "ft_args.h"

int set_ip(t_args *args)
{
	size_t	i = 0;
	size_t	len = strlen(args->domain) + 1;

	if (args->domain_type == DT_DOMAIN_NAME)
	{
		args->ip = strdup("127.0.0.1");
		return (SUCCESS);
	}
	while (args->domain[i])
	{
		if (args->domain[i] == '0' && args->domain[i + 1] != '.' && args->domain[i + 1] != '\0')
			memmove(args->domain + i , args->domain + i + 1, len - i);
		else
		{
			while (args->domain[i] && args->domain[i] != '.')
				i++;
			if (args->domain[i])
				i++;
		}
	}
	args->ip = strdup(args->domain);
	if (!args->ip)
		return (FAIL);
	return (SUCCESS);
}

static void	ft_exec(t_args *args)
{
	if (set_ip(args) == FAIL)
		return ;
	printf("domain: %s\n", args->domain);
	printf("type: %d\n", args->domain_type);
	printf("ip: %s\n", args->ip);
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
