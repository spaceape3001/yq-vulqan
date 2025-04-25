////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Action.hpp>

namespace yq::tachyon {
    class NullAction : public Action {
        YQ_OBJECT_DECLARE(NullAction, Action)
    public:
    
        NullAction();
        ~NullAction();

        virtual bool  action(Payload&) const override;
        
        static void init_info();
    };
}
