# Tides of Manila: A Merchant's Quest

A turn-based CLI-based game where you trade with various ethnic groups to become the most successful merchant in Manila. Your objective is to meet or exceed your profit target by the end of the month; otherwise, you will lose.

### Features

- A goods market with daily randomized pricing for all goods; and
- An upgradeable ship to increase the amount of cargo you can carry.

## Compilation

Using CMake (v3.15 - v3.30):

```bash
cmake -B ./build -S .
```

Using GCC:

> Add a `.exe` file extension to `ccprog1` if compiling on a Windows machine.

```bash
gcc -Wall -std=c99 -I include src/main.c libs/console.c libs/prompts.c libs/text-graphics.c libs/trading.c -o ccprog1
```

## Usage

If compiled using CMake:

> Add a `.exe` file extension to `ccprog1` if compiling on a Windows machine.

```bash
./bin/ccprog1
```

If compiled using GCC:

> Add a `.exe` file extension to `ccprog1` if compiling on a Windows machine.

```bash
./ccprog1
```

---

<img src="https://upload.wikimedia.org/wikipedia/en/thumb/c/c2/De_La_Salle_University_Seal.svg/2048px-De_La_Salle_University_Seal.svg.png" alt="DLSU Seal" width="150px"> <img src="https://www.dlsu.edu.ph/wp-content/uploads/2019/06/ccs-logo.png" alt="CCS Logo" width="150px">

# De La Salle University

## Undergraduate

The source code for machine project project for **Logic Formulation and Introductory Programmings** || A.Y. 2024 - 2025 (Term 1)

- **Title**: Tides of Manila: A Merchant's Quest
- **Instructor**: Diosdado Nicdao III
