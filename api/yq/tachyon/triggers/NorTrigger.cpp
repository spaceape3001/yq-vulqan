////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NorTrigger.hpp"
#include <yq/container/initlist_utils.hpp>
#include <yq/tachyon/api/TriggerInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::NorTrigger)

namespace yq::tachyon {
    NorTrigger::NorTrigger(std::span<const TriggerCPtr> triggers, const Param&p) : Trigger(p)
    {
        for(TriggerCPtr tp : triggers){
            if(!tp) 
                continue;
            m_triggers.push_back(tp);
        }
    }
    
    NorTrigger::NorTrigger(std::initializer_list<TriggerCPtr>triggers, const Param& p) : 
        NorTrigger(span(triggers), p)
    {
    }

    NorTrigger::~NorTrigger()
    {
    }

    Trigger::Result    NorTrigger::match(const Post& pp) const 
    {
        for(const TriggerCPtr& f : m_triggers){
            if(f->triggered(pp))
                return false;
        }
        return true;
    }
    
    void NorTrigger::init_info()
    {
        auto w = writer<NorTrigger>();
        w.description("An NOR post trigger based on other triggers");
    }
}
