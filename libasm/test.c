/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:27:46 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/04/12 22:14:16 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libasm.h"

int		main(void)
{
	char s1[10];
	char *s2;

	printf("---ft_strlen---\n");
	printf(" abcde01234	| %ld\n", ft_strlen("abcde01234"));
	printf(" hyungyyo	| %ld\n", ft_strlen("hyungyyo"));
	printf(" h			| %ld\n", ft_strlen("h"));
	printf(" hyun		| %ld\n", ft_strlen("hyun"));
	printf(" hyung		| %ld\n", ft_strlen("hyung"));
	printf("---ft_strcpy---\n");
	s2 = "abcd01234";
	printf(" abcd01234	| %s\n", ft_strcpy(s1, s2));
	s2 = "test...";
	ft_strcpy(s1, s2);
	printf(" test...	| %s\n", s1);
	printf("---ft_strcmp---\n");
	printf(" abc abc	| %d\n", ft_strcmp("abc", "abc"));
	printf(" abc ab1	| %d\n", ft_strcmp("abc", "ab1"));
	printf(" ab1 abc	| %d\n", ft_strcmp("ab1", "abc"));
	printf(" abc abc	| %d\n", strcmp("abc", "abc"));
	printf(" abc ab1	| %d\n", strcmp("abc", "ab1"));
	printf(" ab1 abc	| %d\n", strcmp("ab1", "abc"));
	int r;
	printf("---ft_write---\n");
	r = ft_write(1, "hello!\n", ft_strlen("hello!\n"));
	printf(" ret: %d, errno: %d\n", r, errno);
	r = ft_write(1, "brrrrrrrrr\n", ft_strlen("brrrrrrrrr\n"));
	printf(" ret: %d, errno: %d\n", r, errno);
	r = ft_write(-1, "?!\n", ft_strlen("?!\n"));
	printf(" ret: %d, errno: %d\n", r, errno);
	r = write(-1, "?!\n", ft_strlen("?!\n"));
	printf(" ret: %d, errno: %d\n", r, errno);
	errno = 0;
	printf("---ft_read---\n");
	r = ft_read(0, s1, 10);
	printf(" input[10]: %s\n", s1);
	printf(" ret: %d, errno: %d\n", r, errno);
	char	s3[10];
	r = ft_read(-1, s3, 10);
	printf(" input[10]: %s\n", s3);
	printf(" ret: %d, errno: %d\n", r, errno);
	r = read(-1, s3, 10);
	printf(" input[10]: %s\n", s3);
	printf(" ret: %d, errno: %d\n", r, errno);
	printf("---ft_strdup---\n");
	s2 = ft_strdup("strdup test");
	printf(" %s\n", s2);
	free(s2);
	return (0);
}
