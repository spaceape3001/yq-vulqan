////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIWindow.hpp>

namespace yq::tachyon {
    class UIDockWriter;
    class UIDock : public UIWindow {
        YQ_OBJECT_DECLARE(UIDock, UIWindow)
    public:
        using Writer = UIDockWriter;
        
        UIDock(std::string_view, UIFlags flags={});
        UIDock(const UIDock&);
        
        UIDock* clone() const override;
        
        static void init_info();
    };
}
