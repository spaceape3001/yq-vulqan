////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaWindowUI.hpp"
#include "LuaConsoleUI.hpp"
#include "LuaInputBarUI.hpp"
#include <yq/lua/logging.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/shape/AxBox2.hxx>


namespace yq::tachyon {

    class LuaWindowUI::Console : public LuaConsoleUI {
        YQ_OBJECT_DECLARE(Console, LuaConsoleUI);
    public:
        Console(UIFlags flags={}) : LuaConsoleUI(flags) {}
        Console(const Console& cp) : LuaConsoleUI(cp) {}
        virtual ~Console(){}
        Console* clone() const override { return new Console(*this); }
        
        static void init_meta(){}
    };

    class LuaWindowUI::Input : public LuaInputBarUI {
        YQ_OBJECT_DECLARE(Input, LuaInputBarUI);
    public:
    
        Input(UIFlags flags={}) : LuaInputBarUI(flags|UIFlag::IsChild) {}
        Input(const Input& cp) : LuaInputBarUI(cp) {}
        virtual ~Input(){}
        Input* clone() const override { return new Input(*this); }
        
        static void init_meta(){}
        //   triggered override
    };
    

    LuaWindowUI::LuaWindowUI(std::string_view kLabel, UIFlags flags) : UIPanel(kLabel, flags | UIFlag::NoScrollBar )
    {
        append(m_console = new Console);
        append(m_input = new Input);
    }
    
    LuaWindowUI::LuaWindowUI(const LuaWindowUI&cp) : UIPanel(cp)
    {
        for(UIElement* u : m_items){
            if(Console*p = dynamic_cast<Console*>(u))
                m_console   = p;
            if(Input* p = dynamic_cast<Input*>(u))
                m_input = p;
        }
    }
    
    LuaWindowUI::~LuaWindowUI()
    {
    }
    
    LuaWindowUI* LuaWindowUI::clone() const 
    {
        return new LuaWindowUI(*this);
    }
    
    void LuaWindowUI::content()  
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

    void LuaWindowUI::debug(std::string_view v)
    {
        if(v.empty())
            return;
        if(!m_console)
            return;
        m_console->debug(v);
    }

    void    LuaWindowUI::info(std::string_view v)
    {
        if(v.empty())
            return;
        if(!m_console)
            return;
        m_console->info(v);
    }   

    void LuaWindowUI::tvm(set_k, TypedID tid)
    {
        m_input -> tvm(SET, tid);
    }

    void LuaWindowUI::submit(const LuaExecuteReply&rep)
    {
        m_console->submit(rep);
    }
    
    void LuaWindowUI::init_meta()
    {
        auto w = writer<LuaWindowUI>();
        w.description("Lua Window");
    }
}


YQ_OBJECT_IMPLEMENT(yq::tachyon::LuaWindowUI)
YQ_OBJECT_IMPLEMENT(yq::tachyon::LuaWindowUI::Console)
YQ_OBJECT_IMPLEMENT(yq::tachyon::LuaWindowUI::Input)
