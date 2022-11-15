/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:42:05 by aabel             #+#    #+#             */
/*   Updated: 2022/11/03 15:42:59 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dstbis;
	char			*srcbis;
	size_t			i;

	dstbis = (char *)dst;
	srcbis = (char *)src;
	i = 0;
	if (dstbis == srcbis)
		return (dstbis);
	while (i < n)
	{
		dstbis[i] = srcbis[i];
		i++;
	}
	return (dst);
}

/*int	main()
{
	char	dest[] = "asdhfoiasdhfoiasdhfoiasdhfip";
	char	src[] = "Good123";

	printf("%s\n", dest);
	printf("%s\n", ft_memcpy(dest, src, 8));
	return (0);
}*/