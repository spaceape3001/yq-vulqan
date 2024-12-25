////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Trigger.hpp>
#include <yq/tachyon/api/Post.hpp>

namespace yq::tachyon {

    /*! \brief Trigger for post matching the given meta data
    */
    class PostTrigger : public Trigger {
        YQ_OBJECT_DECLARE(PostTrigger, Trigger)
    public:
    
        using Param = Trigger::Param;
    
        PostTrigger(const PostInfo& post, const Param& p = {});

        ~PostTrigger();
        Result match(const Post&) const override;
        virtual const PostInfo&     post_info() const { return m_info; }

        static void init_info();

        template <SomePost P>
        class By;

    private:
        const PostInfo&     m_info;
    };
    
    template <SomePost P>
    class PostTrigger::By : public PostTrigger {
    public:
        By(const Param& p = {}) : PostTrigger(meta<P>(), p) {}
        virtual ~By(){}
    };
}
