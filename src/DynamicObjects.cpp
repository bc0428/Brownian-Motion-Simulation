//
// Created by Brian Cheng on 9/11/2022.
//
#include <cmath>
#include "DynamicObjects.h"
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Constants.h"
#include "omp.h"
#include "iostream"


Ball down = {BALL_DEFAULT_X, boundaryDOWN/2, BALL_RADIUS, velX_INITIAL, velY_INITIAL, sf::Color::Red, BALL_MASS};
Ball up = {BALL_DEFAULT_X, boundaryDOWN, BALL_RADIUS, velX_INITIAL, velY_INITIAL, BALL_COLOR, BALL_MASS};
std::vector<Ball> balls = {up, down};

void addBalls(Ball& b){
    balls.push_back(b);
}

void drawDynamic(sf::RenderWindow& window){
    drawBall(window);

    #pragma omp parallel
    {
        #pragma omp for
        {
            for (Ball &i: balls) {
            i.move();
            i.wallCollision();
            }
        }
    }

        for (Ball& i : balls)
        {
            checkCollision(i);
        }

     window.clear();
}

void drawBall(sf::RenderWindow& window){

        for (Ball& a : balls){
        sf::CircleShape drawableBall;
        drawableBall.setRadius(a.radius);
        drawableBall.setOrigin(a.radius, a.radius);
        drawableBall.setPosition(a.x, a.y);
        drawableBall.setFillColor(a.ball_color);
        window.draw(drawableBall);
        }


    window.display();
}
float afterCollisionVel1(float m1, float m2, float u1, float u2){
    return (2*m2*u2 + u1*(m1-m2)) / (m1+m2);
}
float afterCollisionVel2(float m1, float m2, float u1, float u2){
    return (2*m1*u1 + u2*(m2-m1)) / (m1+m2);
}

void checkCollision(Ball& b){

        for (Ball& other : balls){
            auto isOverlap = [b, other](float dx, float dy){
                return dy*dy + dx*dx < (b.radius + other.radius)*(b.radius + other.radius);
            };

            if (b != other){
                float dx = other.x - b.x;
                float dy = other.y - b.y;

                if(abs(dx)< DETECTION_LENGTH and abs(dy) < DETECTION_LENGTH){
                    //                std::cout<< "X: " << other.x << " Y: " << b.x << std::endl;

                    if (isOverlap(dx,dy)) {
                        //    std::cout << "COLLISION!!!"<<std::endl;
                        float b_vel = sqrt(b.velY * b.velY + b.velX*b.velX);
                        float other_vel = sqrt(other.velY * other.velY + other.velX*other.velX);

                        do {
                            b.x -= b.velX / b_vel * b.radius/100;
                            b.y -= b.velY / b_vel * b.radius/100;
                            other.x -= other.velX / other_vel * other_vel/100;
                            other.y -= other.velY / other_vel * other_vel/100;

                            dx = other.x - b.x;
                            dy = other.y - b.y;
                        } while (isOverlap(dx, dy));

                        updateVelocity(b, other, dx, dy);
                    }
                }
            }
        }
}

void updateVelocity(Ball &b, Ball& other, float dx, float dy) {
    float theta = atan(dx / dy);

//                    linear transformation to the collision plane
    float b_vy = b.velX* sin(theta) + b.velY * cos(theta);
    float other_vy = other.velX* sin(theta) + other.velY * cos(theta);
    float b_vx = b.velX * cos(theta) - b.velY * sin(theta);
    float other_vx = other.velX * cos(theta) - other.velY * sin(theta);;

    // new velocity update, change in perpendicular direction only
    float tempY = afterCollisionVel1(b.mass, other.mass, b_vy, other_vy);
    other_vy = afterCollisionVel2(b.mass, other.mass, b_vy, other_vy);
    b_vy = tempY;

    //reverse back to original plane
    b.velX = b_vx * cos(theta) + b_vy * sin(theta);
    b.velY = -b_vx * sin(theta) + b_vy * cos(theta);
    other.velX = other_vx * cos(theta) + other_vy * sin(theta);
    other.velY = -other_vx * sin(theta) + other_vy * cos(theta);

}




