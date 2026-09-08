# Monoalphabetic Cipher

text = input("Enter message: ")

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
key =     "QWERTYUIOPASDFGHJKLZXCVBNM"

# Encryption
encrypted = ""

for ch in text.upper():
    if ch in alphabet:
        encrypted += key[alphabet.index(ch)]
    else:
        encrypted += ch

print("Encrypted:", encrypted)

# Decryption
decrypted = ""

for ch in encrypted:
    if ch in key:
        decrypted += alphabet[key.index(ch)]
    else:
        decrypted += ch

print("Decrypted:", decrypted)
