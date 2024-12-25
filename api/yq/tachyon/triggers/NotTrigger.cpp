////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NotTrigger.hpp"
#include <yq/tachyon/api/Post.hpp>
#include <yq/tachyon/api/TriggerInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::NotTrigger)

namespace yq::tachyon {

    NotTrigger::NotTrigger(const TriggerCPtr& inc, const Param& p) : Trigger(p), m_original(inc)
    {
        assert(m_original);
    }
    
    NotTrigger::~NotTrigger()
    {
    }
    
    Trigger::Result    NotTrigger::match(const Post&pp) const 
    {
        if(!m_original)   // shouldn't happen, demo...
            return false;
        return m_original -> triggered(pp);
    }

    const PostInfo&     NotTrigger::post_info() const 
    {
        if(!m_original)
            return meta<Post>();
        return m_original->post_info();
    }

    void NotTrigger::init_info()
    {
        auto w = writer<NotTrigger>();
        w.description("NOT post trigger (ie, negates the given trigger's test)");
    }
}
