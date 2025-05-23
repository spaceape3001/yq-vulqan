////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Delegate.hpp>
#include <tachyon/typedef/post.hpp>

namespace yq::tachyon {
    class Action;
    class Tachyon;
    class UIElement;
    class Payload;
    
    class ActionInfo : public DelegateInfo {
    public:
        template <typename> class Writer;
        template <typename> class Fixer;
        ActionInfo(std::string_view zName, DelegateInfo& base, const std::source_location& sl=std::source_location::current());
    
    protected:
        ~ActionInfo();
        
        // virtual CommandCPtr execute(const Action*, const PostCPtr&) const { return {}; }
    };

    class Action : public Delegate {
        YQ_OBJECT_INFO(ActionInfo)
        YQ_OBJECT_DECLARE(Action, Delegate)
    public:
    
        Action();
        Action(const Action&);
        ~Action();
        
        static void init_info();
        
        //! Our action (TRUE if successful)
        virtual bool  action(Payload&) const = 0;
        
        //! Not everything can be copied/cloned
        Action* copy() const;
        
    protected:
        virtual Action* clone() const;
    };
}
