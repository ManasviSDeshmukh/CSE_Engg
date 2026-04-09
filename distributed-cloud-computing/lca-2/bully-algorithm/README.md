<h1 align="center">Bully Election Algorithm</h1>
<h3 align="center">DCC LCA-2</h3>
<p align="center">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=500&size=24&pause=1000&center=true&vCenter=true&width=700&lines=Simulate+Process+Failure+and+Election;Using+C&fontcolor=2ecc71" alt="Typing SVG" />
</p>

---
- **Name:** Manasvi Deshmukh  
- **PRN:** 1032222834
- **Subject:** DCC (Distributed Computing Concepts)  
 

---

## Task Description
### Bully Election Algorithm
- Implement the algorithm using C  
- Simulate process failure and election  

---

## Overview

The **Bully Election Algorithm** is a leader election algorithm used in distributed systems. It ensures that when a coordinator (leader) fails, a new coordinator is elected among the remaining active processes.

The process with the **highest ID** is always selected as the coordinator.

---

## Key Concepts

- Each process has a **unique ID**
- Higher ID ⇒ Higher priority
- If coordinator fails:
  - Lower processes initiate election
  - Highest active process becomes coordinator

---

## Algorithm (Step-by-Step)

1. A process detects that the coordinator has failed  
2. It sends an **ELECTION message** to all higher-ID processes  
3. If no response is received:
   - It becomes the coordinator  
4. If higher processes respond:
   - They take over the election process  
5. The highest active process:
   - Declares itself as the new coordinator  
6. It sends a **COORDINATOR message** to all processes  

---

## Working Explanation

- Initially, all processes are active  
- The process with the highest ID is the coordinator  
- When a process fails:
  - If it is the coordinator → election is triggered  
  - Otherwise → no election required  
- During election:
  - Messages are passed to higher processes  
  - Internal responses simulate distributed communication  
- Final result:
  - New coordinator is elected dynamically  

---

## Implementation Details

- **Language Used:** C  

- **Approach:**
  - Dynamic process creation
  - Menu-driven simulation

---

## Bully Election Process Flow

```mermaid
sequenceDiagram
    participant P1
    participant P2
    participant P3
    participant P4
    participant P5

    Note over P5: Initial Coordinator

    P1->>P5: Detect failure
    Note over P5: P5 Failed

    P1->>P2: Election Message
    P2-->>P1: OK

    P1->>P3: Election Message
    P3-->>P1: OK

    P1->>P4: Election Message
    P4-->>P1: OK

    Note over P4: Highest Active Process

    P4->>P1: Coordinator Announcement
    P4->>P2: Coordinator Announcement
    P4->>P3: Coordinator Announcement
```
---
## Features Implemented

- Dynamic number of processes  
- Process failure simulation  
- Manual election triggering  
- Automatic election on coordinator failure  
 

---

## Requirements

- **Operating System:** Windows / Linux  
- **Compiler:** GCC (MinGW for Windows)  
- **IDE:** VS Code (recommended)  

---
## Steps to Run

### 1. Compile the Code
```bash
gcc bully.c -o bully
```
### 2. Run the Program
```bash
./bully
```
---
## Menu Options

1. Fail Process  
2. Start Election  
3. Exit  

---

## Sample Execution

### Case 1: Coordinator Failure

- Coordinator process is terminated  
- Election is triggered automatically  
- New coordinator is selected  

---

### Case 2: Manual Election

- Election started manually by a process  
- Higher processes respond  
- Highest active process becomes coordinator  

---

## Screenshots

##### Initial process state 
  <img src="screenshots/initial-state.png" alt="Initial process state " width="500" height="auto">

##### Process failure simulation
  <img src="screenshots/process-failure.png" alt="Process failure simulation " width="500" height="auto">  

##### Election process logs
  <img src="screenshots/election-process.png" alt="Election process logs " width="500" height="auto">  

##### New coordinator selection
  <img src="screenshots/new-coordinator.png" alt="New coordinator selection " width="500" height="auto">  

##### Manual election execution
  <img src="screenshots/manual.png" alt="Manual election execution " width="500" height="auto">  

---

## Conclusion

The Bully Election Algorithm was successfully implemented and simulated using C. The system dynamically handles process failures and ensures correct election of a new coordinator. 

---

## Learning Outcomes

- Understanding of distributed leader election  
- Simulation of process communication  
- Handling failure scenarios  
- Implementation of algorithmic logic in C  


