# 🐍 Snake Game (C++ & SFML)

## 🎮 Overview

![ScreenRecording2025-11-03at16 24 52-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/0908af45-b24e-428d-bcbb-50363d8c497d)

This project is a modern implementation of the **classic Snake game** using **C++** and the **SFML (Simple and Fast Multimedia Library)** framework.

You control a snake that moves around the grid-based field, eating apples to grow longer while avoiding collisions with walls or itself.

**Gameplay mechanics:**

* 🧃 Each apple eaten increases the snake’s length by one square
* 🏆 The score increases by **+1** for every apple eaten
* 💥 The game ends if the snake hits a wall or its own body

---

## 🧩 Features

✅ Smooth, grid-based snake movement
🍎 Random apple spawning
🐍 Snake growth after eating apples
💯 Real-time score tracking
🧱 Collision detection (walls & self)
💬 Simple end-game feedback dialog

---

## 🛠️ Technologies Used

* **C++17**
* **SFML 3.0.2**
* **Object-Oriented Programming (OOP)** principles
* **Modern memory management** (`std::unique_ptr`, `std::vector`)

---

## 🧱 Project Structure

```
SnakeGame/
│
├── Apple.cpp / Apple.hpp         # Apple item logic
├── Brick.cpp / Brick.hpp         # Wall segments
├── GameItem.cpp / GameItem.hpp   # Abstract base class for items
├── Snake.cpp / Snake.hpp         # Snake movement and logic
├── SnakeGame.cpp / SnakeGame.hpp # Main game loop and rendering
├── Point.cpp / Point.hpp         # Coordinate handling
├── main.cpp                      # Entry point
├── .gitignore
└── arial.ttf                     # Font file
```

---

## 🧑‍💻 Author

**Ivan Wilfried Kouemo**
📧 [ivanovkouemo@gmail.com](mailto:ivanovkouemo@gmail.com)
🔗 [GitHub: IKouemo](https://github.com/IKouemo)

---

## 📝 License

This project is licensed under the **MIT License** — feel free to use, modify, and distribute it freely.
