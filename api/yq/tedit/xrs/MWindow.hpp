////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/window.hpp>
#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MWindow : public MTachyon {
        YQ_TACHYON_DECLARE(MWindow, MTachyon)
        Q_OBJECT
    public:
    
        MWindow(TypedID);
        ~MWindow();
        
        WindowID     oid() const;
        
        static void init_meta();
    };
}
