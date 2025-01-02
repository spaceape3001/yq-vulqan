////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Trigger.hpp>
#include <yq/tachyon/enum/ModifierKey.hpp>
#include <yq/tachyon/enum/KeyCode.hpp>

namespace yq::tachyon {
    class KeyPressTrigger : public Trigger {
        YQ_OBJECT_DECLARE(KeyPressTrigger, Trigger)
    public:
    
        KeyPressTrigger(KeyCode, ModifierKeys::Checker chk={}, const Param& p=Param());
        ~KeyPressTrigger();
        
        virtual const PostInfo&     post_info() const override;
        virtual Result              match(const Post&) const override;
        
        static void init_info();

    private:
        KeyCode                 m_key;
        ModifierKeys::Checker   m_modifiers;
        
    };
}
