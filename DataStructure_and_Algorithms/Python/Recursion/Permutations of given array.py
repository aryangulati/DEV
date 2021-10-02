from typing import List     # Using 'typing' module to set type of data for permutations function arguments and its return type

# Recursive function to find all permutations of N numbers
def permutations(numbers: List[int]) -> List[List[int]]:
    # Base case of zero or a single number
    if len(numbers)<2: return [numbers]
    # Base case of just two numbers
    elif len(numbers)==2: return [numbers, numbers[::-1]]
    else:
        # Recursive case of more than two numbers
        allPermutations = []
        for index in range(len(numbers)):
            for permutation in permutations(numbers[:index]+numbers[index+1:]):
                allPermutations.append([numbers[index]] + permutation)

        return allPermutations

# __main__.py
numbers = [1, 2, 3, 4]          # Example of numbers array
numbers = numbers[:7]           # Using more than 7 numbers takes significantly a lot of time, so just using slicing to ensure the numbers aren't more than 7, for a quick test

print(permutations(numbers))

"""
Output:
[[1, 2, 3, 4], [1, 2, 4, 3], [1, 3, 2, 4], [1, 3, 4, 2], [1, 4, 2, 3], [1, 4, 3, 2], [2, 1, 3, 4], [2, 1, 4, 3], [2, 3, 1, 4], [2, 3, 4, 1], [2, 4, 1, 3], [2, 4, 3, 1], [3, 1, 2, 4], [3, 1, 4, 2], [3, 2, 1, 4], [3, 2, 4, 1], [3, 4, 1, 2], [3, 4, 2, 1], [4, 1, 2, 3], [4, 1, 3, 2], [4, 2, 1, 3], [4, 2, 3, 1], [4, 3, 1, 2], [4, 3, 2, 1]]
"""