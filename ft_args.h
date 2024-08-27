/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:27:03 by tlassere          #+#    #+#             */
/*   Updated: 2024/08/27 23:22:20 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGS_H
# define FT_ARGS_H

# include "ft_ping.h"
# include <stdbool.h>

typedef struct s_args
{
	char	*domain;
	bool	opt_v;
	bool	info;
	int		ret;
}	t_args;

void	ft_print_args(void);
int		ft_pars_arg(int argc, char **argv, t_args *args);

#endif
