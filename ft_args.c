/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:19 by tlassere          #+#    #+#             */
/*   Updated: 2025/08/04 16:29:23 by tlassere         ###   ########.fr       */
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
