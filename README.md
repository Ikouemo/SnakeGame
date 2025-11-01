🐍 Snake Game (C++ & SFML)
🎮 Overview

In this project, the classic Snake game is implemented using C++ and SFML (Simple and Fast Multimedia Library).
The player controls a snake that moves continuously around the field, aiming to eat as many apples as possible without colliding with the walls or itself.

Each time the snake eats an apple:

  Its length increases by one grid square
  The score increases by +1

The game ends when the snake collides with a wall or its own body.

🧩 Features
Smooth snake movement on a grid-based field
Random apple placement
Snake grows after eating apples
Score tracking
Collision detection with walls and self
Simple dialog feedback after game over

🛠️ Technologies Used
C++17
SFML 3.0.2
Object-Oriented Programming (OOP) principles
Modern memory management using std::unique_ptr and std::vector

🧱 Project Structure
```txt
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

🧑‍💻 Author
Ivan Wilfried Kouemo
📧 ivanovkouemo@gmail.com
🔗 GitHub: IKouemo

📝 License
This project is licensed under the MIT License — feel free to use and modify it.
