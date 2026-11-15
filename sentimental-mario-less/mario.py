while True:
    try:
        n = int(input("Height: "))  # Prompt user for height input
        if 1 <= n <= 8:           # Check if the input is within the valid range
            break                   # Exit the loop if input is valid
    except ValueError:
        pass  # Ignore invalid input and continue prompting
for i in range(1, n + 1, 1):        # Loop through each row
    for j in range(0, n - i):       # Loop to print spaces before the hashes
        print(" ", end="")
    for k in range(0, i):           # Loop to print hashes for the current row
        print("#", end="")
    print()
