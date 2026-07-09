*This project has been created as part of the 42 curriculum by masalaib, dilferre.*

push_swap

Description

push_swap is an algorithmic project from the 42 curriculum whose goal is to sort a stack of integers using the smallest possible number of operations, with only two stacks available and a very limited set of instructions to move data between them.

The program receives a list of integers as arguments, pushes them onto a stack (stack a), and must produce a fully sorted stack (ascending order) using only the following operations:



sa, sb, ss — swap the top two elements of stack a, stack b, or both at once.
pa, pb — push the top element of one stack onto the other.
ra, rb, rr — rotate a stack (or both) up by one, the top element becomes the last.
rra, rrb, rrr — reverse rotate a stack (or both), the last element becomes the top.



The program prints the exact sequence of operations required to sort the stack. The pedagogical goal is to design and compare sorting strategies under an operation-count constraint, which pushes the student to move from a naive O(n²) approach towards more efficient, chunk-based or cost-based approaches.

This implementation goes further than a single fixed algorithm: it embeds several sorting strategies of increasing complexity, and can automatically pick the most suitable one based on how disordered the input is (see "Technical choices" below).

Instructions

Compilation

bashmake

This first builds libft (the project's own C standard-library reimplementation, used for string, memory and linked-list utilities) and then compiles push_swap itself with -Wall -Wextra -Werror.

Other Makefile targets:

bashmake clean   # remove object files (including libft's)
make fclean  # remove object files and the push_swap binary
make re      # fclean + all

Execution

bash./push_swap [OPTIONS] "arg1 arg2 arg3 ..."

Arguments can be passed either as one quoted string of space-separated numbers, or as several separate arguments. Example:

bash./push_swap "4 67 3 87 23"
./push_swap 4 67 3 87 23

If the input is:



empty, or already sorted → the program prints nothing and exits immediately.
invalid (non-numeric, out of int range, or containing duplicate values) → the program prints Error on stderr and exits.



Otherwise, it prints on stdout the ordered list of operations that sorts the stack.

Options

In addition to the list of numbers, the program accepts optional flags that control which sorting strategy is used:

FlagEffect--simpleforces the O(n²) selection-sort-like strategy--mediumforces the O(n·√n) chunk-based strategy--complexforces the O(n log n) cost-based strategy--adaptive (default)measures the input's disorder and picks the appropriate strategy automatically--benchprints statistics on stderr after sorting: disorder ratio, chosen strategy, its complexity, and a breakdown of how many times each operation was used

Example with benchmarking enabled:

bash./push_swap --bench "5 2 9 1 3 8 7 4 6"

Checking correctness / number of operations

A common way to validate the result is to feed the operations back through a checker (a program that replays the operations, often provided by 42 as checker_<os>) and to verify it outputs OK:

bashARG="$(python3 -c "import random; print(' '.join(str(n) for n in random.sample(range(-1000,1000), 100)))")
./push_swap $ARG | ./checker_linux $ARG

The number of operations can also be counted directly:

bash./push_swap $ARG | wc -l

Technical choices

The project implements four selectable strategies, dispatched from dispatch_algorithm():



sort_small — a small, hard-coded solution for stacks of 2 or 3 elements, used as the base case by the other strategies.
sort_simple (--simple) — repeatedly finds the current minimum in stack a, rotates it to the top with the shorter rotation direction, and pushes it to stack b; then pushes everything back. This is the simplest, most direct algorithm and is O(n²) in the number of operations, but is cheap to reason about and implement.
sort_medium (--medium) — a chunk-based (bucket) strategy. Values are first mapped to their rank (0..n-1) to work with dense indices. The stack is split into ranges of roughly √n values; each chunk is pushed to stack b in turn, then stack b is merged back into stack a by inserting each value at its correct position (choosing the shorter rotation direction each time), and a final rotation brings the smallest element to the top. This keeps the number of operations close to O(n·√n).
sort_complex (--complex) — a cost-based strategy inspired by the classic "Turk algorithm" approach to push_swap. For every element still in stack a, it computes the cost (in rotations) of moving it to its correct target position in stack b, combining rotations of both stacks when they can be done simultaneously with rr/rrr. It always executes the cheapest move first, which keeps the total number of operations close to the theoretical O(n log n) optimum. Once only 3 elements remain in stack a, sort_small is used, and the same cost evaluation is applied in reverse to reinsert stack b's values back into stack a in order.
--adaptive (default) — computes a disorder ratio (the fraction of out-of-order pairs in the initial stack, i.e. an inversion count normalized between 0 and 1) and picks the cheapest strategy that is still appropriate: sort_simple for a mostly-sorted stack (disorder < 0.2), sort_medium for a moderately shuffled one (disorder < 0.5), and sort_complex for a strongly shuffled one. This avoids paying the overhead of the most complex algorithm when a cheaper one would already be efficient enough.



This layered design lets the project be graded either on the "worst case, always correct" behaviour of a single strategy, or on the adaptive behaviour that tries to balance operation count against algorithmic complexity depending on input.

Resources

Classic references on the topic:



42's own push_swap subject PDF (project specification).
Codebase - push_swap visualizer and similar community visualizers, useful to watch a stack sort step by step.
Articles on the "Turk algorithm" for push_swap (cost-based greedy approach used here for --complex), widely discussed in the 42 community as the reference for reaching O(n log n) operation counts.
General reading on classic sorting algorithms (selection sort, insertion sort) and on inversion counts / measures of "sortedness", which underlie the --simple, --medium and disorder-ratio logic respectively.
CS documentation on singly linked lists, since the project's stacks are implemented on top of libft's t_list.



Use of AI

An AI assistant (Claude, by Anthropic) was used only for the writing of this README.md file: it inspected the existing source code (Makefile, headers, and the algorithm/options implementation) to accurately describe the project's behaviour, options and algorithms, and drafted the corresponding sections in English. It was not used to design, write, or debug the C source code, the sorting algorithms, or the Makefile, all of which were written by the project's authors.