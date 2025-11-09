////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElementsWriter.hpp>
#include <yq/tachyon/ui/UICallback.hxx>
#include <yq/tachyon/ui/UIGenerator.hxx>
#include <yq/tachyon/ui/UILineInput.hxx>
#include <yq/tachyon/ui/UILineInputWriter.hpp>

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

    template <SomeWidget W>
    UILineInputWriter       UIElementsWriter::line_input(std::string_view label, void (W::*fn)())
    {
        if(!fn)
            return {};
        return make<UILineInput_WidgetCallback<W>>(label, fn);
    }

    template <SomeWidget W>
    UILineInputWriter       UIElementsWriter::line_input(std::string_view, void (W::*fn)(std::string_view))
    {
        if(!fn)
            return {};
        return make<UILineInput_WidgetCallbackWithString<W>>(label, fn);
    }

    template <SomeWidget W>
    UILineInputWriter       UIElementsWriter::line_input(std::string_view, void (W::*fn)(const std::string&))
    {
        if(!fn)
            return {};
        return make<UILineInput_WidgetCallback<W>>(label, fn);
    }
}
