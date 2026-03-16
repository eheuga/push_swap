# Push Swap - Chunk Sort

## About
This is my first implementation of the push_swap project.
I chose to implement a chunk-based sorting algorithm as a first approach
before moving on to a more optimized solution (see `main` branch).

## Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements of stack A |
| `sb` | Swap the first 2 elements of stack B |
| `ss` | sa and sb at the same time |
| `pa` | Push the first element of B to the top of A |
| `pb` | Push the first element of A to the top of B |
| `ra` | Rotate A upward (first element becomes last) |
| `rb` | Rotate B upward (first element becomes last) |
| `rr` | ra and rb at the same time |
| `rra` | Reverse rotate A (last element becomes first) |
| `rrb` | Reverse rotate B (last element becomes first) |
| `rrr` | rra and rrb at the same time |

## How it works

### Indexing
Before sorting, all values are replaced by their rank (0 to N-1).
This makes the algorithm work with any range of integers.

### Phase 1 - Push to B by chunks
The indices are divided into chunks of equal size.
For each chunk, `find_closest_in_chunk` finds the element of the current
chunk that is closest to the top of the stack, whether from the top (ra)
or from the bottom (rra). This avoids unnecessary rotations.

### Phase 2 - Push back to A
Once all elements are in B, `push_max` brings them back to A
by always pushing the maximum value, using rb or rrb depending
on which is closer.

### Small cases
- 2 values : sa
- 3 values : hardcoded cases
- 4 values : push min → sort 3 → pa
- 5 values : push 2 mins → sort 3 → pa x2

## Performance
| Input size | Operations | 42 limit |
|------------|------------|----------|
| 100 values | ~720 ops   | 700 (5pts) / 900 (4pts) |
| 500 values | ~7332 ops  | 5500 (5pts) |

The 500 values benchmark does not reach the 5pts score.
This is why I moved on to a threshold-based approach (see `main` branch).

## Why I moved on
The chunk sort has a structural limitation — fixed chunks don't adapt
to the actual distribution of values in the stack.
The threshold approach on `main` fixes this by dynamically adjusting
which values get pushed at each step, reaching ~5174 ops on 500 values.

## What I learned
- Linked list manipulation in C
- Stack operations (push, rotate, reverse rotate)
- Chunk-based sorting logic
- Cost optimization with ra/rra using find_closest_in_chunk