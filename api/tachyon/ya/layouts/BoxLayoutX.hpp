////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/layouts/BoxLayout.hpp>

namespace yq::tachyon {
    class BoxLayoutˣ : public BoxLayout {
        YQ_OBJECT_DECLARE(BoxLayoutˣ, BoxLayout);
    public:
        
        static void init_info();
        
        BoxLayoutˣ();
        ~BoxLayoutˣ();
    };
};
