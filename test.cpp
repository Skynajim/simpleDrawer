#include "SimpleDrawer.hpp"
#include <iostream>

int main(void){
    std::cout << "hello world" << std::endl;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
    SimpleDrawer drawer(window);

    sf::Color white(255, 255, 255, 255);
    sf::Color red(255, 0, 0, 255);
    sf::Color green(0, 255, 0, 255);
    sf::Color blue(0, 0, 255, 255);

    sf::Font stdFont("NotoSerifJP-VariableFont_wght.ttf");

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        drawer.DrawLine(2, {20, 20}, {780, 20}, white);
        drawer.DrawLine(2, {780, 20},{780, 580}, white);
        drawer.DrawLine(2, {780, 580}, {20, 580}, white);
        drawer.DrawLine(2, {20, 580}, {20, 20}, white);
        drawer.DrawLine(1, {20, 20}, {780,580}, green);
        drawer.DrawLine(1, {780, 20}, {20, 580}, red);

        drawer.DrawPoint(100, PointShape::circle, {400, 300}, blue);
        drawer.DrawPoint(10, PointShape::triangle, {400, 500}, red);
        drawer.DrawPoint(50, PointShape::square, {400, 200}, green);

        drawer.DrawCircle(20, 5, {200, 200, 0}, red);
        drawer.DrawPolygon(20, 5, 6, {600, 200, 0}, red, 0.5);

        drawer.DrawTexts("YES ", 20, {100, 100, M_PI/6},stdFont,red);
        drawer.DrawTexts("WE ", 20, {200, 200, M_PI/6},stdFont, white,true);
        drawer.DrawTexts(" CAN.", 20, {600, 400, M_PI/6},stdFont,green,true, true);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();

        while(1);
    }
}