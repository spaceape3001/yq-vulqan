////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElementWriter.hpp"
#include <tachyon/action/StdCallbackAction.hpp>
#include <tachyon/action/StdPostAction.hpp>
#include <tachyon/msg/Post.hpp>
#include <yt/api/Tachyon.hpp>

namespace yq::tachyon {
    
    template <SomePost P>
    UIElementWriter        UIElementWriter::action(post_k<P>)
    {
        action(new StdPostAction<P>());
        return *this;
    }
    
    template <SomeTachyon T>
    UIElementWriter        UIElementWriter::action(void (T::* fn)())
    {
        action(new StdCallbackAction<T>(fn));
        return *this;
    }
}
