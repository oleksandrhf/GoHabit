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
