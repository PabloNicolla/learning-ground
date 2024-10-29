def separateNumbers(s):
    n = len(s)

    # Try each possible starting number of length `l`
    for l in range(1, n // 2 + 1):
        # Start with the first `l` digits as the starting number
        first_num = int(s[:l])
        sequence = str(first_num)

        # Build the sequence by incrementing the starting number
        next_num = first_num
        while len(sequence) < n:
            next_num += 1
            sequence += str(next_num)

        # If the built sequence matches the string `s`
        if sequence == s:
            print(f"YES {first_num}")
            return

    # If no valid sequence is found
    print("NO")
