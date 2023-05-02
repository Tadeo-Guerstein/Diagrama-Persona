#include <iostream>

using namespace std;

class Commensal
{
public:
    Commensal()
    {
    }
    ~Commensal()
    {
    }
    virtual void EatFood() = 0;
};

class Chef
{
public:
    Chef()
    {
    }
    ~Chef()
    {
    }
    virtual void DoCooking() = 0;
};

class Parent : public Commensal, Chef
{
public:
    Parent()
    {
    }
    ~Parent()
    {
    }
    void DoCooking()
    {
        cout << "Parent Cooking" << endl;
    }
    void EatFood()
    {
        cout << "Parent Eating" << endl;
    }
    virtual void Raise() = 0;
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
    void DoCooking() // override de los metodos de Parent
    {
        cout << "Parent " << name << " Cooking" << endl;
    }
    void EatFood() // override de los metodos de Parent
    {
        cout << "Parent " << name << " Eating" << endl;
    }
    void Raise()
    {
        cout << "Father " << name << " " << lastname << " Raising" << endl;
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
    void DoCooking() // override de los metodos de Parent
    {
        cout << "Parent " << name << " Cooking" << endl;
    }
    void EatFood() // override de los metodos de Parent
    {
        cout << "Parent " << name << " Eating" << endl;
    }
    void Raise()
    {
        cout << "Mother " << name << " " << lastname << " Raising" << endl;
    }
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
    void EatFood()
    {
        cout << "Child " << name << " " << lastname << " Eating" << endl;
    }
};

int main()
{
    Father father("Guillermo", "Guerstein");
    Mother mother("Silvia", "Rodriguez");
    Child child("Tadeo", "Guerstein");

    father.DoCooking();
    father.Raise();
    mother.DoCooking();
    mother.Raise();
    child.EatFood();

    return 0;
}