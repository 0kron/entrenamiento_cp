positive = input("")
n = int(input(""))

aux = ""
for i in range(n): 
  aux = input("")
  if (aux.replace(positive, "") == ""): print("Yes")
  else: print("No")