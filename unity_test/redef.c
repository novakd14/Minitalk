/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redef.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:49:36 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/08 23:14:25 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redef.h"
#include "unity.h"

int		exit_pass = 0;

void	exit(int status)
{
	(void)status;
	if (exit_pass == 1)
		TEST_PASS();
	else
		TEST_FAIL_MESSAGE("Program wrongly exited.");
}
