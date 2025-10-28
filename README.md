# SimpleDrawer

A simple C++ drawing helper class for SFML.

## Description

`SimpleDrawer` provides a high-level wrapper around an `sf::RenderWindow` to simplify drawing common 2D primitives. It is designed for quick visualization tasks and prototyping, handling basic shapes like lines, points, regular polygons, circles, and text with simple function calls.

This class manages drawing transformations (position, rotation, and aspect ratio) for shapes based on a `Pose_t` (v, h, theta).

## Dependencies

* **SFML** (Graphics module)
* **Eigen** (Core module)

## Usage

Include `SimpleDrawer.hpp` in your project and ensure you link against SFML and Eigen.

### Basic Example

You must first create an `sf::RenderWindow` and (optionally) load an `sf::Font`. Pass the window reference to the `SimpleDrawer` constructor.

```cpp
#include "SimpleDrawer.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    // 1. Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SimpleDrawer Example");
    Window_t& window_ref = window;

    // 2. Load a font (required for DrawTexts)
    sf::Font myFont;
    if (!myFont.loadFromFile("path/to/your/font.ttf"))
    {
        // Handle error
        return -1;
    }

    // 3. Instantiate the drawer
    SimpleDrawer drawer(window_ref);

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // --- 4. Draw shapes ---
        
        // Define poses and positions
        Position_t lineStart(50.f, 50.f);
        Position_t lineEnd(250.f, 100.f);
        Pose_t polyPose(400.f, 200.f, 0.785f); // {v, h, theta}
        Pose_t circlePose(150.f, 400.f, 0.f);
        Pose_t textPose(400.f, 500.f, 0.f);

        // Draw a line
        drawer.DrawLine(3.f, lineStart, lineEnd, sf::Color::Red);
        
        // Draw a point (as a triangle)
        drawer.DrawPoint(10.f, PointShape::triangle, Position_t(300.f, 50.f), sf::Color::Cyan);

        // Draw a polygon (octagon)
        drawer.DrawPolygon(50.f, 2.f, 8, polyPose, sf::Color::Green);

        // Draw a circle
        drawer.DrawCircle(80.f, 1.f, circlePose, sf::Color::Magenta);

        // Draw text
        drawer.DrawTexts("Hello, Drawer!", 24, textPose, myFont, sf::Color::White);

        // --- End drawing ---

        window.display();
    }

    return 0;
}
````

## API Overview

### Types

  * `Window_t`: `sf::RenderWindow`
  * `ColorRGBA_t`: `sf::Color`
  * `Position_t`: `sf::Vector2f` (v, h)
  * `Pose_t`: `sf::Vector3f` (v, h, theta)
  * `Aspect_t`: `float` (height / width)
  * `PointShape`: `enum { circle = 0, triangle = 3, square = 4 }`

### Public Methods

```cpp
class SimpleDrawer {
public:
    // Constructor
    SimpleDrawer(Window_t& window);

    // Draws a line segment
    void DrawLine(float lineWidth, const Position_t startPosition, const Position_t endPosition, ColorRGBA_t color);

    // Draws a point of a specific shape
    void DrawPoint(float width, PointShape shape, const Position_t& position, ColorRGBA_t color);

    // Draws a regular polygon
    void DrawPolygon(float width, float lineWidth, int numOfSides, const Pose_t& pose, ColorRGBA_t color, Aspect_t aspect=1.0);

    // Draws a circle or ellipse (using aspect)
    void DrawCircle(float diameter, float lineWidth, const Pose_t& pose, ColorRGBA_t color, Aspect_t aspect=1.0);

    // Draws text
    void DrawTexts(std::string msg, int textHeight, const Pose_t& pose, const sf::Font &font, ColorRGBA_t color, bool isBold=false, bool isUnderlined=false);
};
```

## License

This project is licensed under the MIT License.

-----

### MIT License

Copyright (c) [2025] [Skynajim]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
