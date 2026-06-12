# Console-Based Rock Paper Scissors Game

A multi-round Rock-Paper-Scissors interactive console application developed in C++. Built using structured programming methodology, this project demonstrates algorithmic flow control, systematic user input processing, random state generation, and dynamic hardware-linked feedback systems.

---

## Technical Features

### 1. Robust Game Logic Matrix
* **Deterministic Outcome Resolution:** Employs a decoupled evaluation pipeline (`WhoWonTheRound`) utilizing strict conditional validation matrices and structural enums to track player and computer choice states accurately.
* **Pseudo-Random Automation:** Implements a time-seeded random distribution algorithm (`srand`, `rand`) to execute variable computer selections seamlessly during active runtime cycles.

### 2. High-Efficiency System Architecture
* **Halt and Catch Protection:** Enforces restrictive boundary controls on operational rounds (capped securely between 1 and 9 sessions) via continuous verification loops (`HowManyRounds`).
* **Optimized Parameter Handling:** Data transmission across localized drawing and execution contexts leverages constant structural references (`const stRoundInfo&` and `const stGameResults&`) to reduce execution memory footprints and remove unnecessary deep-copy operations.

### 3. Dynamic Console UX Syncing
* **Status UI Feedback:** Synchronizes terminal screen properties directly with game-ending outcomes, using automated standard OS system routines to change color profiles dynamically (Green for player victories, Red with audio alert signals for computer wins, and Yellow for draws).
* **Modular Interface Rendering:** Utilizes structural text formatting buffers to isolate core arithmetic computation from string generation and dashboard logging procedures.

---

## Core Technologies and Concepts Demonstrated
* **Structural Programming:** Execution partitioning using specialized C++ subroutines and pure dynamic functions.
* **Nested State Conditions:** Algorithmic switching structures mapped over variable enumeration values.
* **Data Aggregation:** Game telemetry collection using composite custom `struct` paradigms.

---

## How to Run the Application
1. Clone this repository to your local system environment.
2. Compile the source file using a standard C++ compiler (C++11 or later):
   ```bash
   g++ -std=std=c++11 main.cpp -o RockPaperScissors
