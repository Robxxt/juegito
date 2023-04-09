/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:19:02 by rdragan           #+#    #+#             */
/*   Updated: 2022/11/04 09:25:38 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Returns 1 if the character is digit otherwise 0
@param c: character
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
