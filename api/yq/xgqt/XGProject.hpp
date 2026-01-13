////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vkqt/app/YTachyon.hpp>

namespace yq::tachyon {
    class XGProject : public YTachyon {
        YQ_TACHYON_DECLARE(XGProject, YTachyon)
        Q_OBJECT
    public:
    
        XGProject();
        ~XGProject();
        
        static void init_meta();
    };
}
