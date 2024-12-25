////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NandTrigger.hpp"
#include <yq/container/initlist_utils.hpp>
#include <yq/tachyon/api/TriggerInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::NandTrigger)

namespace yq::tachyon {
    NandTrigger::NandTrigger(std::span<const TriggerCPtr> triggers, const Param&p) : Trigger(p)
    {
        for(TriggerCPtr tp : triggers){
            if(!tp) 
                continue;
            m_triggers.push_back(tp);
        }
    }
    
    NandTrigger::NandTrigger(std::initializer_list<TriggerCPtr>triggers, const Param& p) : 
        NandTrigger(span(triggers), p)
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
            if(!f->triggered(pp))
                return true;
        }
        return false;
    }
    
    void NandTrigger::init_info()
    {
        auto w = writer<NandTrigger>();
        w.description("An OR post trigger based on other triggers");
    }
}
