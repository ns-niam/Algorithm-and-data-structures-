import math

def min_repetitions_to_contain(A, B):
    min_repeats = math.ceil(len(B) / len(A))
    
    repeated_A = A * min_repeats
    if B in repeated_A:
        return min_repeats
    elif B in repeated_A + A:
        return min_repeats + 1
    elif B in repeated_A + A * 2:
        return min_repeats + 2
    
    return -1

A = input().strip()
B = input().strip()
print(min_repetitions_to_contain(A, B))
