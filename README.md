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

 ## Key Generation Process

The program follows the standard S-DES key scheduling algorithm:

10-bit Input Key
        │
      Apply P10
        │
Split into Left & Right Halves
        │
      LS-1
        │
      Apply P8
        │
     Generate K1
        │
      LS-2
        │
      Apply P8
        │
     Generate K2
     
  ---

  
  ## Operation Flow


                 Start
                   │
                   ▼
      Enter 10-bit Binary Key
                   │
                   ▼
          Apply P10 Permutation
                   │
                   ▼
     Split into Two 5-bit Halves
        ┌──────────┴──────────┐
        │                     │
        ▼                     ▼
   Left Half             Right Half
        │                     │
        └──────────┬──────────┘
                   ▼
        Perform LS-1 (Left Shift)
                   │
                   ▼
      Combine Both Shifted Halves
                   │
                   ▼
          Apply P8 Permutation
                   │
                   ▼
          Generate Key 1 (K1)
                   │
                   ▼
      Perform LS-2 on LS-1 Result
                   │
                   ▼
      Combine Both Shifted Halves
                   │
                   ▼
          Apply P8 Permutation
                   │
                   ▼
          Generate Key 2 (K2)
                   │
                   ▼
                  End

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
- Practice bit manipulation in C
- Explore cryptographic permutations

---

## Author

Anjali Ruhil
B.Tech – Network Engineering and Security
Delhi Skill and Entrepreneurship University (DSEU)
