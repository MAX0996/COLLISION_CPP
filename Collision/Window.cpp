#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "Ball.hpp"

App::App(): mWindow(sf::VideoMode(640,480), "SFML Collision")
, mBall_1(sf::Color::Green, 20.f, 50.f, 100.f, 200.f, 200.f)
, mBall_2(sf::Color::Yellow, 50.f, 200.f, 230.f, 50.f, 100.f)
, mBall_3(sf::Color::Cyan, 70.f, 350.f, 120.f, -20.f, 135.f)
, mBall_4(sf::Color::Magenta, 35.f, 40.f, 400.f, -100.f, -180.f)
{
    TimePerFrame = sf::seconds(1.f/120.f);
}

void App::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            mBall_1.processCollision(mBall_2);
            mBall_1.processCollision(mBall_3);
            mBall_1.processCollision(mBall_4);
            mBall_2.processCollision(mBall_1);
            mBall_2.processCollision(mBall_3);
            mBall_2.processCollision(mBall_4);
            mBall_3.processCollision(mBall_1);
            mBall_3.processCollision(mBall_2);
            mBall_3.processCollision(mBall_4);
            mBall_4.processCollision(mBall_1);
            mBall_4.processCollision(mBall_2);
            mBall_4.processCollision(mBall_3);
            mBall_1.processCollisionWall(mWindow);
            mBall_2.processCollisionWall(mWindow);
            mBall_3.processCollisionWall(mWindow);
            mBall_4.processCollisionWall(mWindow);
            update(TimePerFrame);
        }
        render();
    }
}

void App::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::KeyPressed:
                handleUserInput(event.key.code, true);
                break;

            case sf::Event::Closed:
                mWindow.close();
                break;

            case sf::Event::KeyReleased:
                handleUserInput(event.key.code, false);
                break;
        }
    }

    return;
}

void App::handleUserInput(sf::Keyboard::Key key, bool isPressed)
{
    if(key == sf::Keyboard::Space) {
        mIsPressingSpace = isPressed;
    }

    return;
}

void App::update(sf::Time TimePerFrame)
{
    mBall_1.setObjectPosition(TimePerFrame);
    mBall_2.setObjectPosition(TimePerFrame);
    mBall_3.setObjectPosition(TimePerFrame);
    mBall_4.setObjectPosition(TimePerFrame);
    return;
}

void App::render()
{
    mWindow.clear();
    mWindow.draw(mBall_1.get_object());
    mWindow.draw(mBall_2.get_object());
    mWindow.draw(mBall_3.get_object());
    mWindow.draw(mBall_4.get_object());
    mWindow.display();

    return;
}
