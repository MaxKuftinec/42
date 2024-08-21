# Sorting a stack of random integers
This is an attempt on a 42 project called push_swap.
The first approach is an implementation of brute force linear search through a linked_list.
This project implements a sorting algorithm designed to sort elements present in two separate stacks.

Features

The current project does not parse data from the terminal. So the starting stack has to be configured from the source code and then recompiled to run

# Warning: Time Complexity Nightmare
- For each element added to the initial stack, the time complexity increase by 100X
- By 6 elements total, it takes my computer around 1.5 seconds to compute
- By 7 elements total, that would take around 2 mins and 40 second
- I did not try to run the program with 8 elements, but by calculation, it would take around 4 hours to compute
- By 8 elements total, it would take around 17 days to compute
- By 9 elements total, it would take around 5 years to compute
- So on and so forth

# How it Works

The program would generate permutations by operating them on 11 rule
1) sa: swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
2) sb: swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
3) ss: sa and sb at the same time.
4) ra: rotate a - shift up all elements of the stack a by 1. The first element becomes
the last one.
5) rb: rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
6) rr: ra and rb at the same time.
7) rrr: rra and rrb at the same time.
8) rra: reverse rotate a - shift down all elements of the stack a by 1. The last element becomes the first one.
9) rrb: reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
10) pa: push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
11) pb: push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

The repeated traversal of the linked_list is the significant drawback of this program. For every permutation generated, the program would travel the linked_list to check if the permutation has been generated before. If the permutation is not found in the linked_list, it will be appended to the head of the linked_list. As the linked_list gets longer and longer, the time it takes to travel can be described as, (n^2 + n) / 2, where n represents the total number of nodes generated in the linked_list

The memory resource complexity increases by 10x for each element added to the initial stack


# Output
Example

Before sorting:

Stack A: 9 4 8 7

Stack B: 0 0 0 0

After sorting (using instructions):

Stack A: 3 4 5 6 7 8 9

Stack B: 0 0 0 0 0 0 0

Instructions

sa

rra

pb

rra

sb
