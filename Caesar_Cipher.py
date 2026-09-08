text = input("Enter message: ")
key = int(input("Enter key: "))
encrypted = ""
for ch in text:
    if ch.isalpha():
        encrypted += chr((ord(ch.upper()) - 65 + key) % 26 + 65)
    else:
        encrypted += ch
print("Encrypted:", encrypted)
decrypted = ""
for ch in encrypted:
    if ch.isalpha():
        decrypted += chr((ord(ch.upper()) - 65 - key) % 26 + 65)
    else:
        decrypted += ch
print("Decrypted:", decrypted)
