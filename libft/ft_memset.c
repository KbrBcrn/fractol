/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:09:31 by kbeceren          #+#    #+#             */
/*   Updated: 2022/07/11 15:52:30 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <string.h>
*	DESCRIPTION
*	The memset() function writes len bytes of value c (converted to an 
*	unsigned char) to the string b.
*	PARAMETERS
*	#1. The destiny pointer in which to write.
*	#2. The character to write.
*	#3. The number of bytes to write.
*	RETURN VALUES
*	The memset() function returns its first argument.  
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}
