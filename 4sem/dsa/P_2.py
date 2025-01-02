
s1={1,2,3,4,5}
s=set([])
def menu():
  while(True):
    print("\n1.insertion\n 2.deletion\n3.contain\n4.display\n5.union\n6.difference\n7.symmetric difference\n8.intersection\n9.print subset")
    ch=int(input("Enter your choice"))
    if ch==1:
        s.add(int(input("Enter Number")))    
    elif ch==2:
        s.discard(int(input("Enter Number")))
    elif ch==3:
       n=int(input("Enter Search element"))
       if n in s:
           print("Element found")
       else:
           print("Element not found")
    elif ch==4:
        print("Size of set :",len(s))
    elif ch==5:
        print("Union:",s.union(s1))
    elif ch==6:
        print("difference:",s-s1)
    elif ch==7:
        print("Symmetric Difference:",s^s1)
    elif ch==8:
        print("Intersection :",s&s1)
    else:
        break
menu();