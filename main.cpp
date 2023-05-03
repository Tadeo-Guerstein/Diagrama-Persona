#include <iostream>

using namespace std;

class Commensal
{
public:
    ~Commensal()
    {
    }
    virtual void eatFood() = 0;
};

class Chef
{
public:
    ~Chef()
    {
    }
    virtual void doCooking() = 0;
};

class Child : public Commensal
{
private:
    string name, lastname;

public:
    Child(string name, string lastname)
    {
        this->name = name;
        this->lastname = lastname;
    }
    ~Child()
    {
    }
    void eatFood()
    {
        cout << "Child " << name << " " << lastname << " Eating" << endl;
    }
    string getName()
    {
        return name;
    }
};

class Parent : public Commensal, Chef
{
protected:
    int hunger;

public:
    Parent()
    {
        this->hunger = 0;
    }
    ~Parent()
    {
    }
    void doCooking()
    {
        this->hunger += 10;
        cout << "Parent Cooking "
             << "Your hunger meter is: " << this->hunger << endl;
    }
    void eatFood()
    {
        this->hunger -= 10;
        cout << "Parent Eating "
             << "Your hunger meter is: " << this->hunger << endl;
    }
    virtual void raise(Child *child[]) = 0;
};

class Father : public Parent
{
private:
    string name, lastname;

public:
    Father(string name, string lastname)
    {
        this->name = name;
        this->lastname = lastname;
    }
    ~Father()
    {
    }
    void raise(Child *child[])
    {
        cout << "Father " << name << " " << lastname << " Raising" << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << "His son: " << child[i]->getName() << endl;
        }
    }
};

class Mother : public Parent
{
private:
    string name, lastname;

public:
    Mother(string name, string lastname)
    {
        this->name = name;
        this->lastname = lastname;
    }
    ~Mother()
    {
    }
    void raise(Child *child[])
    {
        cout << "Mother " << name << " " << lastname << " Raising" << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << "His son: " << child[i]->getName() << endl;
        }
    }
};

int main()
{
    Father *father = new Father("Guillermo", "Guerstein");
    Mother *mother = new Mother("Silvia", "Rodriguez");
    Child *child[6];

    child[0] = new Child("Victoria", "Fernandez");
    child[1] = new Child("Nicolas", "Pereyra");
    child[2] = new Child("Maira", "Rodriguez");
    child[3] = new Child("Tadeo", "Guerstein");
    child[4] = new Child("Ariana", "Gutierrez");
    child[5] = new Child("Lorenzo", "Gonzales");

    father->raise(child);
    father->doCooking();
    father->eatFood();
    mother->raise(child);
    mother->doCooking();
    mother->eatFood();
    for (int i = 0; i < 6; i++)
    {
        child[i]->eatFood();
    }

    delete father;
    delete mother;
    delete child[6];
    return 0;
}