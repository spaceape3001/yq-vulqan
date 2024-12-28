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
    NandTrigger::NandTrigger(std::vector<TriggerCPtr>&& triggers, const Param&p) : 
        Trigger(p), m_triggers(std::move(triggers))
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
    
    void NandTrigger::init_info()
    {
        auto w = writer<NandTrigger>();
        w.description("An OR post trigger based on other triggers");
    }
}
