/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putldbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 01:29:12 by masprigg          #+#    #+#             */
/*   Updated: 2019/02/14 02:37:02 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_dblclr(t_double *dbl)
{
	free(dbl->exp);
	free(dbl->lowres);
	free(dbl->mantis);
	free(dbl->res);
}

static char		*ft_get_smallpoint(char *str, int strike)
{
	char	*lowres;

	lowres = NULL;
	ft_strclr(&str[strike]);
	if (strike)
	{
		lowres = ft_strjoin(".", str);
		ft_strdel(&str);
		str = lowres;
	}
	return (str);
}

char			*ft_get_ldbl(long double dbl, int strike)
{
	t_double	debel;
	char		*mem;
	char		*dabl;

	ft_memset(&debel, 0, sizeof(t_double));
	mem = ft_get_membit(&dbl, 10);
	debel.mantis = ft_strdup(&mem[16]);
	mem[16] = '\0';
	debel.exp = ft_strdup(&mem[1]);
	debel.sign = mem[0] - 48;
	debel.strike = strike;
	ft_strdel(&mem);
	ft_set_lresult(debel.mantis, &debel);
	if (debel.sign)
		mem = ft_strjoin("-", debel.res);
	else
		mem = ft_strdup(debel.res);
	debel.lowres = ft_get_smallpoint(debel.lowres, strike);
	dabl = ft_strjoin(mem, debel.lowres);
	ft_strdel(&mem);
	ft_dblclr(&debel);
	return (dabl);
}
