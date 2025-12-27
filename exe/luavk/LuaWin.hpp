////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Widget.hpp>

namespace yq::tachyon {
    class ViewerScreenshotReply;
    class LuaExecuteFileCommand;
    class LuaExecuteReply;
    //class LuaConsoleUI;
    //class LuaInputBar;
    class LuaWindowUI;
};

using namespace yq;
//using namespace yq::lua;
using namespace yq::tachyon;

class LuaWin : public Widget {
    YQ_TACHYON_DECLARE(LuaWin, Widget)
public:

    LuaWin(TypedID luavm);
    
    ~LuaWin();

    

    void    imgui(ViContext&u) ;
    
    static void init_meta();
    void    _debug(std::string_view);
    
    //void    cmd_user_input(const Payload&);
    void    cmd_lua_file();

    void    cmd_screenshot();

    virtual Execution   setup(const Context&) override;
    
private:

    void    on_lua_exec_file_command(const LuaExecuteFileCommand&);
    void    on_lua_execute_reply(const LuaExecuteReply&);
    void    on_viewer_screenshot_reply(const ViewerScreenshotReply&);

    TypedID         m_tvm;
    LuaWindowUI*    m_window    = nullptr;
    //lua::LuaConsoleUI*          m_console   = nullptr;
    //lua::LuaInputBar*           m_input     = nullptr;
};
