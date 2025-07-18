////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Trigger.hpp>

namespace yq::tachyon {

    /*! \brief Inverts the acceptance
    
        Got a trigger you want the opposite of?  This is your helper.
        
        \note If this trigger is BAD (null), then this will return FALSE.
    */
    class NotTrigger : public Trigger {
        YQ_OBJECT_DECLARE(NotTrigger, Trigger)
    public:

        NotTrigger(TriggerCPtr&&, const Param& p = {});
        ~NotTrigger();

        Result              match(const Post&) const override;
        const PostMeta&     post_info() const override;
        
        static void init_meta();
    
    private:
        TriggerCPtr m_original;
    };
}
