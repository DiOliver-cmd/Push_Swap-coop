*This project has been created as part of the 42 curriculum by masalaib, dilferre.*

# push_swap

## Description
[cite_start]**push_swap** is an algorithmic project from the 42 curriculum whose goal is to sort a stack of integers using the smallest possible number of operations, with only two stacks available (`stack a` and `stack b`) and a very limited set of instructions to move and manipulate data[cite: 247, 349, 370].

[cite_start]The program receives a list of integers as arguments, pushes them onto `stack a`, and must produce a fully sorted stack in ascending order[cite: 371, 372, 374, 419]. [cite_start]The pedagogical goal is to design, implement, and compare sorting strategies under a strict operation-count constraint, analyzing algorithmic complexity ($O(n^2)$, $O(n\sqrt{n})$, and $O(n \log n)$) in a very concrete way[cite: 264, 355, 390].

[cite_start]This specific implementation embeds four distinct sorting strategies and dynamically selects the most appropriate internal method at runtime based on an initial mathematical disorder metric[cite: 390, 391].

---

## Instructions

### Compilation
[cite_start]The project includes a `Makefile` that compiles the source files with the flags `-Wall -Wextra -Werror` using `cc`, avoiding any unnecessary relinking[cite: 280, 281, 418]. [cite_start]It also automatically handles the compilation of the internal `libft` dependency[cite: 286, 287].

```bash
make          # Compiles the push_swap mandatory binary
make bonus    # Compiles the checker bonus binary
make clean    # Removes object files (including libft's)
make fclean   # Removes object files and binaries
make re       # Performs a full re-compilation (fclean + all)

```

### Execution

```bash
./push_swap [OPTIONS] "arg1 arg2 arg3 ..."
# OR
./push_swap [OPTIONS] 4 67 3 87 23

```

* 
**Sorted/Empty Input:** If no parameters are specified or the integers are already sorted, the program displays nothing and gives the prompt back.


* 
**Error Management:** In case of invalid inputs (non-numeric arguments, values outside the integer range, or duplicate numbers), the program displays `Error` followed by a newline on **stderr**.



### Options / Strategy Selectors

You can force specific algorithms or benchmarking modes using the following flags:

Flag,Effect
--simple,Forces the use of the O(n2) algorithm.
--medium,Forces the use of the O(nn​) algorithm.
--complex,Forces the use of the O(nlogn) algorithm.
--adaptive,(Default) Automatically selects the strategy based on the initial disorder.
--bench,Appends a comprehensive statistics block to stderr after sorting.

---

## Technical Choices & Algorithm Requirements

### 1. Disorder Metric (Mandatory)

Before performing any structural moves, the program computes a normalized **Disorder Metric** between `0.00` and `1.00` ($0\%$ to $100\%$). This metric counts the number of pair inversions relative to the total possible pairs in the stack:

$$\text{Disorder} = \frac{\text{Mistakes}}{\text{Total Pairs}}$$

Where a *mistake* is defined as any pair where $i < j$ but $\text{stack\_a}[i] > \text{stack\_a}[j]$.

### 2. Implemented Strategies & Complexity Arguments

#### A. Simple Algorithm ($O(n^2)$) — `--simple`

* 
**Technique:** Adaptation of Selection/Insertion Sort. It scans `stack a` to find the absolute minimum, rotates it to the top using the shortest path (`ra` or `rra`), and pushes it to `stack b`. This is repeated until `stack a` is empty, then elements are pushed back.


* **Complexity Upper Bounds:** * **Time:** $O(n^2)$ operations. Finding the minimum takes $n$ comparisons, and shifting takes up to $n/2$ operations per element, leading to $\approx \frac{n^2}{2}$ operations.
* **Space:** $O(1)$ auxiliary space beyond the two stack containers.



#### B. Medium Algorithm ($O(n\sqrt{n})$) — `--medium`

* 
**Technique:** Chunk-based sorting using $\sqrt{n}$ blocks. Elements are pre-indexed (ranked from $0$ to $n-1$). The program pushes elements to `stack b` in sequential chunk ranges based on $\sqrt{n}$. Once in `stack b`, elements are strategically re-inserted into their correct sorted position back into `stack a` using optimized rotations.


* **Complexity Upper Bounds:**
* **Time:** $O(n\sqrt{n})$ operations. Partitioning takes $O(n)$ pushes/rotations, and merging chunks with localized cost estimation reduces overall rotation overhead significantly below $n^2$.
* **Space:** $O(n)$ internal memory to map elements to their relative mathematical ranks.



#### C. Complex Algorithm ($O(n \log n)$) — `--complex`

* **Technique:** A cost-optimized approach (inspired by the *Turk Algorithm*). For every single element in `stack a`, the algorithm computes the combined cost of rotation instructions required to place it into its mathematically precise spot in `stack b`, leveraging synchronized rotations (`rr`/`rrr`). The cheapest total instruction package is executed first.


* **Complexity Upper Bounds:**
* **Time:** $O(n \log n)$ operations. The greedy cost calculation scales efficiently, ensuring high-disorder massive stacks are sorted well under the strict evaluation limits.
* **Space:** $O(1)$ auxiliary runtime space since calculations are done directly on the active node parameters.



#### D. Custom Adaptive Algorithm — `--adaptive`

This strategy automatically redirects the input into one of the regimes depending on the initial state of the dataset to save processing cost on partially sorted data. It abides strictly by the subject targets:

* 
**Low Disorder** ($\text{disorder} < 0.2$): Runs the **Simple method** ($O(n^2)$ regime).


* 
**Medium Disorder** ($0.2 \le \text{disorder} < 0.5$): Runs the **Medium method** ($O(n\sqrt{n})$ regime).


* 
**High Disorder** ($\text{disorder} \ge 0.5$): Runs the **Complex method** ($O(n \log n)$ regime).



---

## Performance Targets & Benchmarks

The project strictly meets and outperforms the required performance thresholds verified via the evaluation configuration:

* **For 100 Random Numbers:**
* 
*Subject Maximum Limit:* < 2000 operations 


* 
*Excellent Performance Target:* **< 700 operations** 




* **For 500 Random Numbers:**
* 
*Subject Maximum Limit:* < 12000 operations 


* 
*Excellent Performance Target:* **< 5500 operations** 





### Performance Verification Example

```bash
# Run with 500 random numbers, pipe output to checker, and view metric telemetry on stderr
ARG=$(shuf -i 0-9999 -n 500);
./push_swap --bench --adaptive $ARG 2> bench.txt \vert{} ./checker_linux$ARG
cat bench.txt

```

---

## Bonus Part: The `checker` Program

A custom verification engine named `checker` is implemented under the `bonus` rule. It replicates the testing matrix: it parses the stack layout, reads operations from `stdin` separated by `\n`, executes them internally, and outputs `OK` if the data is sorted (`stack b` must be empty) or `KO` otherwise. Invalid operations trigger standard `Error` logs.

---

## Resources

* 
*Donald Knuth's Sorting and Searching (Big-O Reference Foundations)*.


* 
*42 Push_swap project subject PDF specifications*.


* *Community Push_swap Visualizers (Oatmeal/Leo-Fitz).*
* *Inversion Count & Kendall Tau Distance Mathematics (Underlying principles for the Disorder Metric).*

---

## Use of AI

An AI assistant (Claude, by Anthropic) was utilized strictly to aid in structural layout formulation, technical auditing, and content generation for this `README.md` file. The AI analyzed our codebase configuration parameters to properly document instructions and clarify mathematical definitions. All actual C source code logic, algorithm adaptations, memory mappings, error handlers, and Makefile recipes were written entirely and collaboratively by the human project authors.

```

```
