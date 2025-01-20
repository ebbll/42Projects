/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:54:50 by eunlee            #+#    #+#             */
/*   Updated: 2021/04/16 17:08:08 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int		main(void)
{
	char	*s1 = "";
	char	*s2 = "abcdefghijklmnopqrstuvwxyz\n";
	char	*s3 = "0123456789";
	char	*s4 = "0123456789";

	char	dest[100];
	char	ftdest[100];

	char	*empty1 = "";
	char	*empty2 = "";

	int		temp1;
	int		temp2;

	int		fd_write;
	int		fd_read1;
	int		fd_read2;

	int		buff_size = 30;
	char	buff1[buff_size];
	char	buff2[buff_size];

	char	*dup_test1;
	char	*dup_test2;

	printf(" -------------------------\n");
	printf("|          strlen         |\n");
	printf(" -------------------------\n\n");

	printf("TEST00 : empty string\n");
	printf("----------RESULT----------\n");
	printf("str : %s\n", s1);
	printf("strlen : %lu\n", strlen(s1));
	printf("ft_strlen : %zu\n", ft_strlen(s1));
	if (strlen(s1) == ft_strlen(s1))
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");

	printf("TEST01 : very long string\n");
	printf("----------RESULT----------\n");
	printf("str : %s", s2);
	printf("strlen : %lu\n", strlen(s2));
	printf("ft_strlen : %zu\n", ft_strlen(s2));
	if (strlen(s2) == ft_strlen(s2))
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");



	printf(" -------------------------\n");
	printf("|          strcpy         |\n");
	printf(" -------------------------\n\n");

	printf("TEST00 : empty string\n");
	printf("----------RESULT----------\n");
	strcpy(dest, s1);
	ft_strcpy(ftdest, s1);
	printf("dest : %s\n", dest);
	printf("fd dest : %s\n", ftdest);
	if (strcmp(dest, ftdest) == 0)
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");

	printf("TEST01 : very long string\n");
	printf("----------RESULT----------\n");
	strcpy(dest, s2);
	ft_strcpy(ftdest, s2);
	printf("dest : %s", dest);
	printf("ft dest : %s", ftdest);
	if (strcmp(dest, ftdest) == 0)
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");



	printf(" -------------------------\n");
	printf("|          strcmp         |\n");
	printf(" -------------------------\n\n");

	printf("TEST00 : 2 empty strings\n");
	printf("----------RESULT----------\n");
	printf("s1 : %s\n", empty1);
	printf("s2 : %s\n", empty2);
	printf("strcmp : %d\n", strcmp(empty1, empty2));
	printf("ft strcmp : %d\n", ft_strcmp(empty1, empty2));
	if (strcmp(empty1, empty2) == ft_strcmp(empty1, empty2))
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");

	printf("TEST01 : 1 empty string as 1st\n");
	printf("----------RESULT----------\n");
	printf("s1 : %s\n", empty1);
	printf("s2 : %s", s2);
	printf("strcmp : %d\n", strcmp(empty1, s2));
	printf("ft strcmp : %d\n", ft_strcmp(empty1, s2));
	if (strcmp(empty1, s2) == ft_strcmp(empty1, s2))
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");

	printf("TEST02 : 1 empty string as 2nd\n");
	printf("----------RESULT----------\n");
	printf("s1 : %s", s2);
	printf("s2 : %s\n", empty2);
	printf("strcmp : %d\n", strcmp(s2, empty2));
	printf("ft strcmp : %d\n", ft_strcmp(s2, empty2));
	if (strcmp(s2, empty2) == ft_strcmp(s2, empty2))
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");

	printf("TEST03 : 2 equal strings\n");
	printf("----------RESULT----------\n");
	printf("s1 : %s\n", s3);
	printf("s2 : %s\n", s4);
	printf("strcmp : %d\n", strcmp(s3, s4));
	printf("ft strcmp : %d\n", ft_strcmp(s3, s4));
	if (strcmp(s3, s4) == ft_strcmp(s3, s4))
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");

	printf("TEST04 : 2 different strings\n");
	printf("----------RESULT----------\n");
	printf("s1 : %s", s2);
	printf("s2 : %s\n", s3);
	printf("strcmp : %d\n", strcmp(s2, s3));
	printf("ft strcmp : %d\n", ft_strcmp(s2, s3));
	if (strcmp(s2, s3) == ft_strcmp(s2, s3))
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");

	printf("TEST05 : switch them\n");
	printf("----------RESULT----------\n");
	printf("s1 : %s\n", s3);
	printf("s2 : %s", s2);
	printf("strcmp : %d\n", strcmp(s3, s2));
	printf("ft strcmp : %d\n", ft_strcmp(s3, s2));
	if (strcmp(s3, s2) == ft_strcmp(s3, s2))
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");



	printf(" -------------------------\n");
	printf("|          write          |\n");
	printf(" -------------------------\n\n");

	printf("TEST00 : stdout\n");
	printf("----------RESULT----------\n");
	temp1 = write(1, s2, 27);
	printf("errno : %d\n", errno);
	printf("err msg : %s\n", strerror(errno));
	temp2 = ft_write(1, s2, 27);
	printf("ft errno : %d\n", errno);
	printf("ft err msg : %s\n", strerror(errno));
	if (temp1 == temp2)
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");

	printf("TEST01 : open file descriptor\n");
	printf("----------RESULT----------\n");
	fd_write = open("WRITE_TEST", O_RDWR | O_CREAT | 0644);
	printf("fd : %d\n", fd_write);
	temp1 = write(fd_write, s2, 27);
	printf("write ret : %d\n", temp1);
	printf("errno : %d\n", errno);
	printf("err msg : %s\n", strerror(errno));
	temp2 = ft_write(fd_write, s2, 27);
	printf("ft write ret : %d\n", temp2);
	printf("ft errno : %d\n", errno);
	printf("ft err msg : %s\n", strerror(errno));
	close(fd_write);
	if (temp1 == temp2)
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");

	printf("TEST02 : wrong file descriptor\n");
	printf("----------RESULT----------\n");
	printf("fd : -1\n");
	temp1 = write(-1, s2, 27);
	printf("write ret : %d\n", temp1);
	printf("errno : %d\n", errno);
	printf("err msg : %s\n", strerror(errno));
	temp2 = ft_write(-1, s2, 27);
	printf("write ret : %d\n", temp2);
	printf("ft errno : %d\n", errno);
	printf("ft err msg : %s\n", strerror(errno));
	if (temp1 == temp2)
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");



	printf(" ------------------------\n");
	printf("|          read          |\n");
	printf(" ------------------------\n\n");

	printf("TEST00 : stdin\n");
	printf("----------RESULT----------\n");
	temp1 = read(0, buff1, buff_size);
	buff1[temp1] = '\0';
	printf("str : %s\n", buff1);
	temp2 = ft_read(0, buff2, buff_size);
	buff2[temp2] = '\0';
	printf("ft str : %s", buff2);
	if (temp1 == temp2)
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");

	printf("TEST01 : open file descriptor\n");
	printf("----------RESULT----------\n");
	fd_read1 = open("READ_TEST", O_RDONLY);
	fd_read2 = open("READ_TEST", O_RDONLY);
	temp1 = read(fd_read1, buff1, buff_size);
	buff1[temp1] = '\0';
	printf("ret_read : %d\n", temp1);
	printf("fd : %d\n", fd_read1);
	printf("str : %s", buff1);
	temp2 = ft_read(fd_read2, buff2, buff_size);
	buff2[temp2] = '\0';
	printf("ft fd : %d\n", fd_read2);
	printf("ft str : %s", buff2);
	close(fd_read1);
	close(fd_read2);
	if (strcmp(buff1, buff2) == 0)
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");

	printf("TEST02 : wrong file descriptor\n");
	printf("----------RESULT----------\n");
	temp1 = read(-1, buff1, buff_size);
	printf("ret : %d\n", temp1);
	printf("errno : %d\n", errno);
	printf("err msg : %s\n", strerror(errno));
	temp2 = ft_read(-1, buff2, buff_size);
	printf("ft ret : %d\n", temp2);
	printf("ft errno : %d\n", errno);
	printf("fd err msg : %s\n", strerror(errno));
	if (temp1 == temp2)
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");



	printf(" ------------------------\n");
	printf("|         strdup         |\n");
	printf(" ------------------------\n\n");

	printf("TEST00 : empty string\n");
	printf("----------RESULT----------\n");
	dup_test1 = strdup(s1);
	printf("str : %s\n", dup_test1);
	printf("len : %lu\n", strlen(dup_test1));
	dup_test2 = strdup(s1);
	printf("str : %s\n", dup_test2);
	printf("len : %lu\n", strlen(dup_test2));
	if (strcmp(dup_test1, dup_test2) == 0)
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");
	free(dup_test1);
	free(dup_test2);
	dup_test1 = NULL;
	dup_test2 = NULL;

	printf("TEST01 : very long string\n");
	printf("----------RESULT----------\n");
	dup_test1 = strdup(s2);
	printf("str : %s", dup_test1);
	printf("len : %lu\n", strlen(dup_test1));
	dup_test2 = strdup(s2);
	printf("str : %s", dup_test2);
	printf("len : %lu\n", strlen(dup_test2));
	if (strcmp(dup_test1, dup_test2) == 0)
		printf("<SUCCEED>\n\n\n");
	else
		printf("<FAILED>\n\n\n");
	free(dup_test1);
	free(dup_test2);
	dup_test1 = NULL;
	dup_test2 = NULL;



	return (0);
}
