/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:09:32 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/17 22:09:44 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_print_foreground2(char *str)
{
	if (!ft_strcmp(str, "F_LIGHT_RED"))
		return (ft_tally_print(F_LIGHT_RED, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_LIGHT_GREEN"))
		return (ft_tally_print(F_LIGHT_GREEN, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_LIGHT_YELLOW"))
		return (ft_tally_print(F_LIGHT_YELLOW, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_LIGHT_BLUE"))
		return (ft_tally_print(F_LIGHT_BLUE, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_LIGHT_MAGENTA"))
		return (ft_tally_print(F_LIGHT_MAGENTA, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_LIGHT_CYAN"))
		return (ft_tally_print(F_LIGHT_CYAN, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_WHITE"))
		return (ft_tally_print(F_WHITE, DEFAULT_LEN1));
	else
		return (-1);
}

static int		ft_print_foreground(char *str)
{
	if (!ft_strcmp(str, "F_DEFAULT"))
		return (ft_tally_print(F_DEFAULT, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_EOC"))
		return (ft_tally_print(F_EOC, DEFAULT_LEN2));
	else if (!ft_strcmp(str, "F_BLACK"))
		return (ft_tally_print(F_BLACK, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_RED"))
		return (ft_tally_print(F_RED, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_GREEN"))
		return (ft_tally_print(F_GREEN, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_YELLOW"))
		return (ft_tally_print(F_YELLOW, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_BLUE"))
		return (ft_tally_print(F_BLUE, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_MAGENTA"))
		return (ft_tally_print(F_MAGENTA, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_CYAN"))
		return (ft_tally_print(F_CYAN, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_LIGHT_GRAY"))
		return (ft_tally_print(F_LIGHT_GRAY, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "F_DARK_GRAY"))
		return (ft_tally_print(F_DARK_GRAY, DEFAULT_LEN1));
	else
		return (ft_print_foreground2(str));
}

static int		ft_print_background2(char *str)
{
	if (!ft_strcmp(str, "B_LIGHT_RED"))
		return (ft_tally_print(B_LIGHT_RED, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_LIGHT_GREEN"))
		return (ft_tally_print(B_LIGHT_GREEN, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_LIGHT_YELLOW"))
		return (ft_tally_print(B_LIGHT_YELLOW, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_LIGHT_BLUE"))
		return (ft_tally_print(B_LIGHT_BLUE, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_LIGHT_MAGENTA"))
		return (ft_tally_print(B_LIGHT_MAGENTA, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_LIGHT_CYAN"))
		return (ft_tally_print(B_LIGHT_CYAN, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_WHITE"))
		return (ft_tally_print(B_WHITE, DEFAULT_LEN1));
	else
		return (-1);
}

static int		ft_print_background(char *str)
{
	if (!ft_strcmp(str, "B_DEFAULT"))
		return (ft_tally_print(B_DEFAULT, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_EOC"))
		return (ft_tally_print(B_EOC, DEFAULT_LEN2));
	else if (!ft_strcmp(str, "B_BLACK"))
		return (ft_tally_print(B_BLACK, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_RED"))
		return (ft_tally_print(B_RED, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_GREEN"))
		return (ft_tally_print(B_GREEN, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_YELLOW"))
		return (ft_tally_print(B_YELLOW, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_BLUE"))
		return (ft_tally_print(B_BLUE, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_MAGENTA"))
		return (ft_tally_print(B_MAGENTA, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_CYAN"))
		return (ft_tally_print(B_CYAN, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_LIGHT_GRAY"))
		return (ft_tally_print(B_LIGHT_GRAY, DEFAULT_LEN1));
	else if (!ft_strcmp(str, "B_DARK_GRAY"))
		return (ft_tally_print(B_DARK_GRAY, DEFAULT_LEN1));
	else
		return (ft_print_background2(str));
}

int				ft_print_color(char *str)
{
	int ret;

	ret = ft_print_foreground(str);
	if (ret < 0)
		ret = ft_print_background(str);
	return (ret < 0 ? 0 : 1);
}
