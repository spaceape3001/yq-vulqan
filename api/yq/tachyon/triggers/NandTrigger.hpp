////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Trigger.hpp>

namespace yq::tachyon {

    /*! \brief "OR" trigger of multiple triggers
    
        Takes in a list of triggers, and creates an "or" for them.  
        
        \note No valid triggers means this trigger will REJECT all queries.
    */
    class NandTrigger : public Trigger {
        YQ_OBJECT_DECLARE(NandTrigger, Trigger)
    public:
    
        using Param = Trigger::Param;
    
        NandTrigger(std::vector<TriggerCPtr>&&, const Param& p = {});
 
        ~NandTrigger();
        Result match(const Post&) const override;
    
        static void init_info();

    private:
        std::vector<TriggerCPtr> m_triggers;
    };
}
