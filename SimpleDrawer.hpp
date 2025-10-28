#ifndef SIMPLE_DRAWER_HPP_
#define SIMPLE_DRAWER_HPP_

#include <SFML/Graphics.hpp>
#include <Eigen/Core>
#include <vector>
#include <string>
#include <exception>

typedef sf::RenderWindow Window_t;
typedef sf::Color ColorRGBA_t;

typedef sf::Vector2f Position_t;  //[v, h]
typedef sf::Vector3f Pose_t;      //[v, h, theta] *theta:3 o'clock direction is zero.
typedef float Aspect_t;    //height/width

enum PointShape{
    circle = 0,
    triangle = 3,
    square = 4,
};

class SimpleDrawer{
    public:
    SimpleDrawer(Window_t& window);

    void DrawLine(float lineWidth,const Position_t startPosition, const Position_t endPosition, ColorRGBA_t color);
    void DrawPoint(float width, PointShape shape, const Position_t& position, ColorRGBA_t color);
    void DrawPolygon(float width, float lineWidth, int numOfSides, const Pose_t& pose, ColorRGBA_t color, Aspect_t aspect=1.0);
    void DrawCircle(float diameter, float lineWidth, const Pose_t& pose, ColorRGBA_t color, Aspect_t aspect=1.0);
    void DrawTexts(std::string msg, int textHeight, const Pose_t& pose, const sf::Font &font, ColorRGBA_t color ,bool isBold=false, bool isUnderlined=false);
    
    private:
    const float ALLOWED_CALC_ERROR_ = 0.05;
    Window_t& window_;

};
#endif 