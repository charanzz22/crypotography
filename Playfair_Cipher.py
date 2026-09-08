# Playfair Cipher

m = ["MONAR", "CHYBD", "EFGIK", "LPQST", "UVWXZ"]

text = input("Enter a text: ").upper().replace(" ", "")
text = text.replace("J", "I")

# Add X if text has odd number of letters
if len(text) % 2 != 0:
    text = text + "X"

def pos(ch):
    for i in range(5):
        for j in range(5):
            if m[i][j] == ch:
                return i, j

encrypted = ""

# Encryption
for i in range(0, len(text), 2):

    a = text[i]
    b = text[i + 1]

    r1, c1 = pos(a)
    r2, c2 = pos(b)

    if r1 == r2:
        e1 = m[r1][(c1 + 1) % 5]
        e2 = m[r2][(c2 + 1) % 5]

    elif c1 == c2:
        e1 = m[(r1 + 1) % 5][c1]
        e2 = m[(r2 + 1) % 5][c2]

    else:
        e1 = m[r1][c2]
        e2 = m[r2][c1]

    encrypted = encrypted + e1 + e2

print("Encrypted:", encrypted)


# Decryption
decrypted = ""

for i in range(0, len(encrypted), 2):

    a = encrypted[i]
    b = encrypted[i + 1]

    r1, c1 = pos(a)
    r2, c2 = pos(b)

    if r1 == r2:
        d1 = m[r1][(c1 - 1) % 5]
        d2 = m[r2][(c2 - 1) % 5]

    elif c1 == c2:
        d1 = m[(r1 - 1) % 5][c1]
        d2 = m[(r2 - 1) % 5][c2]

    else:
        d1 = m[r1][c2]
        d2 = m[r2][c1]

    decrypted = decrypted + d1 + d2

print("Decrypted:", decrypted)
