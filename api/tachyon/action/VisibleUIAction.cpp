////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VisibleUIAction.hpp"
#include <yq/core/Any.hpp>
#include <yq/core/Result.hpp>
#include <tachyon/api/ActionInfoWriter.hpp>
#include <tachyon/api/Payload.hpp>
#include <tachyon/api/UIElement.hpp>
#include <tachyon/api/Widget.hpp>
#include <tachyon/api/Widget.hxx>
#include <tachyon/logging.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::VisibleUIAction)

namespace yq::tachyon {
    VisibleUIAction::VisibleUIAction(spec_t sp) : m_spec(sp)
    {
    }
    
    VisibleUIAction::~VisibleUIAction()
    {
    }

    bool  VisibleUIAction::act(A a) const
    {
        Widget*w    = UIElement::widget();
        if(!w)
            return false;
        
        bool    ret = false;
        auto actor = [&](UIElement& ui) {
            switch(a){
            case A::Show:
                ret = true;
                ui.flag(CLEAR, UIFlag::Invisible);
                break;
            case A::Hide:
                ret = true;
                ui.flag(SET, UIFlag::Invisible);
                break;
            case A::Toggle:
                ret = true;
                ui.flag(TOGGLE, UIFlag::Invisible);
                break;
            default: 
                break;
            }
        };
        
        if(auto p = std::get_if<uint64_t>(&m_spec)){
            w->for_elements(*p, actor);
        } else if(auto p = std::get_if<std::string>(&m_spec)){
            w->for_elements(*p, actor);
        }

        return ret;
    }
        
    bool  VisibleUIAction::action(Payload&pay) const 
    {
        if(!pay.argument(HAS, 0))
            return act(A::Toggle);
            
        A   a;
        
        const Any&  arg = pay.argument(0);
        a = arg.as<Tristate>([&](Tristate x){
            switch(x){
            case Tristate::YES:
                return A::Show;
            case Tristate::NO:
                return A::Hide;
            case Tristate::MAYBE:
                return A::Toggle;
            default:
                return A::Invalid;
            }
        });
        
        if(a == A::None){
            a   = arg.as<bool>([&](bool x){
                return x ? A::Show : A::Hide;
            });
        }
        
        if(a == A::None){
            a   = arg.as<int>([&](int x){
                return x ? A::Show : A::Hide;
            });
        }
        
        if((a != A::None) && (a != A::Invalid))
            return act(a);
        return false;
    }
    
    void VisibleUIAction::init_info()
    {
        auto w = writer<VisibleUIAction>();
        w.description("Visible UI Action");
    }
}
