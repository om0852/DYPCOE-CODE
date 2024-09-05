def word_length(s):
    count = 0
    _max = 0
    
    for i in s:
        if i == " ":
            count = 0
        else:
            count += 1
        if count > _max:
            _max = count
    
    print(_max)

def menu():
    while True:
        ch = int(input("Enter Your Choice (1-5): "))
        s = input("Enter String: ")
        
        
        # Execute based on user choice
        if ch == 1:
            word_length(s)
        elif ch == 2:
            pass  # Placeholder for future functionality
        elif ch == 3:
            pass  # Placeholder for future functionality
        elif ch == 4:
            pass  # Placeholder for future functionality
        elif ch == 5:
            break  # Exit the loop to end the program
        else:
            print("Invalid choice. Please select a number between 1 and 5.")

menu()

