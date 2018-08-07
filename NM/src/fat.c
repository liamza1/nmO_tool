/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:51:26 by lstreak           #+#    #+#             */
/*   Updated: 2018/07/10 10:51:27 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void					parse_fat(void *ptr)
{
	struct fat_header	*fat;
	struct fat_arch		*arch;
	uint32_t			x;
	uint32_t			offset;

	fat = (void *)ptr;
	fat = (void*)ptr;
	x = fat->nfat_arch;
	x = rev_32(x);
	arch = (void*)ptr + sizeof(fat);
	while (x)
	{
		if (rev_32(arch->cputype) == CPU_TYPE_X86_64)
			offset = arch->offset;
		if (rev_32(arch->cputype) == CPU_TYPE_POWERPC)
		{
			g_env.is_ppc = 1;
			offset = arch->offset;
		}
		arch += sizeof(arch) / sizeof(void*);
		x--;
	}
	ft_nm(ptr + rev_32(offset));
}
