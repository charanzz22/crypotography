# Polyalphabetic Cipher

text = input("Enter message: ").upper()
key = input("Enter key: ").upper()

# Encryption
encrypted = ""

for i in range(len(text)):
    encrypted += chr((ord(text[i]) - 65 + ord(key[i % len(key)]) - 65) % 26 + 65)

print("Encrypted:", encrypted)

# Decryption
decrypted = ""

for i in range(len(encrypted)):
    decrypted += chr((ord(encrypted[i]) - 65 - (ord(key[i % len(key)]) - 65)) % 26 + 65)

print("Decrypted:", decrypted)
