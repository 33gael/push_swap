*This project has been created as part of the 42 curriculum by gaeducas.*

# Push_swap

## Description

**Push_swap** is a 42 school algorithm project. The goal is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for optimized data sorting.

The program calculates and displays the smallest list of instructions to sort the integer arguments received on the standard output.

# You need to know this !!!

The subject tell about you can only use this 11 functions (that you will code them) to sort all the stacks.

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.

### Key Objectives

- Stack manipulation.

## Instructions

### 1. Compilation
To compile the project, run the following command at the root of the repository:

```bash
make
```

### 2. Execution

To execute the program you need to run the following command and add some numbers you want to sort

```bash
./push_swap "and the numbers you want to sort"
```

## RESOURCES

I found several resources on the internet but the main ones are wikipedia for the butterfly algorithm , gemini for the struct of the project and how butterfly algo works, and I asked some questions about linked lists to my peers in the campus