////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Layout.hpp>

namespace yq::tachyon {
    class BoxLayout : public Layout {
        YQ_OBJECT_DECLARE(BoxLayout, Layout)
    public:

        static void init_info();
        virtual void tick(const TickAPI&) override;
    
    protected:
        BoxLayout();
        ~BoxLayout();
    };
}
