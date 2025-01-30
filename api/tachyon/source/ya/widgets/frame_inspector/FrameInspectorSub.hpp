////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/widgets/FrameInspector.hpp>

namespace yq::tachyon {
    class FrameInspector::Sub {
    public:
        void    set_frame(const Frame*f)
        {
            m_frame = f;
        };
        
    protected:
        const Frame* m_frame = nullptr;
    };

}
