===========================================================
      CROSSWORD SOLVER PROJECT - GROUP 07 (HCMUS)
===========================================================

1. PROJECT SETUP
----------------
This project is submitted as a .zip file. After extracting, 
you will obtain the root directory named "07".

NOTE: All commands must be executed from WITHIN the "07" folder.

2. COMPILATION
--------------
Run the following command in your terminal:

g++ source/src/algorithms/*.cpp source/src/processing/*.cpp source/main.cpp -o crossword.exe -std=c++17

3. ALGORITHMS SUPPORTED
-----------------------
Specify the algorithm using the "-a" flag:
- bf  : Brute Force
- rk  : Rabin-Karp
- kmp : Knuth-Morris-Pratt
- bm  : Boyer-Moore
- ac  : Aho-Corasick

4. USER GUIDE (EXECUTION)
-------------------------
Syntax:
crossword.exe -a [algo] -i source/data/[scenario] -o output.txt

Example:
crossword.exe -a kmp -i source/data/scenario1_1.txt -o output.txt

5. DEMO VIDEO SCENARIOS
-----------------------
In the demo video, we executed all supported algorithms (bf, rk, 
kmp, bm, ac) for the following test cases:

- Scenario Set 1: scenario1_1.txt to scenario1_4.txt
- Scenario Set 2: scenario2_1.txt to scenario2_4.txt

To reproduce any test from the video, use the pattern:
crossword.exe -a <algorithm> -i source/data/scenario<X_Y>.txt -o output.txt

6. DIRECTORY STRUCTURE
------------------------------------
- Report.pdf     : Project report.
- video.txt      : Link to the demonstration youtube video.
- source/        : Main folder containing code and data.
    + data/      : All test scenarios (scenario1_1 to 2_4).
    + src/       : Algorithm and logic source files.
    + main.cpp   : Main entry point.
    + readme.txt : This instruction file.
7. CONTACT
---------------------
- Email: dblam2530@clc.fitus.edu.vn

===========================================================