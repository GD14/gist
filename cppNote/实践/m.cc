#include <bits/stdc++.h>
using namespace std;

class shape {
public:
    virtual void draw()
    {
        cout << "shape!" << endl;
    }
    virtual void color()
    {
        cout << "shape:color!" << endl;
    }
};

class circle : public shape {
public:
    void draw()
    {
        cout << "circle!" << endl;
    }

private:
    int radio;
};

class newCircle : public circle {
public:
    void draw()
    {
        cout << "new circle" << endl;
    }

private:
    int x;
};
class treeCicle : public newCircle {
public:
    void draw()
    {
        cout << "treecircle" << endl;
    }
};

int main(int argc, char* argv[])
{
    shape s;
    circle c;

    shape* ps = &c;
    newCircle nc;
    treeCicle tc;
    
    ps->draw();
    return 0;
}