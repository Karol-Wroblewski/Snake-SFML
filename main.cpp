#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
//#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp>
//////////////////////////
//Position of snake
struct position
{
    int x;
    int y;
};

int last_move = 4; //how many move we did
sf::RectangleShape O(sf::Vector2f(5, 5)); //To copy Body Patch
int HeadDirection = 3; //Start Direction
bool acc = 0; //if snake have an accident acc = 1
std::vector<sf::RectangleShape> Body;
std::vector<position> Pos; //Position where is snake
int points =  0;
bool first_food; //on the start of the round to generate food
sf::Font globalFont; //Font to subtitles
sf::RectangleShape Food(sf::Vector2f(5, 5));
bool CheckFood(); //Check if snake ate a food
bool ChechHit(sf::RenderWindow &W); //Check if snake Hit a bar or himself

bool Movement(sf::RenderWindow &W)
{
//add new position
            position add;
            add.x = Body[0].getPosition().x;
            add.y = Body[0].getPosition().y;
            Pos.push_back(add);
            ++last_move;
//do a move
        if(HeadDirection == 3)
        {
            for(int i=0; i<=4;i++)
            {
            Body[0].move(-1, 0);
            ChechHit(W);
            CheckFood();
            }
        }

        if(HeadDirection == 0)
        {
            for(int i=0; i<=4;i++)
            {
            Body[0].move(0, -1);
            ChechHit(W);
            CheckFood();
            }
        }
        if(HeadDirection == 2)
        {
            for(int i=0; i<=4;i++)
            {
            Body[0].move(0, 1);
            ChechHit(W);
            CheckFood();
            }
        }
        if(HeadDirection == 1)
        {
            for(int i=0; i<=4;i++)
            {
            Body[0].move(1, 0);
            ChechHit(W);
            CheckFood();
            }
        }
//////
}
void Body_Movement()
{
//Body make a move (replace place where wa a head)
    for(int i = 1; i <= (4 + points); i++)
    {
        Body[i].setPosition(Pos[last_move - i ].x, Pos[last_move - i ].y);
    }

}

void New_Game(sf::RenderWindow &W)
{
/////////////////Building a board
    sf::RectangleShape up(sf::Vector2f(600,5));
    up.setFillColor(sf::Color::White);
    up.setPosition(100,100);

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
    /////////////////////
}

void Food_Generate();


bool CheckFood()
{
    if( abs(Body[0].getPosition().x - Food.getPosition().x) <= 5 && abs(Body[0].getPosition().y - Food.getPosition().y) <= 5)
    {
        Body.push_back(O);  //adding new body patch
        points++;
        Body[(4 + points)] = Body[0];
        Food_Generate();
        return true;
    }
}

bool ChechHit(sf::RenderWindow &W)
{
    //Chech if head hit another part of the body
    for(int i = 1; i < (4+points); i++)
    {
        if((abs(Body[0].getPosition().x - Body[i].getPosition().x) <= 2) && (abs(Body[0].getPosition().y - Body[i].getPosition().y) <= 2))
            {
        sf::Text sub;
        sf::Text summary;

        summary.setFillColor(sf::Color::Black);
        summary.setPosition(391 , 277);
        summary.setFont(globalFont);
        summary.setCharacterSize(20);
        sub.setString("End game! To play again press space, to quit press esc \n \t \t \t \t \t \t Points:");

        std::string StringPoints = std::to_string(points);
        summary.setString(StringPoints);

        sub.setFillColor(sf::Color::Black);
        sub.setPosition(165 , 250);
        sub.setFont(globalFont);
        sub.setCharacterSize(20);
        globalFont.loadFromFile("OpenSans-Bold.ttf");
        W.clear(sf::Color::White);
        W.draw(sub);
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
                            //New Game
                            acc = 1;
                           return true; //back to main
                        }
                    }
                }

            }
    }


    if(Body[0].getPosition().x <= 103 || Body[0].getPosition().x >= 698 || Body[0].getPosition().y <= 100 || Body[0].getPosition().y >= 399 )
    {
    //
        sf::Text sub;
        sf::Text summary;

        summary.setFillColor(sf::Color::Black);
        summary.setPosition(391 , 277);
        summary.setFont(globalFont);
        summary.setCharacterSize(20);
        sub.setString("End game! To play again press space, to quit press esc \n \t \t \t \t \t \t Points:");

        std::string StringPoints = std::to_string(points);
        summary.setString(StringPoints);

        sub.setFillColor(sf::Color::Black);
        sub.setPosition(165 , 250);
        sub.setFont(globalFont);
        sub.setCharacterSize(20);
        globalFont.loadFromFile("OpenSans-Bold.ttf");
        W.clear(sf::Color::White);
        W.draw(sub);
        W.draw(summary);
        W.display();
        sf::Event e;
        while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
       {
            bool go = true;
            while(W.pollEvent(e) || go == true)
            {
                if(e.type == sf::Event::Closed) //EXIT
                    W.close();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //EXIT
                    W.close();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                //NEW GAME
                    acc=1;
                    return true;
                }
            }
        }
    }
    else
        return false;
}


int main()
{
//and Body
    for(int i = 0; i < 5; i++)
    {
        Body.push_back(O);
        Body[i].setFillColor(sf::Color::White);
    }
    //Set Position
 	Body[0].setPosition(400, 250);
    Body[1].setPosition(405, 250);
    Body[2].setPosition(410, 250);
    Body[3].setPosition(415, 250);
    Body[4].setPosition(420, 250);

    position p1, p2, p3, p4, p0;
    p0.x = 420;
    p0.y = 250;
    p1.x = 415;
    p1.y = 250;
    p2.x = 410;
    p2.y = 250;
    p3.x = 405;
    p3.y = 250;

    Pos.push_back(p0);
    Pos.push_back(p1);
    Pos.push_back(p2);
    Pos.push_back(p3);
    /////


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
        while(W.pollEvent(e) || go == true)
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

    W.setFramerateLimit(60); //MAX FPS
    while(W.isOpen())
    {

        while(W.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                W.close();
            /////////////////////////////////////////////////////////Movement


                    if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) &&(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) )
                    {
                        if(HeadDirection != 2)
                            HeadDirection =  0;

                    }

                    if((!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) &&(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) )
                    {
                        if(HeadDirection != 0)
                            HeadDirection = 2;
                    }

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) )
                    {
                        if(HeadDirection != 1)
                            HeadDirection = 3;
                    }
                    if((!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) &&(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) )
                    {
                                if(HeadDirection != 3)
                                    HeadDirection = 1;
                    }

            }

        if(first_food)
        {
            Food_Generate();
            first_food = false;
        }


        time1 = clock.getElapsedTime();
        if (time1.asMilliseconds() >= 50)////////////// Do a move
        {
            Movement(W);
            Body_Movement();
            clock.restart();
        }


        if(acc == 1) //IF was an accident do a board like on the beginning
        {
                while(Body.size() > 5)
                    Body.pop_back();

                while(Pos.size() > 0)
                    Pos.pop_back();

                HeadDirection = 3;
                points = 0;
                last_move = 4;
                first_food = true;
                New_Game(W);

            Body[0].setPosition(400, 250);
            Body[1].setPosition(405, 250);
            Body[2].setPosition(410, 250);
            Body[3].setPosition(415, 250);
            Body[4].setPosition(420, 250);
            Pos.push_back(p0);
            Pos.push_back(p1);
            Pos.push_back(p2);
            Pos.push_back(p3);
        }



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


void Food_Generate() //Generate a food in random place
{
    Food.setFillColor(sf::Color::White);
    srand( time( NULL));
    Food.setPosition((std::rand()%570) + 110, (std::rand()%270) + 110);
}
