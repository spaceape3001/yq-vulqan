////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VisibleUIAction.hpp"
#include <yq/core/Any.hpp>
#include <yq/core/Result.hpp>
#include <yt/api/ActionInfoWriter.hpp>
#include <yt/ui/UIElement.hpp>
#include <yt/ui/Widget.hpp>
#include <yt/ui/Widget.hxx>
#include <yt/logging.hpp>

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
        if(pay.pargs.empty())
            return act(A::Toggle);
            
        A   a;
        
        a = pay.pargs[0].as<Tristate>([&](Tristate x){
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
            a   = pay.pargs[0].as<bool>([&](bool x){
                return x ? A::Show : A::Hide;
            });
        }
        
        if(a == A::None){
            a   = pay.pargs[0].as<int>([&](int x){
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
