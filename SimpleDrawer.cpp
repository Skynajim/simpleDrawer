#include "SimpleDrawer.hpp"
#include <iostream>

SimpleDrawer::SimpleDrawer(Window_t& window)
:window_(window){
}

void SimpleDrawer::DrawLine(float lineWidth, const Position_t startPosition, const Position_t endPosition, ColorRGBA_t color){
    Position_t lineVec(endPosition-startPosition);
    sf::Angle theta = lineVec.angle();
    sf::Angle PI_RAD = sf::radians(M_PI);

    float width = lineVec.length();
    float height = lineWidth;
    sf::RectangleShape rectangle({width, height});

    Position_t squareOrigin(height/2, theta - PI_RAD/2); //procceding.
    squareOrigin += startPosition; //This is origin of square.

    rectangle.setPosition(squareOrigin);
    rectangle.setRotation(theta);
    rectangle.setFillColor(color);

    window_.draw(rectangle);
}
void SimpleDrawer::DrawPoint(float width, PointShape shape, const Position_t& position, ColorRGBA_t color){
    Pose_t pose(position.x, position.y, 0);
    if(shape == PointShape::circle){
        DrawCircle(width, width, pose, color);
    }else{
        DrawPolygon(width, width, shape, pose, color);
    }
}
void SimpleDrawer::DrawPolygon(float width, float lineWidth, int numOfSides, const Pose_t& pose, ColorRGBA_t color, Aspect_t aspect){
    sf::CircleShape shape(width/2, numOfSides);

    if(width < lineWidth*2 + ALLOWED_CALC_ERROR_){
        shape.setFillColor(color);
    }else{
        shape.setRadius(width-lineWidth*2);
        shape.setFillColor(sf::Color(0, 0, 0, 0));
        shape.setOutlineColor(color);
        shape.setOutlineThickness(lineWidth);
    }

    shape.setScale({1.0, aspect});
    shape.setPosition({pose.x - width/2, pose.y - width/2});
    shape.setRotation(sf::radians(pose.z));

    window_.draw(shape);
}
void SimpleDrawer::DrawCircle(float radius, float lineWidth, const Pose_t& pose, ColorRGBA_t color, Aspect_t aspect){
    sf::CircleShape circle(radius);

    if(radius < lineWidth*2 + ALLOWED_CALC_ERROR_){
        circle.setFillColor(color);
    }else{
        circle.setRadius(radius-lineWidth*2);
        circle.setFillColor(sf::Color(0, 0, 0, 0));
        circle.setOutlineColor(color);
        circle.setOutlineThickness(lineWidth);
    }
    
    circle.setScale({1.0, aspect});
    circle.setPosition({pose.x - radius, pose.y - radius});
    circle.setRotation(sf::radians(pose.z));

    window_.draw(circle);
}
void SimpleDrawer::DrawTexts(std::string msg, int textHeight, const Pose_t& pose, const sf::Font &font, ColorRGBA_t color ,bool isBold, bool isUnderlined){
    sf::Text text(font);
    text.setString(msg);
    text.setCharacterSize(textHeight);
    text.setFillColor(color);
    if(isBold)text.setStyle(sf::Text::Bold);
    if(isUnderlined)text.setStyle(sf::Text::Underlined);

    text.setPosition({pose.x, pose.y});
    text.setRotation(sf::radians(pose.z));
    window_.draw(text);
}