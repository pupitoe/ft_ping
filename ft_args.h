/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:27:03 by tlassere          #+#    #+#             */
/*   Updated: 2025/08/05 12:02:11 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGS_H
# define FT_ARGS_H

# include "ft_ping.h"
# include <stdbool.h>

typedef struct s_opt
{
	unsigned int v: 1;
	unsigned int usage: 1;	
}	t_opt;

typedef struct s_args
{
	char	*domain;
	t_opt	opt;
	int		ret;
}	t_args;

void	ft_print_args(t_args *args);

#endif
