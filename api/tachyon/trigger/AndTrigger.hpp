////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Trigger.hpp>

namespace yq::tachyon {

    /*! \brief "OR" trigger of multiple triggers
    
        Takes in a list of triggers, and creates an "or" for them.  
        
        \note No valid triggers means this trigger will REJECT all queries.
    */
    class AndTrigger : public Trigger {
        YQ_OBJECT_DECLARE(AndTrigger, Trigger)
    public:
    
        using Param = Trigger::Param;
    
        AndTrigger(std::span<const TriggerCPtr>, const Param& p = {});
        AndTrigger(std::initializer_list<TriggerCPtr>, const Param& p = {});

        ~AndTrigger();
        Result match(const Post&) const override;
    
        static void init_info();

    private:
        std::vector<TriggerCPtr> m_triggers;
    };
}
