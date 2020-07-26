#ifndef INLINE_HPP_INCLUDED
#define INLINE_HPP_INCLUDED
#include <math.h>
#include <iostream>
#define PI 3.1415926535

double calculerAngleVecteur2f(sf::Vector2f Vect)
{
    double angle;
    Vect.y *=-1;
    normalisationVecteur2f(Vect);

    if(Vect.x >= 0 && Vect.y >=0) {
        angle = acos(Vect.x);
    }
    else if(Vect.x <= 0 && Vect.y >=0) {
        angle = acos(Vect.x);
    }
    else if(Vect.x <=0 && Vect.y <=0) {
        angle = acos(Vect.x);
        angle = PI - angle;
        angle = PI + angle;
    }
    else if(Vect.x >=0 && Vect.y <=0) {
        angle = 2*PI - acos(Vect.x);
    }
    return angle;
}

void normalisationVecteur2f(sf::Vector2f& Vect)
{
    Vect = (Vect)*(1/sqrt(Vect.x*Vect.x + Vect.y*Vect.y));
    return ;
}
#endif // INLINE_HPP_INCLUDED
