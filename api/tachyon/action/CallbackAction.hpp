////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Action.hpp>

namespace yq::tachyon {
    
    class TachyonMeta;

    /*! \brief Direct callback action on a tachyon
    
        \note This isn't always thread-safe, beware!
    */
    class CallbackAction : public Action {
        YQ_OBJECT_DECLARE(CallbackAction, Action)
    public:
        CallbackAction();
        CallbackAction(const CallbackAction&);
        ~CallbackAction();
        
        static void init_info();
    };
}
