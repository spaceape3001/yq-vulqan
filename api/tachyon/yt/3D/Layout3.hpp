////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Layout.hpp>

namespace yq::tachyon {
    class Layout³Info : public LayoutInfo {
    public:
        template <typename> class Writer;
        Layout³Info(std::string_view, LayoutInfo&, const std::source_location& sl = std::source_location::current());
    };
    
    class Layout³ : public Layout {
        YQ_OBJECT_INFO(Layout³Info)
        YQ_OBJECT_DECLARE(Layout³, Layout)
    public:
    
        static void init_info();
        
    protected:
        Layout³();
        ~Layout³();
    };
    
}
