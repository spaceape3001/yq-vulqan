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
#include <tachyon/widget/Stacked.hpp>
#include <math/units.hpp>
#include <math/vector/Vector3.hpp>
#include <math/vector/Quaternion3.hpp>

#include <iostream>

using namespace yq;
using namespace yq::tachyon;


struct Entity : public Task {

    enum class Type {
        Unknown,
        Asteroid,
        Crystal,
        Missile,
        Homing,
        Particle,
        Enemy,
        Fighter
    };

    using Position      = Vector3<unit::Meter>;
    using Velocity      = Vector3<unit::MeterPerSecond>;
    using Acceleration  = Vector3<unit::MeterPerSecond²>;
    using Orientation   = Quaternion3D;
    using AngularSpin   = Vector3<unit::RadianPerSecond>;
    using AngularAcc    = Vector3<unit::RadianPerSecond²>;
    using Force         = Vector3<unit::Newton>;

    Position        position            = {};
    Velocity        velocity            = {};
    Acceleration    acceleration        = {};
    Orientation     orientation         = Orientation(IDENTITY);
    AngularSpin     spin                = {};
    AngularAcc      angularAcc          = {};
    unit::Meter     radius              = { 1. };
    unit::Kilogram  mass                = { 1. };

        // thrust is local....
    Force           thrust              = {};
    Force           braking             = {};

    Type            type                = Type::Unknown;

    bool            homing              = 0;
    double          health              = 0;


    EC  tick(TaskAPI&api) override
    {
        //  do update....
        
        
        return true;
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
    
    ~TopBar() = default;
};

class LeftBar : public Widget {
    YQ_OBJECT_DECLARE(LeftBar, Widget)
public:

    LeftBar()
    {
    }
    
    ~LeftBar() = default;
};

class RightBar : public Widget {
    YQ_OBJECT_DECLARE(RightBar, Widget)
public:
    RightBar()
    {
    }
    
    ~RightBar() = default;
};

class BottomBar : public Widget {
    YQ_OBJECT_DECLARE(BottomBar, Widget)
public:
    BottomBar()
    {
    }
    
    ~BottomBar() = default;
};


class MenuPane : public Widget {
    YQ_OBJECT_DECLARE(MenuPane, Widget)
public:
    MenuPane()
    {
    }
    
    ~MenuPane() = default;
};

class PlayPane : public Widget {
    YQ_OBJECT_DECLARE(PlayPane, Widget)
public:
    PlayPane()
    {
    }
    
    ~PlayPane() = default;
};


class MainWin : public Stacked {
    YQ_OBJECT_DECLARE(MainWin, Stacked)
public:

    MainWin()
    {
        add_child(new PlayPane);
        add_child(new MenuPane);
    }
    
    void        do_menu()
    {
        set_active(1);
    }
    
    ~MainWin() = default;
};


YQ_OBJECT_IMPLEMENT(TopBar)
YQ_OBJECT_IMPLEMENT(RightBar)
YQ_OBJECT_IMPLEMENT(LeftBar)
YQ_OBJECT_IMPLEMENT(BottomBar)
YQ_OBJECT_IMPLEMENT(MainWin)
YQ_OBJECT_IMPLEMENT(MenuPane)
YQ_OBJECT_IMPLEMENT(PlayPane)

int main(int argc, char* argv[])
{
    AppCreateInfo        vi;
    Application app(argc, argv, vi);
    
        // do any init infos....
        
    app.finalize();
    
    MainWin*        mw  = new MainWin;
    mw -> do_menu();

    ViewerCreateInfo      wi;
    wi.title        = "Asteroids";
    wi.resizable    = false;
    wi.size         = { 1920, 1080 };
    wi.clear        = { 0.0f, 0.0f, 0.0f, 1.f };
    wi.imgui        = false;

    Ref<Viewer>     win = new Viewer(wi, mw);
    app.run(win.ptr());
    return 0;
}
