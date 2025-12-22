////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <yq/lua/info/FunctionInfo.hpp>
#include <yq/lua/info/ModuleInfo.hpp>
#include <yq/luavk/LuaTVM.hpp>
#include <yq/meta/Meta.hpp>
#include <yq/tachyon/application.hpp>

#include <yq/lua/lualua.hxx>

using namespace yq;
using namespace yq::lua;
using namespace yq::tachyon;

bool    gStart  = false;
bool    gRun    = false;

//  Will want debugging support ... separate viewer/widget?  Embedded?  A supreme GameWidget?  (Likely default)

int lh_start(lua_State*l)
{
    gStart  = true;
    return 0;
}

int lh_run(lua_State*l)
{
    gStart  = true;
    gRun    = true;
    return 0;
}

void reg_lua()
{
    using namespace yq::lua;
    if(ModuleInfo* mi = reg(MODULE, "sys")){
        if(FunctionInfo* fi = mi->add("start", lh_start)){
            fi -> brief("Starts the system");
        }
        if(FunctionInfo* fi = mi->add("run", lh_run)){
            fi -> brief("Runs the system (call AFTER start)");
        }
    }
}

/*
    Game design...
        
        GameWidget dominates
        
        "screen" will be the different widgets... main menu, settings, etc
    
*/

struct LuaScript {
    std::string         data;
    std::string_view    init;
    std::string_view    start;
    std::string_view    run;
};

int main(int argc, char* argv[])
{
    if(argc < 2){
        std::cout << R"VOGON(Usage: gamevk <lua>\n"
        
This runs the gamevk engine.  It's a lua script with the following caveats

-- Do configuration stuff

START

-- Do setup

RUN

-- Anything at runtime (can be nothing too)

)VOGON";
        return 0;
    }
    
    
    AppCreateInfo   aci;
    Application app(argc, argv, aci);
    Meta::init();
    reg_lua();


    
    Ref<LuaTVM>     tvm = new LuaTVM;
    

    // Actual start is moved here...
    // this will be evil... if there's a startup failure, we'll THROW through the lua calls
    // also, luatvm is switching active threads... (Going to have to pcall/yield)
    
    //  Will call the TVM until sys.start() is executed
    
    
}
