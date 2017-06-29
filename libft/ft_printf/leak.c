/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int			g_alloc_count = 0;
int			g_malloc_inject = -1;
static int	g_have_registered = 0;

static void	print_alloc_count(void)
{
	if (g_alloc_count != 0)
		fprintf(stderr, "FAIL: %d mallocs not freed\n", g_alloc_count);
	else
		fprintf(stderr, "[OK]: all allocations freed\n");
}

void		*malloc(size_t sz)
{
	void	*(*libc_malloc)(size_t);
	void	*addr_alloc;

	if (!g_have_registered)
	{
		atexit(print_alloc_count);
		g_have_registered = 1;
	}
	if (g_malloc_inject >= 0)
		if (g_malloc_inject-- == 0)
		{
			fprintf(stderr, "malloc(%ld) = INJECT\n", sz);
			return (0);
		}
	libc_malloc = dlsym(RTLD_NEXT, "malloc");
	addr_alloc = libc_malloc(sz);
	if (addr_alloc)
		g_alloc_count++;
	fprintf(stderr, "malloc(%ld) = %p\n", sz, addr_alloc);
	return (addr_alloc);
}

void		free(void *p)
{
	void	(*libc_free)(void*);

	libc_free = dlsym(RTLD_NEXT, "free");
	fprintf(stderr, "free(%p)\n", p);
	libc_free(p);
	if (p)
		g_alloc_count--;
}
