# Simple-DES-Algorithm in C
Simplified DES Algorithm implemented in C with key generation, encryption, and decryption.

## Overview

This project implements the Simplified Data Encryption Standard (S-DES) algorithm in C. It demonstrates the complete encryption and decryption process, including key generation, permutations, and round functions.

---

## Features

- Key Generation
- Initial Permutation (IP)
- Expansion/Permutation (EP)
- S-Boxes
- P4 Permutation
- Round Function (Fk)
- Swap Function (SW)
- Encryption
- Decryption

---

## Technologies Used

- C
- GCC Compiler

---

## Project Structure

src/
include/
examples/

---

## How to Compile

g++ src/*.c -o sdes

---

## Run

./sdes

---

## Example

Plaintext : 10101010

Key : 1010000010

Ciphertext : 01001110

Recovered Plaintext : 10101010

---

## Learning Objectives

- Understand symmetric encryption
- Learn Feistel network concepts
- Practice bit manipulation in C++
- Explore cryptographic permutations

---

## Author

Anjali Ruhil
