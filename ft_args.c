/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:19 by tlassere          #+#    #+#             */
/*   Updated: 2024/08/27 23:45:35 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include <string.h>
#include <stdio.h>

void	ft_print_args(void)
{
	fprintf(stderr, "\nUsage\n  ping [options] <destination>\n\n");
	fprintf(stderr, "Options:\n  <destination>      dns name or ip address\n");
	fprintf(stderr, "  -v                 verbose output\n");
	fprintf(stderr, "\nFor more details see tlassere\n");
}

static int	ft_set_flags(char *line, t_args *args)
{
	int	status;

	status = SUCCESS;
	line++;
	while (*line && strchr("v?", *line))
	{
		if (*line == 'v')
			args->opt_v = true;
		if (*line == '?')
			args->info = true;
		line++;
	}
	if (*line)
	{
		fprintf(stderr, "ft_ping: invalid option -- '%c'\n", *line);
		ft_print_args();
		args->ret = 2;
		status = FAIL;
	}
	return (status);
}

static int	ft_set_arg(char *line, t_args *args)
{
	int	status;

	status = SUCCESS;
	if (line[0] != '-')
		args->domain = line;
	else if (strlen(line) < 2)
	{
		fprintf(stderr, "ft_ping: -: Name or service not known\n");
		args->ret = 2;
		status = FAIL;
	}
	else
		status = ft_set_flags(line, args);
	return (status);
}

int	ft_pars_arg(int argc, char **argv, t_args *args)
{
	int	status;
	int	i;

	status = SUCCESS;
	i = 1;
	if (argc > 1)
	{
		while (i < argc && ft_set_arg(argv[i], args) == SUCCESS)
			i++;
		if (i != argc)
			status = FAIL;
	}
	return (status);
}
