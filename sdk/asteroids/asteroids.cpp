////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/Application.hpp>
#include <tachyon/Viewer.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/ui/Widget.hpp>
#include <tachyon/task/Task.hpp>

#include <iostream>

using namespace yq;
using namespace yq::tachyon;


class Asteroid : public Task {

    Asteroid()
    {
    }
    
    ~Asteroid()
    {
    }
    
    EC  tick(API&) override
    {
    }
};

class Crystal : public Task {

    Crystal()
    {
    }
    
    ~Crystal()
    {
    }
    
    EC  tick(API&) override
    {
    }
};

class Fighter : public Task {

    Fighter()
    {
    }
    
    ~Fighter()
    {
    }
    
    EC  tick(API&) override
    {
    }
};

class Enemy : public Task {
public:
    Enemy()
    {
    }
};

class Player : public Object {
    YQ_OBJECT_DECLARE(Player, Object)
public:
    Player()
    {
    }
    
    ~Player()
    {
    }
    
};



class TopBar : public Widget {
    YQ_OBJECT_DECLARE(TopBar, Widget)
public:

    TopBar()
    {
    }
};

class LeftBar : public Widget {
    YQ_OBJECT_DECLARE(LeftBar, Widget)
public:

    LeftBar()
    {
    }
    
    ~LeftBar()
    {
    }
};

class RightBar : public Widget {
    YQ_OBJECT_DECLARE(RightBar, Widget)
public:
    RightBar()
    {
    }
    
    ~RightBar()
    {
    }
};

class BottomBar : public Widget {
    YQ_OBJECT_DECLARE(BottomBar, Widget)
public:
    BottomBar()
    {
    }
    
    ~BottomBar()
    {
    }
};


class MainWin : public Widget {
    YQ_OBJECT_DECLARE(MainWin, Widget)
public:

    MainWin()
    {
    }
    
    ~MainWin()
    {
    }
};


YQ_OBJECT_IMPLEMENT(TopBar)
YQ_OBJECT_IMPLEMENT(RightBar)
YQ_OBJECT_IMPLEMENT(LeftBar)
YQ_OBJECT_IMPLEMENT(BottomBar)
YQ_OBJECT_IMPLEMENT(MainWin)

int main(int argc, char* argv[])
{
    std::cout << "Good Bye World!\n";
    return 0;
}
