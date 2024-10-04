from typing import Tuple, Callable
from stringdata import get_data
from time import time


def main():
    data = get_data()  # Access the data set from the stringdata module

    result, runtime = time_of_algorithm(linear_search, data, "not_here")
    print(f'Result of Linear Search for "not_here": {result}')
    print(f"Time: {runtime}", end="\n\n")

    result, runtime = time_of_algorithm(binary_search, data, "not_here")
    print(f'Result of Binary Search for "not_here": {result}')
    print(f"Time: {runtime}", end="\n\n")

    result, runtime = time_of_algorithm(linear_search, data, "mzzzz")
    print(f'Result of Linear Search for "mzzzz": {result}')
    print(f"Time: {runtime}", end="\n\n")

    result, runtime = time_of_algorithm(binary_search, data, "mzzzz")
    print(f'Result of Binary Search for "mzzzz": {result}')
    print(f"Time: {runtime}", end="\n\n")

    result, runtime = time_of_algorithm(linear_search, data, "aaaaa")
    print(f'Result of Linear Search for "aaaaa": {result}')
    print(f"Time: {runtime}", end="\n\n")

    result, runtime = time_of_algorithm(binary_search, data, "aaaaa")
    print(f'Result of Binary Search for "aaaaa": {result}')
    print(f"Time: {runtime}", end="\n\n")


# Finds runtime of called algorithm and returns result of algorithm
def time_of_algorithm(
    search: Callable[[Tuple[str], str], int], data: Tuple[str], element: str
) -> Tuple[str, str]:
    start_time = time()
    result = search(data, element)
    end_time = time()
    runtime = end_time - start_time
    return str(result), str(runtime)


# O(logn)
def binary_search(container: Tuple[str], element: str) -> int:
    low = 0  # First index of container
    high = len(container) - 1  # Last index of container
    mid = midpoint(low, high)
    old_mid = -1

    while old_mid != mid:  # Break when we check the same spot
        if container[mid] == element:
            return mid
        elif element < container[mid]:  # Need to look earlier in container
            old_mid = mid
            high = mid - 1  # New high is everything before mid
            mid = midpoint(low, high)
        else:  # Need to look later in container
            old_mid = mid
            low = mid + 1  # New low is everything after mid
            mid = midpoint(low, high)

    return -1


# O(n)
def linear_search(container: Tuple[str], element: str) -> int:
    for i in range(0, len(container)):
        if container[i] == element:
            return i

    return -1


def midpoint(low: int, high: int) -> int:
    return (low + high) // 2


if __name__ == "__main__":
    main()
