////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Layout.hpp>

namespace yq::tachyon {
    class Layout¹Info : public LayoutInfo {
    public:
        template <typename> class Writer;
        Layout¹Info(std::string_view, LayoutInfo&, const std::source_location& sl = std::source_location::current());
    };
    
    class Layout¹ : public Layout {
        YQ_OBJECT_INFO(Layout¹Info)
        YQ_OBJECT_DECLARE(Layout¹, Layout)
    public:
    
        static void init_info();
        
    protected:
        Layout¹();
        ~Layout¹();
    };
    
}
