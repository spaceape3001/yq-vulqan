////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/api/Action.hpp>
#include <yt/api/ActionInfoWriter.hpp>

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

    void Action::init_info()
    {
        auto w = writer<Action>();
        w.description("Tachyon Action (Abstract Base Class)");
    }
}
