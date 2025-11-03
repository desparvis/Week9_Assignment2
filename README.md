C Programming 
Group Project: Pointers, Sorting & Memory Management
Project Summary

This group project aims to evaluate and strengthen your understanding of core C programming concepts. You will practice working with pointers, dynamic memory, arrays, strings, function pointers, and modular programming principles while building real-world style applications.

Group Requirements

This is a collaborative assignment — every team member must participate.

Contributions will be tracked through the project’s GitHub repository.

The submission deadline has been extended.

All code must be uploaded to GitHub, and the repository link must be included in the final report.

Grades will be allocated based on each member’s GitHub activity and contributions.

Learning Objectives

By completing this project, you will learn to:

Understand stack vs. heap memory usage

Work with pointers for variables, arrays, and strings

Apply nested loops for data manipulation

Write clean modular functions in C

Use malloc(), calloc(), and free() effectively

Develop programs that correctly allocate and free memory

✅ Task 1: Employee Net Salary Calculator

Write a modular C program that computes an employee’s net salary after deductions:

Deductions include:

Tax (based on salary bracket)

Medical insurance — 5%

Maternity fund — 0.3%

Social security — 3%

Rules & Conditions

Each deduction must be a separate function.

Each function should return values using pointers.

main() must receive the final net salary and output it.

Tax brackets:

≤ $100 → 0%

$100 and ≤ $300 → 20%

$300 → 28%

Reflection:
Explain why pointers are beneficial in this scenario compared to regular variables.

✅ Task 2: Name Sorting Program

Create a program that sorts 20 full names entered by the user.

Requirements

Ask the user whether to sort names in ascending or descending order.

Use Bubble Sort as the sorting method.

Use function pointers to trigger the correct sorting direction.

✅ Task 3: Dynamic Email Storage

Build a program to store email addresses of 10 students from the 2023M cohort using dynamic memory.

Requirements

Allocate memory using malloc() or calloc()

Use free() to release memory properly

Later reduce the memory size to store only 6 emails (without losing existing data)

Use proper memory reallocation

Compilation

Use a C compiler like gcc to compile your programs.

gcc salary_calculator.c -o salary_calculator
./salary_calculator

gcc name_sorter.c -o name_sorter
./name_sorter

gcc memory_management.c -o memory_management
./memory_management


Contributors
Credo
Implemented Net Salary Calculator & handled pointer logic.

Ngugi James
Developed Name Sorting with function pointers and bubble sort.

Kelia Songa Tesi
Handled dynamic memory allocation and shrinking logic for emails.
