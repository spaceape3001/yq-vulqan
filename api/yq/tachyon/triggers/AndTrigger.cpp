////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AndTrigger.hpp"
#include <yq/container/initlist_utils.hpp>
#include <yq/tachyon/api/TriggerInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AndTrigger)

namespace yq::tachyon {
    AndTrigger::AndTrigger(std::vector<TriggerCPtr>&& triggers, const Param&p) : 
        Trigger(p), m_triggers(std::move(triggers))
    {
    }
    
    AndTrigger::~AndTrigger()
    {
    }

    Trigger::Result    AndTrigger::match(const Post& pp) const 
    {
        if(m_triggers.empty())
            return false;
        for(const TriggerCPtr& f : m_triggers){
            if(f && !f->triggered(pp))
                return false;
        }
        return true;
    }
    
    void AndTrigger::init_info()
    {
        auto w = writer<AndTrigger>();
        w.description("An OR post trigger based on other triggers");
    }
}
