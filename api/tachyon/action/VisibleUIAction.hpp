////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Action.hpp>
#include <variant>

namespace yq::tachyon {

    /*! \brief Action that'll toggle/set a UI element's visibility
    
        *IF* the action payload contains a positional argument, it'll
        SET the element.  If not, it'll toggle.
    */
    class VisibleUIAction : public Action {
        YQ_OBJECT_DECLARE(VisibleUIAction, Action)
    public:
    
        using spec_t    = std::variant<std::monostate, uint64_t, std::string>;
        
        VisibleUIAction(spec_t);
        ~VisibleUIAction();
        
        virtual bool  action(Payload&) const override;
        
        static void init_info();
    
    private:
        spec_t          m_spec;
        
        enum class A {
            None = 0,
            Show,
            Hide,
            Toggle,
            Invalid
        };
        
        
        bool        act(A) const;
        
    };
}
