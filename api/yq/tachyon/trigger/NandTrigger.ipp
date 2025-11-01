////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/trigger/NandTrigger.hpp>
#include <yq/container/initlist_utils.hpp>
#include <tachyon/api/TriggerMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::NandTrigger)

namespace yq::tachyon {
    NandTrigger::NandTrigger(std::span<const TriggerCPtr> triggers, const Param&p) : 
        Trigger(p), m_triggers(triggers.begin(), triggers.end())
    {
    }
    
    NandTrigger::NandTrigger(std::initializer_list<TriggerCPtr> triggers, const Param&p) : 
        Trigger(p), m_triggers(triggers.begin(), triggers.end())
    {
    }

    NandTrigger::~NandTrigger()
    {
    }

    Trigger::Result    NandTrigger::match(const Post& pp) const 
    {
        if(m_triggers.empty())
            return true;
        for(const TriggerCPtr& f : m_triggers){
            if(f && !f->triggered(pp))
                return true;
        }
        return false;
    }
    
    void NandTrigger::init_meta()
    {
        auto w = writer<NandTrigger>();
        w.description("An OR post trigger based on other triggers");
    }
}
