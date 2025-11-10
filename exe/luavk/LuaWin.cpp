////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaWin.hpp"

#include <yq/lua/logging.hpp>
#include <yq/luavk/command/ExecuteFileCommand.hpp>
#include <yq/luavk/command/ExecuteStringCommand.hpp>
#include <yq/luavk/event/ExecuteFileEvent.hpp>
#include <yq/luavk/event/ExecuteStringEvent.hpp>
#include <yq/luavk/ui/LuaConsoleUI.hpp>
#include <yq/luavk/ui/LuaConsoleUIWriter.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/Payload.hpp>
#include <yq/tachyon/api/WidgetMetaWriter.hpp>
#include <yq/tachyon/ui/UIInputBar.hpp>
#include <yq/tachyon/ui/UILineInput.hpp>
#include <yq/tachyon/ui/UIWriters.hxx>
#include <yq/tachyon/ui/layout/UIVBoxLayout.hpp>
#include <yq/text/format.hpp>
#include <yq/text/transform.hpp>
#include <ImGuiFileDialog.h>

using namespace yq;
//using namespace yq::lua;
using namespace yq::tachyon;

YQ_TACHYON_IMPLEMENT(LuaWin)

LuaWin::LuaWin(TachyonID luavm) : m_lua(luavm)
{
}

LuaWin::~LuaWin()
{
}

void    LuaWin::_debug(std::string_view v)
{
    if(m_console && !v.empty())
        m_console -> debug(v);
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
                    send(new yq::lua::ExecuteFileCommand({}, filePathName));
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

    send(new yq::lua::ExecuteStringCommand({}, l));
}

void    LuaWin::on_execute_file(const yq::lua::ExecuteFileEvent&evt)
{
    if(!m_console) [[unlikely]]
        return;
    m_console->submit(evt);
}

void    LuaWin::on_execute_string(const yq::lua::ExecuteStringEvent&evt)
{
    if(!m_console) [[unlikely]]
        return;
    m_console->submit(evt);
}


Execution   LuaWin::setup(const Context&u)
{
    Execution   ex  = Widget::setup(u);
    if(is_error(ex))
        return ex;
    if(!m_console){
        m_console   = dynamic_cast<lua::LuaConsoleUI*>(element(FIRST, "console"));
        if(!m_console)
            return WAIT;
            
        m_console->info("Welcome to the Lua ImGui Interpreter (of the Your Quill project)");
    }
    
    if(!m_input)
        m_input     = dynamic_cast<UIInputBar*>(element(FIRST, "input"));
    
    return {};
}


////////////////////////////////////

void LuaWin::init_meta()
{
    auto w = writer<LuaWin>();
    w.description("Lua Window");
    w.slot(&LuaWin::on_execute_file);
    w.slot(&LuaWin::on_execute_string);
    
    auto app        = w.imgui(UI, APP);
    
    auto mmb        = app.menubar(MAIN);
    mmb.uid("mmb");
    
    auto file       = mmb.menu("Lua");
    file.menuitem("Run...").action(&LuaWin::cmd_lua_file);
    
    auto lay        = app.make<UIVBoxLayout>();
    
    auto console    = lay.make<lua::LuaConsoleUI>("Console");
    //console.bumper(BOTTOM, 30.);
    console.uid("console");

    auto input      = lay.make<UIInputBar>("##Input", UIFlag::NoDecoration);
    input.height(40);
    input.action(&LuaWin::cmd_user_input);
    input.uid("input");

}
