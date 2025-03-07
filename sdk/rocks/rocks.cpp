////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL -- ROCKS
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "RockApp.hpp"

int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    
    //aci.threads.sim     = true;
    //aci.threads.viewer  = PER;

    RockApp app(argc, argv, aci);
    if(!app.start()){
        app.stop();
        return -1;
    }
    app.run();
    return 0;
}
