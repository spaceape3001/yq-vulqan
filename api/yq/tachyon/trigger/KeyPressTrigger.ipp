////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/trigger/KeyPressTrigger.hpp>
#include <yq/tachyon/api/TriggerMetaWriter.hpp>
#include <yq/tachyon/event/keyboard/KeyPressEvent.hpp>

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
    
    const PostMeta&     KeyPressTrigger::post_info() const 
    {
        return meta<KeyPressEvent>();
    }
        
    void KeyPressTrigger::init_meta()
    {
        auto w = writer<KeyPressTrigger>();
        w.description("Triggers on a key press");
    }
}
