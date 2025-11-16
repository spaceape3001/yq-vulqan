////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaWindow.hpp"
#include "LuaConsole.hpp"
#include "LuaInputBar.hpp"
#include <yq/lua/logging.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/shape/AxBox2.hxx>


using namespace yq::tachyon;

namespace yq::lua {

    class LuaWindow::Console : public LuaConsole {
        YQ_OBJECT_DECLARE(Console, LuaConsole);
    public:
        Console(UIFlags flags={}) : LuaConsole(flags) {}
        Console(const Console& cp) : LuaConsole(cp) {}
        virtual ~Console(){}
        Console* clone() const override { return new Console(*this); }
        
        static void init_meta(){}
    };

    class LuaWindow::Input : public LuaInputBar {
        YQ_OBJECT_DECLARE(Input, LuaInputBar);
    public:
    
        Input(UIFlags flags={}) : LuaInputBar(flags|UIFlag::IsChild) {}
        Input(const Input& cp) : LuaInputBar(cp) {}
        virtual ~Input(){}
        Input* clone() const override { return new Input(*this); }
        
        static void init_meta(){}
        //   triggered override
    };
    

    LuaWindow::LuaWindow(std::string_view kLabel, tachyon::UIFlags flags) : UIWindow(kLabel, flags | UIFlag::NoScrollBar )
    {
        append(m_console = new Console);
        append(m_input = new Input);
    }
    
    LuaWindow::LuaWindow(const LuaWindow&cp) : UIWindow(cp)
    {
        for(UIElement* u : m_items){
            if(Console*p = dynamic_cast<Console*>(u))
                m_console   = p;
            if(Input* p = dynamic_cast<Input*>(u))
                m_input = p;
        }
    }
    
    LuaWindow::~LuaWindow()
    {
    }
    
    LuaWindow* LuaWindow::clone() const 
    {
        return new LuaWindow(*this);
    }
    
    void LuaWindow::content()  
    {
        const ImGuiStyle&   style   = ImGui::GetStyle();
        AxBox2F box = viewport(CONTENT);       
        m_console -> render();
        m_input -> render();
        Size2F      sz  = m_console->size();
        sz.x        = box.width();
        if(sz.y > 0.){
            float dy    = box.height() - ImGui::GetCursorPos().y - style.FramePadding.y;
            sz.y += dy;
        } else
            sz.y  = box.height();
            
        m_console->size(SET, sz);
    }

    void LuaWindow::debug(std::string_view v)
    {
        if(v.empty())
            return;
        if(!m_console)
            return;
        m_console->debug(v);
    }

    void    LuaWindow::info(std::string_view v)
    {
        if(v.empty())
            return;
        if(!m_console)
            return;
        m_console->info(v);
    }   

    void LuaWindow::tvm(set_k, tachyon::TypedID tid)
    {
        m_input -> tvm(SET, tid);
    }

    void LuaWindow::submit(const LuaExecuteReply&rep)
    {
        m_console->submit(rep);
    }
    
    void LuaWindow::init_meta()
    {
        auto w = writer<LuaWindow>();
        w.description("Lua Window");
    }
}


YQ_OBJECT_IMPLEMENT(yq::lua::LuaWindow)
YQ_OBJECT_IMPLEMENT(yq::lua::LuaWindow::Console)
YQ_OBJECT_IMPLEMENT(yq::lua::LuaWindow::Input)
