#include "mydice.h"

Die::Die(int s)
{
    sides = s;
    result = 0;
}
Die::Die()
{
    sides = 0;
    result = 0;
}
Die::~Die()
{}
int Die::Roll()
{
    if(sides == 0 || result != 0){
        return 0;
    }

    result = ((int)qrand() %sides) + 1;

    return result;
}
int Die::GetResult()
{
    return result;
}
int Die::GetSides()
{
    return sides;
}
void Die::SetSides(int s)
{
    sides = s;
    result = 0;
}
int Die::ReRoll()
{
    result = 0;
    return Roll();
}
void Die::Reset()
{
    result = 0;
}


MyDice::MyDice(int s, int c)
{
    for(int i=0;i<c;i++){
        dice.append(new Die(s));
    }
}
MyDice::MyDice(int c)
{
    for(int i=0;i<c;i++){
        dice.append(new Die());
    }
}
MyDice::MyDice(QList<int> s)
{
    for(int i=0;i<s.length();i++){
        dice.append(new Die(s.at(i)));
    }
}
MyDice::MyDice()//Default is 1d6
{
    dice.append(new Die(6));
}
MyDice::~MyDice()
{
    for(int i=0;i<dice.length();i++)
        delete dice[i];
    dice.clear();
}

int MyDice::RollAll()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    int total = 0;
    for(int i=0;i<dice.length();i++){
        total += dice[i]->Roll();
    }

    return total;
}
QList<Die*> MyDice::GetDice()
{
    return dice;
}
int MyDice::GetNumberOfDice()
{
    return dice.length();
}

