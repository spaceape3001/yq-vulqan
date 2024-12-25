////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PostTrigger.hpp"
#include <yq/tachyon/api/TriggerInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PostTrigger)

namespace yq::tachyon {
    PostTrigger::PostTrigger(const PostInfo& post, const Param& p) : Trigger(p), m_info(post)
    {
    }
    
    PostTrigger::~PostTrigger()
    {
    }
    
    Trigger::Result PostTrigger::match(const Post& pp) const
    {
        return pp.metaInfo().is_this(m_info);
    }

    void PostTrigger::init_info()
    {
        auto w = writer<PostTrigger>();
        w.description("Post Trigger (ie, detects if the post is same/derived-from the specified class)");
    }
}
