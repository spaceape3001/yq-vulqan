////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Action.hpp>
#include <tachyon/api/ActionInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Action)

namespace yq::tachyon {
    ActionInfo::ActionInfo(std::string_view zName, DelegateInfo& base, const std::source_location& sl) :
        DelegateInfo(zName, base, sl)
    {
        //set(Flag::TRIGGER);
    }
    
    ActionInfo::~ActionInfo(){}

    Action::Action()
    {
    }
    
    Action::Action(const Action& cp)
    {
    }

    Action::~Action()
    {
    }

    Action* Action::copy() const
    {
        return clone();
    }
        
    Action* Action::clone() const
    {
        return nullptr;
    }

    void Action::init_info()
    {
        auto w = writer<Action>();
        w.description("Tachyon Action (Abstract Base Class)");
    }
}
