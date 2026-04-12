# Diffie-Hellman Key Exchange Implementation
# Author: Manasvi Deshmukh
# Description: Demonstrates secure key exchange using public key cryptography

# Function to compute power with modulo
def mod_exp(base, exp, mod):
    return pow(base, exp, mod)


# Step 1: Take user inputs
print("=== Diffie-Hellman Key Exchange ===")

# Prime number (public)
p = int(input("Enter a prime number (p): "))

# Primitive root (public)
g = int(input("Enter a primitive root (g): "))

# Private keys (secret)
a = int(input("Enter Alice's private key: "))
b = int(input("Enter Bob's private key: "))


# Step 2: Generate Public Keys
A = mod_exp(g, a, p)  # Alice's public key
B = mod_exp(g, b, p)  # Bob's public key

print("\n--- Public Keys ---")
print(f"Alice's Public Key (A): {A}")
print(f"Bob's Public Key (B): {B}")


# Step 3: Exchange keys and generate shared secret
# Alice computes shared key
shared_key_alice = mod_exp(B, a, p)

# Bob computes shared key
shared_key_bob = mod_exp(A, b, p)

print("\n--- Shared Secret Keys ---")
print(f"Alice's Computed Key: {shared_key_alice}")
print(f"Bob's Computed Key: {shared_key_bob}")


# Step 4: Verification
if shared_key_alice == shared_key_bob:
    print("\n Key Exchange Successful! Shared Secret Key:", shared_key_alice)
else:
    print("\n Key Exchange Failed!")
