////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElementWriter.hpp"
#include <yq/tachyon/action/PayloadCallbackAction.hpp>
#include <yq/tachyon/action/StdCallbackAction.hpp>
#include <yq/tachyon/action/StdPostAction.hpp>
#include <yq/tachyon/api/Post.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

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

    template <SomeTachyon T>
    UIElementWriter        UIElementWriter::action(void (T::* fn)(const Payload&))
    {
        action(new PayloadCallbackAction<T>(fn));
        return *this;
    }
}
