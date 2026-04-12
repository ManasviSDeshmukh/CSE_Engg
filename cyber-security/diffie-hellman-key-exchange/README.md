<h1 align="center">Diffie-Hellman Key Exchange Algorithm</h1>
<p align="center">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=500&size=24&pause=1000&center=true&vCenter=true&width=700&lines=Key+Exchange;Using+Python&fontcolor=2ecc71" alt="Typing SVG" />
</p>

---

## Description
This project demonstrates the implementation of the Diffie-Hellman Key Exchange algorithm using Python.

It allows two users (Alice and Bob) to securely generate a shared secret key over an insecure channel.

---

## Features
- User input for prime number, primitive root, and private keys
- Public key generation
- Shared secret computation
- Verification of key exchange

---

## Algorithm Steps
1. Select prime number `p` and primitive root `g`
2. Alice selects private key `a`
3. Bob selects private key `b`
4. Compute:
   - A = g^a mod p
   - B = g^b mod p
5. Exchange A and B
6. Compute shared key:
   - Alice: K = B^a mod p
   - Bob: K = A^b mod p

---

##  How to Run

```bash
python diffie_hellman.py
```
