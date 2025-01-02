def union(l1, l2):
    union_list = []
    for i in l1:
        union_list.append(i)
    for i in l2:
        if i not in union_list:
            union_list.append(i)
    return union_list

def diff(l1, l2):
    diff_list = []
    for i in l1:
        if i not in l2:
            diff_list.append(i)
    return diff_list

def inter(l1, l2):
    inter_list = []
    for i in l1:
        if i in l2:
            inter_list.append(i)
    return inter_list

def symm_diff(l1, l2):
    symm_diff_list = []
    for i in l1:
        if i not in l2:
            symm_diff_list.append(i)
    for i in l2:
        if i not in l1:
            symm_diff_list.append(i)
    return symm_diff_list

def menu():
    cricket = [1, 2, 3]
    badminton = [3, 4, 5]
    football = [4, 5, 6, 7]
    all_students = cricket + badminton + football

    print("\nMenu\n1. List of students who play both cricket and badminton\n2. List of students who play either cricket or badminton but not both\n3. Number of students who play neither cricket nor badminton\n4. Number of students who play cricket and football but not badminton.")
    
    while True:
        ch = int(input("Enter Your Choice: "))
        
        if ch == 1:
            print("Students who play both cricket and badminton:", inter(cricket, badminton))
        elif ch == 2:
            print("Students who play either cricket or badminton but not both:", symm_diff(cricket, badminton))
        elif ch == 3:
           u = union(cricket,badminton)
           print(diff(football,u))
            
        elif ch == 4:
            cricket_and_football = inter(cricket, football)
            result = diff(cricket_and_football, badminton)
            print("Students who play cricket and football but not badminton:", result)
        else:
            break

menu()
