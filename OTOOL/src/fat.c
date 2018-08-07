/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 11:10:02 by lstreak           #+#    #+#             */
/*   Updated: 2018/08/03 11:10:25 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void					parse_fat(void *ptr)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	int					header_size;
	int					arch_size;
	uint32_t			i;

	header = (struct fat_header *)ptr;
	header_size = sizeof(struct fat_header);
	arch_size = sizeof(struct fat_arch);
	arch = (void *)ptr + sizeof(*header);
	i = -1;
	while (++i < rev_32(header->nfat_arch))
	{
		if (rev_32(arch->cputype) == CPU_TYPE_X86)
		{
			ft_printf("For architecture X86:\n");
			ft_otool(ptr + rev_32(arch->offset));
		}
		if (rev_32(arch->cputype) == CPU_TYPE_X86_64)
		{
			ft_printf("For architecture X86_64:\n");
			ft_otool(ptr + rev_32(arch->offset));
		}
		arch = (struct fat_arch *)(((void *)arch) + sizeof(struct fat_arch));
	}
}
