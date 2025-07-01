////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/trigger/OrTrigger.hpp>
#include <yq/container/initlist_utils.hpp>
#include <tachyon/api/TriggerMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::OrTrigger)

namespace yq::tachyon {
    OrTrigger::OrTrigger(std::span<const TriggerCPtr> triggers, const Param&p) : 
        Trigger(p), m_triggers(triggers.begin(), triggers.end())
    {
    }

    OrTrigger::OrTrigger(std::initializer_list<TriggerCPtr> triggers, const Param&p) : 
        Trigger(p), m_triggers(triggers.begin(), triggers.end())
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
    
    void OrTrigger::init_meta()
    {
        auto w = writer<OrTrigger>();
        w.description("An OR post trigger based on other triggers");
    }
}
