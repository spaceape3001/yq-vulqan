////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Widget.hpp>

namespace yq::tachyon {
    struct Payload;
    class UIConsole;
    class UIInputBar;
}

namespace yq::lua {
    class ExecuteFileEvent;
    class ExecuteStringEvent;
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
    
    
    LuaWin(TachyonID luavm);
    
    ~LuaWin();

    

    void    imgui(ViContext&u) ;
    
    static void init_meta();
    void    _debug(std::string_view);
    
    void    cmd_user_input(const Payload&);
    void    cmd_lua_file();

    virtual Execution   setup(const Context&) override;
    
private:
    void    on_execute_file(const yq::lua::ExecuteFileEvent&);
    void    on_execute_string(const yq::lua::ExecuteStringEvent&);

    FileMode                    m_fileMode = FileMode::None;
    yq::tachyon::TachyonID      m_lua;
    UIConsole*                  m_console   = nullptr;
    UIInputBar*                 m_input     = nullptr;
};
