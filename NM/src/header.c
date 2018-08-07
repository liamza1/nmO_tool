/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:51:35 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 11:06:25 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void						get_header32_info(void *ptr)
{
	struct mach_header		*header;

	g_env.lc = NULL;
	g_env.ncmds = 0;
	g_env.nsects = 0;
	g_env.secs_counter = 0;
	g_env.lcmd = 0;
	g_env.nsyms = 0;
	g_env.symoff = 0;
	g_env.val = 0;
	header = (struct mach_header *)ptr;
	g_env.ncmds = (g_env.is_swap) ? (rev_32(header->ncmds)) : (header->ncmds);
	g_env.lc = (void *)ptr + sizeof(*header);
}

void						get_header64_info(void *ptr)
{
	struct mach_header_64	*header;

	g_env.lc = NULL;
	g_env.ncmds = 0;
	g_env.nsects = 0;
	g_env.secs_counter = 0;
	g_env.lcmd = 0;
	g_env.nsyms = 0;
	g_env.symoff = 0;
	g_env.val = 0;
	header = (struct mach_header_64 *)ptr;
	g_env.ncmds = (g_env.is_swap) ? (rev_32(header->ncmds)) : (header->ncmds);
	g_env.lc = (void *)ptr + sizeof(*header);
}
