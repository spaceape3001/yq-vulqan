////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Action.hpp>

namespace yq::tachyon {
    class PostAction : public Action {
        YQ_OBJECT_DECLARE(PostAction, Action)
    public:
        PostAction();
        PostAction(const PostAction&);
        ~PostAction();
        static void init_info();
    };
}
