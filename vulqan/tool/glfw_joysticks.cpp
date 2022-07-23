////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <basic/TextUtils.hpp>
#include <engine/Application.hpp>
#include <engine/vulqan/VqJoystick.hpp>
#include <iostream>

using std::cout;
using namespace yq;
using namespace yq::engine;


int main(int argc, char* argv[])
{
    Application   app(argc, argv);
    app.init_glfw();
    
    std::vector<VqJoystick> joysticks   = VqJoystick::joysticks();
    
    std::cout << "Found " << joysticks.size() << " joystick(s)\n\n";
    
    for(VqJoystick j : joysticks){
        std::cout << "Joystick #" << (int) j.id << " (" << j.name() << " or GUID=" << j.guid() << ")";
        if( j.is_gamepad())
            std::cout << " GAMEPAD!";
        std::cout  << "\n  axes: ";
        for( float f : j.axes())
            std::cout << " " << f;
        std::cout << "\n  buttons: ";
        for(unsigned char ch : j.buttons())
            std::cout << ' ' << (int) ch;
        std::cout << "\n  hats: ";
        for(unsigned char ch : j.hats())
            std::cout << ' ' << (int) ch;
        std::cout << '\n';
    }
    
    return 0;
}
