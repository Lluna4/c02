/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntranc </var/spool/mail/luna>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:21:28 by luntranc          #+#    #+#             */
/*   Updated: 2023/12/05 21:31:55 by luna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcapitalize(char *str)
{
	int index;
	int capitalize;

	index = 0;
	capitalize = 1;
	while (str[index] != '\0')
	{
		if (capitalize == 1 && (str[index] >= 'a' && str[index] <= 'z'))
		{
			str[index] -= ('a' - 'A');
			capitalize = 0;
		}
		else if (capitalize == 0 && (str[index] >= 'A' && str[index] <= 'Z'))
		{
			str[index] += ('a' - 'A');
		}
		else if (str[index] == ' ')
			capitalize = 1;
		index++;
	}
	return (str);
}
