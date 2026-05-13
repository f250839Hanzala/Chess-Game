# ♟️ Console Chess — C++ OOP Implementation
 
A fully functional **two-player chess game** built in C++ using core Object-Oriented Programming principles. Runs entirely in the terminal with color-coded pieces and standard algebraic notation input.
 
---
 
## 📸 Preview
 
```
  a b c d e f g h
 
8 R N B Q K B N R
7 P P P P P P P P
6 - - - - - - - -
5 - - - - - - - -
4 - - - - - - - -
3 - - - - - - - -
2 P P P P P P P P
1 R N B Q K B N R
```
 
> White pieces are displayed in **white**, Black pieces in **blue** using ANSI escape codes.
 
---
 
## ✅ Features
 
- ♟ All **6 piece types** — Pawn, Rook, Knight, Bishop, Queen, King
- ✔ **Legal move validation** for every piece with full path-obstruction checking
- 🔴 **Check detection** — warns the player when their King is under attack
- 💀 **Checkmate detection** — ends the game and declares the winner
- 🤝 **Stalemate detection** — correctly identifies draws
- 👑 **Pawn promotion** — promote to Queen, Rook, Bishop, or Knight
- 🚫 **Self-capture prevention** — cannot move onto your own piece
- 🔄 **Move simulation** — internally simulates moves to prevent leaving your King in check
- 🎨 **Color-coded board** — ANSI terminal colors for both sides
- 🧭 **Algebraic notation input** — enter moves like `e2` → `e4`
---
 
## 🗂️ Project Structure
 
```
Chess/
├── Header.h       # Class declarations for Piece, all 6 piece types, Board, and Game
├── Source.cpp     # Full implementation of all classes and game logic
└── main.cpp       # Entry point — instantiates and runs the Game
```
 
---
 
## 🧠 OOP Design
 
| Concept | How It's Applied |
|---|---|
| **Abstraction** | `Piece` base class with pure virtual `isLegalMove()` |
| **Inheritance** | `Pawn`, `Rook`, `Knight`, `Bishop`, `Queen`, `King` all extend `Piece` |
| **Polymorphism** | `board[i][j]->isLegalMove(...)` dispatches correctly at runtime |
| **Encapsulation** | Board state and turn tracking are private inside `Board` and `Game` |
| **Dynamic Memory** | Pieces allocated on heap; destructor safely cleans up the entire board |
 
---
 
## 🚀 Getting Started
 
### Prerequisites
 
- A C++ compiler supporting **C++11** or later (`g++`, `clang++`, MSVC)
### Compile
 
```bash
g++ main.cpp Source.cpp -o chess
```
 
### Run
 
```bash
# Linux / macOS
./chess
 
# Windows
chess.exe
```
 
---
 
## 🎮 How to Play
 
1. Launch the game and enter both player names
2. **White always moves first**
3. Enter the source square, then the destination square in algebraic notation:
   ```
   Enter the initial coordinates (like a2): e2
   Enter target coordinates: e4
   ```
4. The board refreshes after every valid move
5. The game ends on **Checkmate** or **Stalemate**
### Piece Symbols
 
| Symbol | Piece |
|--------|-------|
| `P` | Pawn |
| `R` | Rook |
| `N` | Knight |
| `B` | Bishop |
| `Q` | Queen |
| `K` | King |
 
---
 
## ⚠️ Known Limitations
 
- ❌ No **en passant** support
- ❌ No **castling** support
- ❌ Uses `system("cls")` and `system("pause")` — Windows specific (replace with `system("clear")` on Linux/macOS)
- ❌ Input does not gracefully handle non-chess characters
---
 
## 🛠️ Built With
 
- **Language:** C++
- **Paradigm:** Object-Oriented Programming (OOP)
- **I/O:** Standard console with ANSI escape codes for color
---
 
## 📄 License
 
This project is open source and available under the [MIT License](LICENSE).
 
---
 
## 🙌 Contributing
 
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
