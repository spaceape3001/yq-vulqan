////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/ui/UITabbed.hpp>
#include <yq/tachyon/ui/UIPanelWriter.hpp>

namespace yq::tachyon {
    class UITabbed;
    class UITabbedWriter : public UIPanelWriter {
    public:
        UITabbedWriter();
        UITabbedWriter(UITabbed*);
        UITabbedWriter(const UITabbedWriter&);
        ~UITabbedWriter();
        
        UITabbed* element();
    };
}
