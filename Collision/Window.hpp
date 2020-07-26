#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "Ball.hpp"

class App
{
    public:
        App();
        void run();

    private:
        void processEvents();
        void update(sf::Time);
        void render();
        void handleUserInput(sf::Keyboard::Key, bool);
        sf::RenderWindow mWindow;
        sf::Time TimePerFrame;
        Ball mBall_1;
        Ball mBall_2;
        Ball mBall_3;
        Ball mBall_4;
        bool mIsPressingSpace;
};

#endif // WINDOW_HPP_INCLUDED
