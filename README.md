*This project has been created as part of the 42 curriculum by chrihuan and tchian.*

# push_swap

## Description

`push_swap` is an algorithmic C project that requires sorting a randomized stack of integers using two stacks (`a` and `b`) and a highly restricted set of operational moves. The primary goal is to compute and display the absolute minimum sequence of instructions necessary to sort the data in ascending order.

The mandatory part embeds an adaptive strategy selector and supports these operational instructions:

- `sa` and `sb` — swap the first two elements at the top of stack A or stack B.
- `ss` — execute `sa` and `sb` at the same time.
- `pa` — take the first element at the top of B and put it at the top of A.
- `pb` — take the first element at the top of A and put it at the top of B.
- `ra` and `rb` — shift up all elements of stack A or stack B by one (top becomes last).
- `rr` — execute `ra` and `rb` at the same time.
- `rra` and `rrb` — shift down all elements of stack A or stack B by one (last becomes top).
- `rrr` — execute `rra` and `rrb` at the same time.

The custom operational strategy prototypes are:

```c
double compute_disorder(t_stack *a);
void   sort_adaptive(t_stack **a, t_stack **b, double disorder);
```

The goal is to practise algorithmic complexity modeling, dynamic path routing, strict data input parsing, memory leak mitigation, and writing a non-relinking compilation engine.

## Instructions

### Requirements

- A C compiler (`cc`)
- `make`

### Build the program

From the project root, run:

```sh
make
```

This should build the standalone executable program binary:

```text
push_swap
```

The project Makefile provides the rules `all`, `clean`, `fclean`, and `re`, and compiles with the flags `-Wall -Wextra -Werror` using object file tracking to prevent relinking penalties.

### Use the program

Execute the binary directly by passing a space-separated integer list:

```sh
./push_swap 3 1 2
```

You can pass explicit strategy flags or benchmark conditions directly to the binary at runtime:

```sh
./push_swap --simple 5 4 3 2 1
./push_swap --medium 4 67 3 87 23
./push_swap --complex 23 100 45 12 8
./push_swap --bench --adaptive 3 1 2
```

### Clean build files

```sh
make clean
make fclean
make re
```

## Algorithm and Design

The implementation can be organized into three main stages:

1. **Parse and Validate Input Arguments.** Loop through inputs checking syntax. The validator filters out non-numeric characters, catches duplicate entries, and screens against integer overflow. If errors are caught, write `Error\n` to `stderr` and exit cleanly.
2. **Evaluate the Disorder Metric.** Before triggering execution mutations, compute the pre-sortedness of stack A. By checking all combinations, each instance where a larger value precedes a smaller one counts as a mistake. The closer the resulting float ratio is to 1.0, the higher the disorder.
3. **Route the Adaptive Strategy.** Based on the calculated disorder metric ratio, the selector channels runtime logic dynamically into distinct algorithmic tiers: Low disorder (< 0.2) invokes O(n²) sorting, Medium disorder (0.2 to 0.5) utilizes O(n√n) chunk blocks, and High disorder (>= 0.5) unleashes an O(n log n) engine.

The doubly linked list protection: Explicitly implements a stack architecture tracking bidirectional pointers (next and prev) to rewrite node relationships instantly in constant O(1) operational time limits without moving data sequences across memory ranges.

The index assignment optimizer: Note that the parsing loop pre-ranks raw numerical arguments into unified index positions scaling from 0 to N-1, turning massive random input spreads into uniform bit steps that streamline radix and chunk comparisons.

## Testing

Compare the instruction lengths emitted by your program against the strict maximum bounds assigned inside the curriculum guidelines. Test multiple numerical sets and check variations including:

- Tiny random constraints (3 and 5 elements)
- 100 random values (Pass bounds: < 2000, Good: < 1500, Excellent: < 700 operations)
- 500 random values (Pass bounds: < 12000, Good: < 8000, Excellent: < 5550 operations)
- Sorted, reverse-sorted configurations, and integer limit bounds
- Evaluating success via piping commands straight to the automated validation tester

Example test:

```sh
ARG="4 67 3 87 23"; ./push_swap \(ARG \vert{} ./checker_linux\)ARG
```

## Resources

- Donald Knuth: *The Art of Computer Programming, Volume 3: Sorting and Searching* — Foundation for tracking operational time/space bounds and algorithm regimes.
- Standard computer science documentation for bidirectional structures, pointer swapping, and ring arrays.
- The official 42 `push_swap` subject blueprint document supplied for this assignment.

### AI usage

AI tools were used to construct non-relinking compilation maps, plan architectural description modules, review comparative layout bounds for stack manipulation types, and layout tracking schemas for structural pointers.
