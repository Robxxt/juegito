/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:22:26 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/06 18:36:54 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Appends string src to the end of dst. It will append at
dstsize - strlen(dst) - 1 characters. It will NUL-terminate
unless dstsize is 0 or dst > dstsize.
@param src: destinaton string
@param dst: src string
@param dstsize: destination size.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	j;
	size_t	slen;

	i = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	slen = ft_strlen(src);
	if (dstsize == i)
		return (i + slen);
	j = 0;
	k = i;
	while (j < slen)
	{
		if (i < dstsize - 1)
		{
			dst[k] = src[j];
			k++;
		}
		i++;
		j++;
	}
	dst[k] = '\0';
	return (i);
}
