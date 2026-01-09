////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/input/UIInputBar.hpp>
#include <yq/tachyon/ui/UIWindowWriter.hpp>

namespace yq::tachyon {
    class UIInputBarWriter : public UIWindowWriter {
    public:
        UIInputBarWriter();
        UIInputBarWriter(UIInputBar*);
        UIInputBarWriter(const UIInputBarWriter&);
        ~UIInputBarWriter();
        
        UIInputBar* element();
        
        UIInputBarWriter   capacity(size_t);
        UIInputBarWriter   label(std::string_view);
    };
}
