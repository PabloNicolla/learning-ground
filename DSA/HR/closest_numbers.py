def closestNumbers(arr):
    # Sort the array
    arr.sort()

    # Initialize variables
    min_diff = float('inf')
    result = []

    # Find the smallest difference between consecutive elements
    for i in range(len(arr) - 1):
        diff = arr[i + 1] - arr[i]

        if diff < min_diff:
            # Found a new smaller difference, reset the result list
            min_diff = diff
            result = [(arr[i], arr[i + 1])]
        elif diff == min_diff:
            # Found a pair with the same minimum difference
            result.append((arr[i], arr[i + 1]))

    # Flatten the result list to match the required output format
    flat_result = [num for pair in result for num in pair]
    return flat_result
