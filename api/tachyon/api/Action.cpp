////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Action.hpp>
#include <tachyon/api/ActionMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Action)

namespace yq::tachyon {
    ActionMeta::ActionMeta(std::string_view zName, DelegateMeta& base, const std::source_location& sl) :
        DelegateMeta(zName, base, sl)
    {
        //set(Flag::TRIGGER);
    }
    
    ActionMeta::~ActionMeta(){}

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
