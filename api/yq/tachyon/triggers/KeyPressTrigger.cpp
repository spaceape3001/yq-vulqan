////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyPressTrigger.hpp"

#include <yq/tachyon/api/TriggerInfoWriter.hpp>
#include <yq/tachyon/events/KeyPressEvent.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyPressTrigger)

namespace yq::tachyon {
    KeyPressTrigger::KeyPressTrigger(KeyCode kc, ModifierKeys::Checker chk, const Param& p) : 
        Trigger(p), m_key(kc), m_modifiers(chk)
    {
    }
    
    KeyPressTrigger::~KeyPressTrigger()
    {
    }
        
    Trigger::Result    KeyPressTrigger::match(const Post& pp) const 
    {
        const KeyPressEvent*    evt = dynamic_cast<const KeyPressEvent*>(&pp);
        if(!evt)
            return MISMATCH;
        return (evt->key() == m_key) && m_modifiers(evt->modifiers());
    }
    
    const PostInfo&     KeyPressTrigger::post_info() const 
    {
        return meta<KeyPressEvent>();
    }
        
    void KeyPressTrigger::init_info()
    {
        auto w = writer<KeyPressTrigger>();
        w.description("Triggers on a key press");
    }
}