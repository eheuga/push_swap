<<<<<<< HEAD
# Push Swap - K-sort
=======
# Push Swap - K-Sort
>>>>>>> aeec83c (push_swap 100%)

## About
This is the final implementation of the push_swap project.
After experimenting with a chunk-based approach (see `chunk_sort` branch),
I moved to a threshold-based algorithm that passes the 42 benchmark.

## How it works

### Operations

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

### Indexing
Before sorting, all values are replaced by their rank (0 to N-1).
This makes the algorithm work with any range of integers.

### Phase 1 - Push to B with threshold
Instead of fixed chunks, a threshold grows progressively.
At each step, if the value at the top of A is within the current
threshold window, it gets pushed to B.
If the pushed value is below the current threshold, rb is applied
to keep smaller values at the bottom of B.
This ensures B is roughly ordered, making phase 2 cheaper.
```c
delta = size / 20 + 7
threshold = 0
while stack_a not empty:
    if top_a <= delta + threshold → pb
        if top_b <= threshold → rb
        threshold++
    else → ra
```

### Phase 2 - Push back to A
Once all elements are in B, `push_max` brings them back to A
by always pushing the maximum value, using rb or rrb depending
on which is closer.


## Performance
| Input size | Operations | 42 limit |
|------------|------------|----------|
| 100 values | ~570 ops   | 700 (5pts)|
| 500 values | ~5150 ops  | 5500 (5pts) |

## What I learned
- How a dynamic threshold outperforms fixed chunks
- The importance of ordering B during the push phase
- Optimization through adaptive window sizing
