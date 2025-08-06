/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:44:05 by tlassere          #+#    #+#             */
/*   Updated: 2025/08/06 14:38:15 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include "ft_args.h"

static void	ft_execut(t_args *args)
{
	if (args->domain)
	{
		printf("domain: %s\n", args->domain);
		printf("type: %d\n", args->domain_type);
	}
	else
	{
		fprintf(stderr, ERR_ADDR);
		args->ret = 1;
	}
}

int	find_flag(char *str, t_args *args)
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

#define DOT 1
#define NUMBER 0

int set_domain(char *str, t_args *args)
{
	size_t	i = 0;
	int		dot = 0;
	int		number = 0;
	int		flag = NUMBER;
	char	*end = NULL;
	
	if (args->domain)
		return (SUCCESS);
	args->domain = str;
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

int	put_arg(char *str, t_args *args)
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
		fprintf(stderr, "ft_ping: usage error: Destination address required\n");
		args->ret = 1;
		return (FAIL);
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
