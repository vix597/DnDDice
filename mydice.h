#ifndef MYDICE_H
#define MYDICE_H

#include <QList>
#include <QTime>

class Die{
    private:
        int sides;
        int result;
    public:
        Die(int s);
        Die();
        ~Die();
        int Roll();
        int GetResult();
        int GetSides();
        void SetSides(int s);
        int ReRoll();
        void Reset();
};

class MyDice
{
    private:
        QList<Die*> dice;
    public:
        MyDice(int s,int c);
        MyDice(int c);
        MyDice(QList<int> s);
        MyDice();
        ~MyDice();
        int RollAll();
        QList<Die*> GetDice();
        int GetNumberOfDice();
};

#endif // MYDICE_H
