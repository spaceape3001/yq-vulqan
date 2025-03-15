////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Layout.hpp>
#include <vector>

namespace yq::tachyon {
    class BoxLayout : public Layout {
        YQ_OBJECT_DECLARE(BoxLayout, Layout)
    public:

        static void init_info();
        virtual void tick(const TickAPI&) override;
        std::span<const double> dividers() const { return m_dividers; }
    
    protected:
        BoxLayout();
        ~BoxLayout();
        
        std::vector<double>     m_dividers;
    };
}
