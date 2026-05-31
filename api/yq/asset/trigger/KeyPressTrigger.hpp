////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Trigger.hpp>
#include <yq/tachyon/os/ModifierKey.hpp>
#include <yq/tachyon/os/KeyCode.hpp>

namespace yq::tachyon {
    class KeyPressTrigger : public Trigger {
        YQ_OBJECT_DECLARE(KeyPressTrigger, Trigger)
    public:
    
        KeyPressTrigger(KeyCode, ModifierKeys::Checker chk={}, const Param& p=Param());
        ~KeyPressTrigger();
        
        virtual const PostMeta&     post_info() const override;
        virtual Result              match(const Post&) const override;
        
        static void init_meta();

    private:
        KeyCode                 m_key;
        ModifierKeys::Checker   m_modifiers;
        
    };
}
