#pragma once

class Point {

private:
    int x;                                      // X coordinate on the game grid.
    int y;                                      // Y coordinate on the game grid.

public: 
    Point (int x_, int y_);                     // Constructor that initializes a point with given X and Y coordinates
    int getX() const;                           // Returns the X coordinate of the point (read-only)
    int getY() const;                           // Returns the Y coordinate of the point (read-only)
    
};