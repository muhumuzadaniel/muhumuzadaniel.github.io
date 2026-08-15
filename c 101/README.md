# Blooming Buds Nursery Enrollment

A console-based C program that manages child enrollment for **Blooming Buds Nursery School**. It collects child bio data, parent/guardian details, and fee payment information, then prints a formatted payment receipt for each enrolled child.

---

## Features

- Collects **Child Bio Data**: first name, last name, date of birth, and gender.
- Collects **Parent / Guardian Details**: name, relationship, phone, email, and address.
- Processes **Fee Payments**: calculates the balance (or overpayment credit) from fees due and amount paid.
- Prints a **formatted payment receipt** with a unique receipt number in the format `NR/2025/xxx`.
- Supports **multiple enrollments** in a single session via a looped menu.
- Demonstrates use of C **structs**, `scanf`/`printf` I/O, `sprintf` for string formatting, and basic arithmetic.

---

## Build Requirements

| Requirement | Details |
|-------------|---------|
| C Compiler  | GCC 7+ or Clang 6+ (any C99-compatible compiler) |
| OS          | Linux, macOS, or Windows (with MinGW / MSVC) |
| Build tools | None beyond the compiler — no Makefile or CMake needed |

---

## Compile and Run

### Linux / macOS

```bash
gcc project.c -o nursery-enrollment
./nursery-enrollment
```

### Windows (MinGW)

```cmd
gcc project.c -o nursery-enrollment.exe
nursery-enrollment.exe
```

### Windows (MSVC)

```cmd
cl project.c /Fe:nursery-enrollment.exe
nursery-enrollment.exe
```

---

## Usage

Once the program starts, follow the on-screen prompts in three sections:

1. **Child Bio Data** — Enter the child's first name, last name, date of birth (`DD/MM/YYYY`), and gender.
2. **Parent / Guardian Details** — Enter the guardian's first name, last name, relationship to the child, phone number, email address, and physical address.
3. **Fee Payment** — Enter the total fees due and the amount paid. The program calculates the remaining balance (or shows an overpayment credit).

After each entry, a receipt is printed and you are given the option to:
- `1` — Record another child
- `2` — Exit the program

> **Note:** All text fields use space-terminated `scanf` tokens, so **multi-word inputs are not supported** (e.g., enter `Kampala` rather than `Kampala City`). See [Limitations](#limitations--todos) below.

---

## Example Run

```
=== BLOOMING BUDS NURSERY ENROLLMENT ===

--- CHILD BIO DATA ---
First Name: Alice
Last Name: Nakato
Date of Birth (DD/MM/YYYY): 15/06/2022
Gender: Female

--- PARENT / GUARDIAN DETAILS ---
First Name: Sarah
Last Name: Nakato
Relationship: Mother
Phone: 0712345678
Email: sarah.nakato@email.com
Address: Kampala

--- FEE PAYMENT ---
Total Fees Due: 500000
Amount Paid: 300000

========== PAYMENT RECEIPT ==========
Receipt No.: NR/2025/001
Child: Alice Nakato
DOB: 15/06/2022 | Gender: Female
Parent/Guardian: Sarah Nakato (Mother)
Contact: 0712345678 | Email: sarah.nakato@email.com
Address: Kampala
-------------------------------------
Fees Due   : 500000.00
Amount Paid: 300000.00
Balance    : 200000.00
Thank you for trusting Blooming Buds Nursery!
=====================================

Options:
1. Record another child
2. Exit
Choose 1 or 2:
```

---

## Limitations / TODOs

- **`scanf` whitespace handling** — Fields are read with `scanf("%s", ...)`, which stops at the first whitespace character. Multi-word values (e.g., addresses with spaces) are not captured correctly. A future improvement would use `fgets` or a custom input function.
- **No file or database persistence** — Enrollment records exist only during the current session. Once the program exits, all data is lost. A future version could write records to a CSV file or a lightweight database.
- **Minimal input validation** — The program does not validate date formats, phone numbers, email addresses, or whether numeric fee values are sensible (e.g., negative amounts are accepted).
- **Receipt serial resets each run** — The `receiptSerial` counter starts at `1` every time the program is launched, so receipt numbers are not globally unique across sessions.
- **Single-session loop only** — There is no persistent menu beyond "record another child / exit"; administrative features (search, edit, delete records) are not implemented.

---

## License

No license specified — all rights reserved by the author.

---

## Contact

**Author:** Elijah Newton  
**Email:** musiitwaelijah@gmail.com
