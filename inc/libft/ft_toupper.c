/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:58:26 by akalombo          #+#    #+#             */
/*   Updated: 2019/06/17 09:57:45 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return ((c - 7) - 25);
	else
		return ((c));
}
