#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp>
//////////////////////////
sf::RectangleShape O(sf::Vector2f(5, 5));
int BodyDirection[100];
bool acc=0;
std::vector<sf::RectangleShape> Body;
int points =  0;
bool first_food;
sf::Font globalFont;
sf::RectangleShape Food(sf::Vector2f(5, 5));
bool CheckFood();
bool ChechHit(sf::RenderWindow &W);
bool Movement(sf::RenderWindow &W)
{
        if(BodyDirection[0] == 0)
        {
            for(int i=0; i<=4;i++)
            {
            Body[0].move(0, -1);

            ChechHit(W);
            CheckFood();
            }
        }
        if(BodyDirection[0] == 2)
        {
            for(int i=0; i<=4;i++)
            {
            Body[0].move(0, 1);
            ChechHit(W);
            CheckFood();
            }
        }
        if(BodyDirection[0] == 3)
        {
            for(int i=0; i<=4;i++)
            {
            Body[0].move(-1, 0);
            ChechHit(W);
            CheckFood();
            }
        }
        if(BodyDirection[0] == 1)
        {
            for(int i=0; i<=4;i++)
            {
            Body[0].move(1, 0);
           ChechHit(W);
            CheckFood();
            }
        }

}
void Body_Movement(sf::RenderWindow &W)
{

for(int i = 1; i <= (4+points); i++)
    {
        if(BodyDirection[i-1] == 0)
      {
            if(BodyDirection[i] == 0)
            {
                if(Body[i].getPosition().x != Body[i-1].getPosition().x)
                {
                    if(Body[i].getPosition().x > Body[i-1].getPosition().x)
                        {
                            Body[i].move(-5, 0);
                        }
                    else
                        {
                            Body[i].move(5, 0);
                        }


                }
                else Body[i].move(0, -5);
            }
            if(BodyDirection[i] == 1)
            {

                Body[i].move(5, 0);
                if(Body[i].getPosition().x == Body[i-1].getPosition().x)
                    BodyDirection[i] = 0;
            }
            if(BodyDirection[i] == 3)
            {
                Body[i].move(-5, 0);
                if(Body[i].getPosition().x == Body[i-1].getPosition().x)
                    BodyDirection[i] = 0;
            }

          if(BodyDirection[i] == 2)
            {
                if(Body[i].getPosition().x > Body[i-1].getPosition().x && Body[i].getPosition().y > Body[i-1].getPosition().y)
                    {
                        Body[i].move(-5, 0);
                        BodyDirection[i] = 0;
                    }
                    else if(Body[i].getPosition().x < Body[i-1].getPosition().x && Body[i].getPosition().y > Body[i-1].getPosition().y)
                    {
                        Body[i].move(5, 0);
                        BodyDirection[i] = 0;
                    }
            }
       }
    if(BodyDirection[i - 1] == 1)
    {
        if(BodyDirection[i] == 1)
        {
            if(Body[i].getPosition().y != Body[i-1].getPosition().y)
            {
                if(Body[i].getPosition().y > Body[i-1].getPosition().y)
                    BodyDirection[i] = 0;

                else if (Body[i].getPosition().y < Body[i-1].getPosition().y)
                        BodyDirection[i] = 0;
            }
            else
            {
                Body[i].move(5, 0);
            }

        }
            if(BodyDirection[i] == 0)
            {
                Body[i].move(0, -5);
                if(Body[i].getPosition().y == Body[i-1].getPosition().y)
                BodyDirection[i] = 1;
            }
            if(BodyDirection[i] == 2)
            {
                Body[i].move(0, 5);
                if(Body[i].getPosition().y == Body[i-1].getPosition().y)
                BodyDirection[i] = 1;
            }

            if(BodyDirection[i] == 3)
            {
                if(Body[i].getPosition().y > Body[i-1].getPosition().y && Body[i].getPosition().x < Body[i-1].getPosition().x)
                    {
                        Body[i].move(0, -5);
                        BodyDirection[i] = 1;
                    }
                    else if(Body[i].getPosition().y < Body[i-1].getPosition().y && Body[i].getPosition().x < Body[i-1].getPosition().x)
                    {
                        Body[i].move(0, 5);
                        BodyDirection[i] = 1;
                    }
            }
    }
    if(BodyDirection[i - 1] == 2)
    {
        if(BodyDirection[i] == 2)
            {

                if(Body[i].getPosition().x != Body[i-1].getPosition().x)
                {
                    if(Body[i].getPosition().y > Body[i-1].getPosition().y)
                    Body[i].move(-5, 0);
                else
                    Body[i].move(5, 0);
                }
                    else
                        Body[i].move(0, 5);


            }
            if(BodyDirection[i] == 3)
            {
                Body[i].move(-5, 0);
                if(Body[i].getPosition().x == Body[i-1].getPosition().x)
                BodyDirection[i] = 2;
            }
            if(BodyDirection[i] == 1)
            {
                Body[i].move(5, 0);
                if(Body[i].getPosition().x == Body[i-1].getPosition().x)
                BodyDirection[i] = 2;
            }

            if(BodyDirection[i] == 0)
            {
                if(Body[i].getPosition().x > Body[i-1].getPosition().x && Body[i].getPosition().y < Body[i-1].getPosition().y)
                    {
                        Body[i].move(-5, 0);
                        BodyDirection[i] = 2;
                    }
                    else if(Body[i].getPosition().x < Body[i-1].getPosition().x && Body[i].getPosition().y < Body[i-1].getPosition().y)
                    {
                        Body[i].move(5, 0);
                        BodyDirection[i] = 2;
                    }


            }
    }
    if(BodyDirection[i - 1] == 3)
    {
        if(BodyDirection[i] == 3)
            {
                if(Body[i].getPosition().y != Body[i-1].getPosition().y)
                {
                if(Body[i].getPosition().y > Body[i-1].getPosition().y)
                 Body[i].move(0, -5);

                else
                    Body[i].move(0, 5);


                }
                else Body[i].move(-5, 0);

            }
            if(BodyDirection[i] == 2)
            {
                Body[i].move(0, 5);
                if(Body[i].getPosition().y == Body[i-1].getPosition().y)
                BodyDirection[i] = 3;
            }
            if(BodyDirection[i] == 0)
            {
                Body[i].move(0, -5);
                if(Body[i].getPosition().y == Body[i-1].getPosition().y)
                BodyDirection[i] = 3;
            }
            if(BodyDirection[i] == 1)
            {
                if(Body[i].getPosition().y > Body[i-1].getPosition().y && Body[i].getPosition().x > Body[i-1].getPosition().x)
                    {
                        Body[i].move(0, -5);
                        BodyDirection[i] = 3;
                    }
                    else if(Body[i].getPosition().y < Body[i-1].getPosition().y && Body[i].getPosition().x > Body[i-1].getPosition().x)
                    {
                        Body[i].move(0, 5);
                        BodyDirection[i] = 3;
                    }


            }
    }

}


//////////////////////////////////
}

void New_Game(sf::RenderWindow &W)
{
/////////////////Obramowanie
    sf::RectangleShape up(sf::Vector2f(600,5));
    up.setFillColor(sf::Color::White);
    up.setPosition(100,100);
//(0xFFFFFF)
    sf::RectangleShape down(sf::Vector2f(600,5));
    down.setFillColor(sf::Color::White);
    down.setPosition(100, 400);

    sf::RectangleShape left(sf::Vector2f(5, 300));
    left.setFillColor(sf::Color::White);
    left.setPosition(100,100);

    sf::RectangleShape right(sf::Vector2f(5, 305));
    right.setFillColor(sf::Color::White);
    right.setPosition(700,100);
    W.clear();
    W.draw(up);
    W.draw(down);
    W.draw(left);
    W.draw(right);
}

void Food_Generate();


bool CheckFood()
{
    if( abs(Body[0].getPosition().x - Food.getPosition().x) <= 5 && abs(Body[0].getPosition().y - Food.getPosition().y) <= 5)
    {
        Body.push_back(O);
        points++;
        Body[(4 + points)] = Body[0];
        //////////////////////////////////////////////////////////////////////////////////////////
        if(BodyDirection[3 + points] == 0)
        {
            Body[4 + points].setPosition(Body[3 + points].getPosition().x, Body[3 + points].getPosition().y + 5);
            BodyDirection[4 + points] = BodyDirection[3 + points];
        }
        if(BodyDirection[3 + points] == 1)
        {
        Body[4 + points].setPosition(Body[3 + points].getPosition().x-5, Body[3 + points].getPosition().y);
        BodyDirection[4 + points] = BodyDirection[3 + points];
        }
        if(BodyDirection[3 + points] == 2)
        {
        Body[4 + points].setPosition(Body[3 + points].getPosition().x, Body[3 + points].getPosition().y - 5);
        BodyDirection[4 + points] = BodyDirection[3 + points];
        }
        if(BodyDirection[3 + points] == 3)
        {
        Body[4 + points].setPosition(Body[3 + points].getPosition().x+5, Body[3 + points].getPosition().y);
        BodyDirection[4 + points] = BodyDirection[3 + points];
        }

        Food_Generate();
        return true;
    }
}

bool ChechHit(sf::RenderWindow &W)
{
    for(int i = 1; i < (4+points); i++)
    {
        if((abs(Body[0].getPosition().x - Body[i].getPosition().x) <= 2) && (abs(Body[0].getPosition().y - Body[i].getPosition().y) <= 2))
            {
            acc = 1;
            sf::Text napis;
        napis.setString("End game! To play again press space, to quit press esc");
        napis.setFillColor(sf::Color::Black);
        napis.setPosition(165, 250);
        napis.setFont(globalFont);
        napis.setCharacterSize(20);
        globalFont.loadFromFile("OpenSans-Bold.ttf");
        W.clear(sf::Color::White);
        W.draw(napis);
        W.display();
        sf::Event e;
        while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
        bool go = true;
            while(W.pollEvent(e) || go == true)
            {
            if(e.type == sf::Event::Closed)
                W.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                W.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                Body[0].setPosition(400, 250);
                Body[1].setPosition(405, 250);
                Body[2].setPosition(410, 250);
                Body[3].setPosition(415, 250);
                Body[4].setPosition(420, 250);
                while(Body.size() > 5)
                    Body.pop_back();
                BodyDirection[0] = BodyDirection[1] = BodyDirection[2] = BodyDirection[3] = BodyDirection[4] = 3;
                points = 0;
                first_food = true;
                New_Game(W);
                break;
            }
        }
        break;
        }

            }
    }


    if(Body[0].getPosition().x <= 103 || Body[0].getPosition().x >= 698 || Body[0].getPosition().y <= 100 || Body[0].getPosition().y >= 399 )
    {
        acc=1;
        sf::Text napis;
        sf::Text summary;

        summary.setFillColor(sf::Color::Black);
        summary.setPosition(391 , 277);
        summary.setFont(globalFont);
        summary.setCharacterSize(20);
        napis.setString("End game! To play again press space, to quit press esc \n \t \t \t \t \t \t Points:");

        std::string StringPoints = std::to_string(points);
        summary.setString(StringPoints);

        napis.setFillColor(sf::Color::Black);
        napis.setPosition(165 , 250);
        napis.setFont(globalFont);
        napis.setCharacterSize(20);
        globalFont.loadFromFile("OpenSans-Bold.ttf");
        W.clear(sf::Color::White);
        W.draw(napis);
        W.draw(summary);
        W.display();
        sf::Event e;
        while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
       {
        bool go = true;
            while(W.pollEvent(e) || go == true)
            {
            if(e.type == sf::Event::Closed)
                W.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                W.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                Body[0].setPosition(400, 250);
                Body[1].setPosition(405, 250);
                Body[2].setPosition(410, 250);
                Body[3].setPosition(415, 250);
                Body[4].setPosition(420, 250);
                while(Body.size() > 5)
                    Body.pop_back();
                ///////////////////
                BodyDirection[0] = 3;
                BodyDirection[1] = 3;
                BodyDirection[2] = 3;
                BodyDirection[3] = 3;
                BodyDirection[4] = 3;
                points = 0;
                first_food = true;
                New_Game(W);
                break;

            }
       }
        break;
        }
    }
    else
        return false;
}


int main()
{

    for(int i = 0; i < 5; i++)
    {
        Body.push_back(O);
        BodyDirection[i] = 3;
        Body[i].setFillColor(sf::Color::White);
    }
 	Body[0].setPosition(400, 250);
    Body[1].setPosition(405, 250);
    Body[2].setPosition(410, 250);
    Body[3].setPosition(415, 250);
    Body[4].setPosition(420, 250);



    first_food = true;
    sf::RenderWindow W(sf::VideoMode(800,600,32),"Snake");
    sf::Text ShowPoints;
    sf::Text Show;
    Show.setFont(globalFont);
    Show.setString("Points: ");
    Show.setFillColor(sf::Color::White);

    std::string StringPoints;
    StringPoints = std::to_string(points);


    ShowPoints.setFont(globalFont);
    ShowPoints.setString(StringPoints);
    ShowPoints.setFillColor(sf::Color::White);
    ShowPoints.setPosition(103, 0);
    sf::Event e;

    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
    bool go = true;
        while(W.pollEvent(e) || go ==true)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                W.close();
            if(e.type == sf::Event::Closed)
                W.close();

            sf::Text napis;
            napis.setString("To start game press space, to quit press ESC");
            napis.setFillColor(sf::Color::Black);
            napis.setPosition(190, 250);
            napis.setFont(globalFont);
            napis.setCharacterSize(20);
            globalFont.loadFromFile("OpenSans-Bold.ttf");
            W.clear(sf::Color::White);
            W.draw(napis);
            W.display();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                New_Game(W);
                break;
            }
        }
    break;
    }



    sf::Clock clock;
    sf::Time time1;


    while(W.isOpen())
    {

        while(W.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                W.close();
            /////////////////////////////////////////////////////////Movement


            if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) &&(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) )
            {
                if(BodyDirection[0] != 2)
                BodyDirection[0] =  0;

            }

            if((!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) &&(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) )
            {
                if(BodyDirection[0] != 0)
                BodyDirection[0] = 2;

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) )
            {
                if(BodyDirection[0] != 1)
                BodyDirection[0] = 3;


            }
            if((!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) &&(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) )
            {
                if(BodyDirection[0] != 3)
                BodyDirection[0] = 1;
            }

            }

        if(first_food)
        {
            Food_Generate();
            first_food = false;
        }


        time1 = clock.getElapsedTime();
        if (time1.asMilliseconds() >= 1000/20)
        {
            Movement(W);
            Body_Movement(W);
            clock.restart();
        }


        if(acc == 1)
        {
            Body[0].setPosition(400, 250);
            Body[1].setPosition(405, 250);
            Body[2].setPosition(410, 250);
            Body[3].setPosition(415, 250);
            Body[4].setPosition(420, 250);
        }
        acc = 0;

        New_Game(W);
        StringPoints = std::to_string(points);
        ShowPoints.setString(StringPoints);
        acc = false;
        W.draw(Show);
       for(int i = 0; i <= (4 + points); i++)
        {
            W.draw(Body[i]);
        }



        W.draw(Food);
        W.draw(ShowPoints);
        W.display();



    }



}


void Food_Generate()
{
    Food.setFillColor(sf::Color::White);
    srand( time( NULL));
    Food.setPosition((std::rand()%570) + 110, (std::rand()%270) + 110);
}
