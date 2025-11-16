////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaPanel.hpp"
#include "LuaWin.hpp"

#include <yq/date/dateutils.hpp>
#include <yq/lua/logging.hpp>
#include <yq/luavk/request/LuaExecuteFileRequest.hpp>
#include <yq/luavk/request/LuaExecuteStringRequest.hpp>
#include <yq/luavk/reply/LuaExecuteReply.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/Payload.hpp>
#include <yq/tachyon/api/WidgetMetaWriter.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/reply/viewer/ViewerScreenshotReply.hpp>
#include <yq/tachyon/request/viewer/ViewerScreenshotRequest.hpp>
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

    if(m_fileMode != FileMode::None){
        ImVec2  minSize = { (float)(0.5 * width()), (float)(0.5 * height()) };
        if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey", ImGuiWindowFlags_NoCollapse, minSize)) {
            if (ImGuiFileDialog::Instance()->IsOk()) { // action if OK
                std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
                switch(m_fileMode){
                case FileMode::None:
                    break;
                case FileMode::Script:
                    send(new yq::lua::LuaExecuteFileRequest({.target=m_tvm}, filePathName));
                    break;
                }
            }
            m_fileMode      = FileMode::None;
            ImGuiFileDialog::Instance()->Close();
        }
    }
}

void LuaWin::cmd_lua_file()
{
    IGFD::FileDialogConfig config;
    config.path = ".";
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose Lua Script to Run", ".lua", config);        
    m_fileMode  = FileMode::Script;
}


void    LuaWin::cmd_screenshot()
{
    ViewerID        viewID  = viewer();
    TypedID         view(viewID.id, Type::Viewer);
    send(new ViewerScreenshotRequest({.target=view}));
}

#if 0
void LuaWin::cmd_user_input(const Payload& pay)
{
    if(pay.arguments().empty())
        return ;
    
    auto   line    = to_string(pay.arguments()[0]);
    if(!line)
        return ;
        
    auto l  = trimmed(*line);
    if(l.empty())
        return ;

    send(new yq::lua::LuaExecuteStringRequest({}, l));
}
#endif

void    LuaWin::on_lua_execute_reply(const yq::lua::LuaExecuteReply&rep)
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
        m_window   = dynamic_cast<lua::LuaWindow*>(element(FIRST, "lua"));
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
