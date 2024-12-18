////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/application.hpp>
#include <yq/tachyon/joystick.hpp>
#include <iostream>

using std::cout;
using namespace yq;
using namespace yq::tachyon;


int main(int argc, char* argv[])
{
    AppCreateInfo aci;
    aci.vulkan      = false;
    Application   app(argc, argv, aci);
    
    std::vector<Joystick> joysticks   = Joystick::joysticks();
    
    std::cout << "Found " << joysticks.size() << " joystick(s)\n\n";
    
    for(Joystick j : joysticks){
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
