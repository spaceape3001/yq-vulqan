////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElementsWriter.hpp>
#include <tachyon/ui/UICallback.hxx>
#include <tachyon/ui/UIGenerator.hxx>

namespace yq::tachyon {
    template <SomeWidget W>
    UIElementWriter         UIElementsWriter::callback(void (W::*function)())
    {
        if(!function)
            return {};
        return make<UICallback_Widget<W>>(function);
    }

    template <SomeUIElement U, SomeWidget W>
    UIElementWriter         UIElementsWriter::generate(std::function<U*(W&)>&&fn)
    {
        if(!fn)
            return {};
        return make<UIGenerateByWidgetRef<U,W>>(std::move(fn));
    }
}
