text = input("Enter text: ").replace(" ", "").upper()
rail1 = ""
rail2 = ""
for i in range(len(text)):
    if i % 2 == 0:
        rail1 += text[i]
    else:
        rail2 += text[i]
encrypted = rail1 + rail2
print("Encrypted:", encrypted)
mid = (len(encrypted) + 1) // 2
rail1 = encrypted[:mid]
rail2 = encrypted[mid:]
decrypted = ""
for i in range(len(rail1)):
    decrypted += rail1[i]
    if i < len(rail2):
        decrypted += rail2[i]
print("Decrypted:", decrypted)
