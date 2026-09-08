
text = input("Enter text: ").replace(" ", "").upper()
key = [3, 1, 4, 2]
while len(text) % 4 != 0:
    text += "X"
encrypted = ""
for n in range(1, 5):
    col = key.index(n)
    for i in range(col, len(text), 4):
        encrypted += text[i]
print("Encrypted:", encrypted)
decrypted = [""] * len(text)
k = 0
for n in range(1, 5):
    col = key.index(n)
    for i in range(col, len(text), 4):
        decrypted[i] = encrypted[k]
        k += 1
print("Decrypted:", "".join(decrypted))
