#include "dataset.h"


Singleton* Singleton::p_instance = 0;

void Singleton::SetThisUserId(int S)
{
    thisUserId = S;
}
int Singleton::GetThisUserId()
{
    return thisUserId;
}
void Singleton::SetHabitId(int S)
{
    habitId = S;
}
int Singleton::GetHabitId()
{
    return habitId;
}
void Singleton::SettimeOfCheck(QDateTime T)
{
    timeOfCheck = T;
}
QDateTime Singleton::GettimeOfCheck()
{
    return timeOfCheck;
}

void Singleton::setScreen(int x, int y)
{
    this->screenX = x;
    this->screenY = y;
}

int Singleton::getScreenX()
{
    return this->screenX;
}

int Singleton::getScreenY()
{
    return this->screenY;
}

void Singleton::setarrOfId(int arr[])
{
    for(int i = 0; i <5 ; i++)
    {
        this->arrOfId[i] = arr[i];
    }
}

int* Singleton::getarrOfId()
{
    return this->arrOfId;
}

