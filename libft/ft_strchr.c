/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:49:54 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/11 15:29:52 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char    *ft_strchr(const char *s, int c)
{
    if (!s) // Handle NULL input
        return (NULL);

    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    return ((char)c == '\0' ? (char *)s : NULL); // Ensure NULL safety
}