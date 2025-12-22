////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <yq/meta/Meta.hpp>
#include <yq/tachyon/application.hpp>

//  Helpers....
ViewerCreateInfo        gVCI;

int lh_start(lua_State*l)
{
    // this will be evil... if there's a startup failure, we'll THROW through the lua calls
    // also, luatvm is switching active threads... (Going to have to pcall/yield)
}


int main(int argc, char* argv[])
{
    if(argc < 2){
        std::cout << "Usage: gamevk <lua>\n";
        return 0;
    }
    
    //  Will call the TVM until sys.start() is executed
    
    Meta::init();
    
}
