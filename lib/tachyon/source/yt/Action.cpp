////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/Action.hpp>
#include <yt/ActionInfoWriter.hpp>

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
    
    Action::~Action()
    {
    }

    bool Action::configure(/* TBD */) 
    {
        return true;
    }

    void Action::init_info()
    {
        auto w = writer<Action>();
        w.description("Tachyon Action (Abstract Base Class)");
    }
}
