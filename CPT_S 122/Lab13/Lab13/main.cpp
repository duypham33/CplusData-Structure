


#include "Task1.h"
#include "Derived.h"

int main(void)
{
    Mammal* pDog = new Dog;
    pDog->Move();
    pDog->Speak();

    delete pDog;

    cout << endl;

    Dog* pDog2 = new Dog;
    pDog2->Move();
    pDog2->Speak();

    delete pDog2;

    Mammal* mammals[5];
    Mammal* ptr = nullptr;
    int choice = 0;
    for (int i = 0; i < 5; i++)
    {
        cout << "(1)dog (2)cat (3)horse (4)guinea pig: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            ptr = new Dog;
            break;
        case 2:
            ptr = new Cat;
            break;
        case 3:
            ptr = new Horse;
            break;
        case 4:
            ptr = new GuineaPig;
            break;
        }

        mammals[i] = ptr;
    }

    for (int i = 0; i < 5; i++)
    {
        if (mammals[i] != NULL)
        {
            mammals[i]->Speak();
            delete mammals[i];
            mammals[i] = nullptr;
        }
    }

    return 0;
}