s = input().lower()
for char in ["a", "o", "y", "e", "u", "i"]:
    s = s.replace(char, "")
s = "." + ".".join(s)
print(s)
