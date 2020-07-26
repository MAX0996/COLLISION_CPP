#ifndef BALL_HPP_INCLUDED
#define BALL_HPP_INCLUDED

class Ball
{
    public:
        Ball();
        Ball(sf::Color, float, float, float, float, float);
        sf::CircleShape get_object();
        void setObjectPosition(sf::Time);
        void processCollision(Ball& ball);
        void processCollisionWall(sf::Window &);

    private:
        sf::Vector2f mVit;
        float angle;
        sf::CircleShape mCercle;
        sf::Color mColorCercle;
        float mRadius;
        static bool DisplayVector;
};

#endif // BALL_HPP_INCLUDED
