/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:28:34 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/11 17:28:49 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_stack *stack)
{
    int count;

    count = 0;
    if (!stack)
        return (0);
    
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}
