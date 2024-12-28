////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "OrTrigger.hpp"
#include <yq/container/initlist_utils.hpp>
#include <yq/tachyon/api/TriggerInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::OrTrigger)

namespace yq::tachyon {
    OrTrigger::OrTrigger(std::vector<TriggerCPtr>&& triggers, const Param&p) : 
        Trigger(p), m_triggers(std::move(triggers))
    {
    }

    OrTrigger::~OrTrigger()
    {
    }

    Trigger::Result    OrTrigger::match(const Post& pp) const 
    {
        for(const TriggerCPtr& f : m_triggers){
            if(f && f->triggered(pp))
                return true;
        }
        return false;
    }
    
    void OrTrigger::init_info()
    {
        auto w = writer<OrTrigger>();
        w.description("An OR post trigger based on other triggers");
    }
}
