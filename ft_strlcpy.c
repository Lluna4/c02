/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luna </var/spool/mail/luna>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:36:11 by luna              #+#    #+#             */
/*   Updated: 2023/12/05 21:59:29 by luna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int index;

	index = 0;
	if (size < 1)
		return (0);
	while (src[index] != '0' && index < (size - 1))
	{
		dest[index] = src[index];
		index++;
	}
	dest[size - 1] = '\0';
	return (index);
}
