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
    NorTrigger::NorTrigger(std::vector<TriggerCPtr>&& triggers, const Param&p) : 
        Trigger(p), m_triggers(std::move(triggers))
    {
    }

    NorTrigger::~NorTrigger()
    {
    }

    Trigger::Result    NorTrigger::match(const Post& pp) const 
    {
        for(const TriggerCPtr& f : m_triggers){
            if(f && f->triggered(pp))
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
