#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Ball.hpp"
#include "inline.h"

static bool DisplayVector=1;

using namespace std;

Ball::Ball()
{
    mVit=sf::Vector2f (100.f,-100.f);
    mRadius = 50.f;
    mCercle.setRadius(100.f);
    mCercle.setPosition(100.f,100.f);
    mCercle.setFillColor(sf::Color::Red);
    mColorCercle = sf::Color::Red;
}

Ball::Ball(sf::Color color, float Radius, float abs, float ord, float vit_x, float vit_y)
{
    mVit=sf::Vector2f (vit_x,vit_y);
    mRadius = Radius;
    mCercle.setRadius(Radius);
    mCercle.setFillColor(color);
    mCercle.setPosition(abs, ord);
    mColorCercle = color;
}

sf::CircleShape Ball::get_object()
{
    return mCercle;
}

void Ball::setObjectPosition(sf::Time TimePerFrame)
{
    mCercle.move(mVit * TimePerFrame.asSeconds());

    return ;
}

void Ball::processCollisionWall(sf::Window& window)
{
    sf::Vector2u dim_Wall = window.getSize();
    sf::Vector2f pos_ball = mCercle.getPosition();

    if((pos_ball.x <= 0 && mVit.x < 0) || (pos_ball.x + 2*mRadius >= dim_Wall.x && mVit.x > 0)) {
        mVit.x *= -1;
    }
    else if((pos_ball.y <=0 && mVit.y < 0) || (pos_ball.y + 2*mRadius >= dim_Wall.y && mVit.y > 0)) {
        mVit.y *= -1;
    }

    return;
}

void Ball::processCollision(Ball& ball)
{
    sf::Vector2f pos_c_ball = ball.mCercle.getPosition();
    sf::Vector2f pos_c_Ball = mCercle.getPosition();
    sf::Vector2f temp;
    float norme;
    float angle_Ball, angle_tangente_collision;

    pos_c_ball.x += ball.mRadius;
    pos_c_ball.y += ball.mRadius;

    pos_c_Ball.x += mRadius;
    pos_c_Ball.y += mRadius;

    norme = sqrt((mVit.x*mVit.x) + ((mVit.y)* (mVit.y)));

    float distance_2c = sqrt(abs(pos_c_ball.x - pos_c_Ball.x)*abs(pos_c_ball.x - pos_c_Ball.x) + abs(pos_c_ball.y - pos_c_Ball.y)*abs(pos_c_ball.y - pos_c_Ball.y));

    if(distance_2c <= mRadius + ball.mRadius) {
        temp.x = pos_c_ball.y - pos_c_Ball.y ; // Temp = vecteur directeur de la tangente
        temp.y = pos_c_Ball.x - pos_c_ball.x;  //

        angle_tangente_collision = calculerAngleVecteur2f(temp);
        angle_Ball = calculerAngleVecteur2f(mVit);

        angle_Ball = 2*angle_tangente_collision - angle_Ball;

        temp.x = cos(angle_Ball);
        temp.y = sin(angle_Ball); //Temp nouvelle direction de la balle après collision

        mVit.x = temp.x * norme;
        mVit.y = -temp.y * norme;
    }

    return;
}
