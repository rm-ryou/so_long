/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:13:46 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/02 12:36:53 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] != '\0')
		len += 1;
	return (len);
}

char	*gnl_ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i += 1;
	}
	return (NULL);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	s1_len = gnl_ft_strlen(s1);
	s2_len = gnl_ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		i += 1;
	}
	j = 0;
	while (j < s2_len)
	{
		str[i + j] = s2[j];
		j += 1;
	}
	str[i + j] = '\0';
	return (str);
}

char	*gnl_ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = gnl_ft_strlen(s);
	if (start >= s_len)
		return (gnl_ft_strdup(""));
	else if ((start + len) > s_len)
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		str[i] = s[start + i];
		i += 1;
	}
	str[i] = '\0';
	return (str);
}

char	*gnl_ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (gnl_ft_strlen(s1) + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i += 1;
	}
	res[i] = '\0';
	return (res);
}
