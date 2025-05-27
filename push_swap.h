/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:26:17 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/27 20:13:27 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"   // Funciones auxiliares de la Libft
# include <limits.h>        // Para INT_MAX, INT_MIN
# include <stdlib.h>        // Para malloc, free
# include <unistd.h>        // Para write

/* Nodo individual del stack, contiene un valor y puntero al siguiente */
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

/* Estructura que contiene ambos stacks: 'a' y 'b' */
typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
}	t_stack;

/* ----------------------- Parsing y utilidades ------------------------ */
int		is_valid_number(char *str);                // Verifica si el string es un número válido
int		is_duplicate(t_node *stack, int value);    // Verifica si el valor ya está en el stack
void	append_node(t_node **stack, int value);    // Añade un nodo al final del stack
void	exit_error(t_node **a, t_node **b);         // Limpia memoria y muestra error
void	free_stack(t_node **stack);                // Libera toda la memoria del stack

/* ---------------------- Operaciones básicas -------------------------- */
// Swap
void	swap_a(t_stack *st);    // Intercambia los dos primeros nodos de 'a' (sin imprimir)
void	swap_b(t_stack *st);    // Intercambia los dos primeros nodos de 'b' (sin imprimir)

void	op_sa(t_stack *st);     // swap a + imprime "sa"
void	op_sb(t_stack *st);     // swap b + imprime "sb"
void	op_ss(t_stack *st);     // swap a y b + imprime "ss"

// Push
void	push_a(t_stack *st);    // Mueve el primer nodo de 'b' a 'a' (sin imprimir)
void	push_b(t_stack *st);    // Mueve el primer nodo de 'a' a 'b' (sin imprimir)

void	op_pa(t_stack *st);     // push a + imprime "pa"
void	op_pb(t_stack *st);     // push b + imprime "pb"

// Rotate
void	rotate_a(t_stack *st);  // Rota todos los elementos de 'a' hacia arriba (sin imprimir)
void	rotate_b(t_stack *st);  // Rota todos los elementos de 'b' hacia arriba (sin imprimir)

void	op_ra(t_stack *st);     // rotate a + imprime "ra"
void	op_rb(t_stack *st);     // rotate b + imprime "rb"
void	op_rr(t_stack *st);     // rotate a y b + imprime "rr"

// Reverse rotate
void	reverse_rotate_a(t_stack *st); // Rota 'a' hacia abajo (sin imprimir)
void	reverse_rotate_b(t_stack *st); // Rota 'b' hacia abajo (sin imprimir)

void	op_rra(t_stack *st);    // reverse rotate a + imprime "rra"
void	op_rrb(t_stack *st);    // reverse rotate b + imprime "rrb"
void	op_rrr(t_stack *st);    // reverse rotate a y b + imprime "rrr"

/* ---------------------- Algoritmos de ordenación --------------------- */
void	sort_small(t_stack *st);         // Ordena stacks de tamaño ≤ 5
void	sort_large(t_stack *st);         // Algoritmo para stacks grandes (ej: radix sort)

/* ---------------------- Funciones auxiliares ------------------------- */
int		stack_size(t_node *stack);       // Devuelve el tamaño del stack
int		is_sorted(t_node *stack);        // Verifica si el stack está ordenado
int		get_min(t_node *stack);          // Devuelve el valor mínimo del stack
int		get_max(t_node *stack);          // Devuelve el valor máximo del stack
int		get_position(t_node *stack, int value); // Devuelve la posición de un valor
void	normalize_indexes(t_node *stack); // Normaliza los valores como índices (0 a n)

#endif
