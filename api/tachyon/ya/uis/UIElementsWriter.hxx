////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElementsWriter.hpp>
#include <ya/uis/UICallback.hxx>

namespace yq::tachyon {
    template <SomeWidget W>
    UIElementWriter         UIElementsWriter::callback(void (W::*function)())
    {
        if(!function)
            return {};
        return make<UICallback_Widget<W>>(function);
    }
}
