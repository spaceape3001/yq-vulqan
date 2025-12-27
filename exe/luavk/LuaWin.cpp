////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaPanel.hpp"
#include "LuaWin.hpp"

//#include <yq/assetvk/ui/UIPanel.hpp>
#include <yq/date/dateutils.hpp>
#include <yq/lua/logging.hpp>
#include <yq/luavk/command/LuaExecuteFileCommand.hpp>
#include <yq/luavk/gesture/LuaExecuteFileGesture.hpp>
#include <yq/luavk/reply/LuaExecuteReply.hpp>
#include <yq/luavk/request/LuaExecuteFileRequest.hpp>
#include <yq/luavk/request/LuaExecuteStringRequest.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/Payload.hpp>
#include <yq/tachyon/api/WidgetMetaWriter.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/reply/viewer/ViewerScreenshotReply.hpp>
#include <yq/tachyon/request/viewer/ViewerScreenshotRequest.hpp>
#include <yq/tachyon/ui/UIPanelWriter.hpp>
#include <yq/tachyon/ui/UIWriters.hxx>
#include <yq/tachyon/ui/layout/UIVBoxLayout.hpp>
#include <yq/text/format.hpp>
#include <yq/text/transform.hpp>
#include <ImGuiFileDialog.h>

using namespace yq;
//using namespace yq::lua;
using namespace yq::tachyon;

YQ_TACHYON_IMPLEMENT(LuaWin)

LuaWin::LuaWin(TypedID luavm) : m_tvm(luavm)
{
    m_flags |= F::Gesture;
}

LuaWin::~LuaWin()
{
}

void    LuaWin::_debug(std::string_view v)
{
    if(m_window && !v.empty())
        m_window -> debug(v);
}

void    LuaWin::imgui(ViContext&u) 
{
    Widget::imgui(UI,u);
    Widget::imgui(u);
}

void LuaWin::cmd_lua_file()
{
    gesture(new LuaExecuteFileGesture(*this));
}


void    LuaWin::cmd_screenshot()
{
    ViewerID        viewID  = viewer();
    TypedID         view(viewID.id, Type::Viewer);
    send(new ViewerScreenshotRequest({.target=view}));
}


void    LuaWin::on_lua_exec_file_command(const LuaExecuteFileCommand& cmd)
{
    if(cmd.target() != id())
        return ;
   send(new LuaExecuteFileRequest({.target=m_tvm}, cmd.file()));
}

void    LuaWin::on_lua_execute_reply(const LuaExecuteReply&rep)
{
    if(!m_window) [[unlikely]]
        return;
    m_window->submit(rep);
}


void    LuaWin::on_viewer_screenshot_reply(const ViewerScreenshotReply& rep)
{
    std::string     filename    = std::format("screenshot-{}.png", iso8601basic_now());
    if(rep.raster())
        rep.raster() -> save_to(filename);
}

Execution   LuaWin::setup(const Context&u)
{
    Execution   ex  = Widget::setup(u);
    if(is_error(ex))
        return ex;
    if(!m_window){
        m_window   = dynamic_cast<LuaWindowUI*>(element(FIRST, "lua"));
        if(!m_window)
            return WAIT;
        m_window->tvm(SET, m_tvm);
        m_window->info("Welcome to the Lua ImGui Interpreter (of the Your Quill project)");
    }
    
    return {};
}


////////////////////////////////////

void LuaWin::init_meta()
{
    auto w = writer<LuaWin>();
    w.description("Lua Window");
    w.slot(&LuaWin::on_lua_exec_file_command);
    w.slot(&LuaWin::on_lua_execute_reply);
    w.slot(&LuaWin::on_viewer_screenshot_reply);
    
    auto app        = w.imgui(UI, APP);
    
    auto mmb        = app.menubar(MAIN);
    mmb.uid("mmb");
    
    auto file       = mmb.menu("Lua");
    file.menuitem("Run...").action(&LuaWin::cmd_lua_file);
    file.menuitem("Screenshot", "F12").action(&LuaWin::cmd_screenshot);
    
    //auto lay        = app.make<UIVBoxLayout>();
    
    auto lualua    = app.make<LuaPanel>("Lua");
    //console.bumper(BOTTOM, 30.);
    lualua.uid("lua");

    //auto input      = lay.make<lua::LuaInputBar>("##Input", UIFlag::NoDecoration);
    //input.height(40);
    //input.action(&LuaWin::cmd_user_input);
    //input.uid("input");

}
