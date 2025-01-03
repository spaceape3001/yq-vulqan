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
    class NorTrigger : public Trigger {
        YQ_OBJECT_DECLARE(NorTrigger, Trigger)
    public:
    
        using Param = Trigger::Param;
    
        NorTrigger(std::span<const TriggerCPtr>, const Param& p = {});
        NorTrigger(std::initializer_list<TriggerCPtr>, const Param& p = {});
        // Add overloads as necessary
        
        //NorTrigger(std::vector<TriggerCPtr>&&);
        //NorTrigger(const std::vector<TriggerCPtr>&);
        //NorTrigger(const std::span<TriggerCPtr>);
        //

        ~NorTrigger();
        Result match(const Post&) const override;
    
        static void init_info();

    private:
        std::vector<TriggerCPtr> m_triggers;
    };
}
