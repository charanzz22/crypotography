key = [[3, 3],
       [2, 5]]
text = input("Enter 2-letter message: ").upper()
a = ord(text[0]) - 65
b = ord(text[1]) - 65
x = (3 * a + 3 * b) % 26
y = (2 * a + 5 * b) % 26

encrypted = chr(x + 65) + chr(y + 65)
print("Encrypted:", encrypted)
inv = [[15, 17],
       [20, 9]]
x = (15 * (ord(encrypted[0]) - 65) +
     17 * (ord(encrypted[1]) - 65)) % 26
y = (20 * (ord(encrypted[0]) - 65) +
     9 * (ord(encrypted[1]) - 65)) % 26
decrypted = chr(x + 65) + chr(y + 65)
print("Decrypted:", decrypted)
