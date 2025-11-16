////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Widget.hpp>

namespace yq::tachyon {
    class ViewerScreenshotReply;
}

namespace yq::lua {
    class LuaExecuteReply;
    //class LuaConsoleUI;
    //class LuaInputBar;
    class LuaWindow;
};

using namespace yq;
//using namespace yq::lua;
using namespace yq::tachyon;

class LuaWin : public Widget {
    YQ_TACHYON_DECLARE(LuaWin, Widget)
public:

    enum class FileMode {
        None,
        Script
    };
    
    
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
    void    on_lua_execute_reply(const yq::lua::LuaExecuteReply&);
    void    on_viewer_screenshot_reply(const tachyon::ViewerScreenshotReply&);

    FileMode                    m_fileMode = FileMode::None;
    yq::tachyon::TypedID        m_tvm;
    lua::LuaWindow*             m_window    = nullptr;
    //lua::LuaConsoleUI*          m_console   = nullptr;
    //lua::LuaInputBar*           m_input     = nullptr;
};
