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
    class OrTrigger : public Trigger {
        YQ_OBJECT_DECLARE(OrTrigger, Trigger)
    public:
    
        using Param = Trigger::Param;
    
        OrTrigger(std::span<const TriggerCPtr>, const Param& p = {});
        OrTrigger(std::initializer_list<TriggerCPtr>, const Param& p = {});
        // Add overloads as necessary
        
        //OrTrigger(std::vector<TriggerCPtr>&&);
        //OrTrigger(const std::vector<TriggerCPtr>&);
        //OrTrigger(const std::span<TriggerCPtr>);
        //

        ~OrTrigger();
        Result match(const Post&) const override;
    
        static void init_info();

    private:
        std::vector<TriggerCPtr> m_triggers;
    };
}
