/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:19 by tlassere          #+#    #+#             */
/*   Updated: 2025/08/09 15:52:58 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include <string.h>
#include <stdio.h>

void	ft_print_args(t_args *args)
{
	args->ret = 2;
	fprintf(stderr, "\nUsage\n  ping [options] <destination>\n\n");
	fprintf(stderr, "Options:\n  <destination>      dns name or ip address\n");
	fprintf(stderr, "  -v                 verbose output\n");
	fprintf(stderr, "\nFor more details see tlassere\n");
}

static int	find_flag(char *str, t_args *args)
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
				fprintf(stderr, "ft_ping: option requires an argument -- '%c'\n", *str);
				ft_print_args(args);
				return (FAIL);
				break;
		}
		str++;
	}
	return (SUCCESS);
}

static int set_domain(char *str, t_args *args)
{
	size_t	i = 0;
	int		dot = 0;
	int		number = 0;
	int		flag = NUMBER;
	char	*end = NULL;
	
	if (args->domain)
		return (SUCCESS);
	args->domain = strdup(str);
	if (!args->domain)
		return (FAIL);
	while (str[i] && args->domain_type != DT_DOMAIN_NAME)
	{
		if (str[i] == '.' && flag == DOT)
		{
			flag = NUMBER;
			dot++;
		}
		else if (isdigit(str[i]) && flag == NUMBER && strtol(str + i, &end, 10) < 256)
		{
			flag = DOT;
			i = end - str - 1;
			number++;
		}
		else
			args->domain_type = DT_DOMAIN_NAME;
		i++;
	}
	if (number != 4 || dot != 3)
		args->domain_type = DT_DOMAIN_NAME;
	return (SUCCESS);
}

static int	put_arg(char *str, t_args *args)
{
	if (str[0] == '-' && str[1])
		return (find_flag(str + 1, args));
	return (set_domain(str, args));
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
	if (!args->domain)
	{
		fprintf(stderr, ERR_ADDR);
		args->ret = 1;
		return (FAIL);
	}
	return (SUCCESS);
}

void	free_args(t_args *args)
{
	free(args->domain);
	free(args->ip);
}
