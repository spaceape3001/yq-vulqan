////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Scene3.hpp>

namespace yq::tachyon {
    class SimpleScene³ : public Scene³ {
        YQ_TACHYON_DECLARE(SimpleScene³, Scene³)
    public:
    
        SimpleScene³();
        ~SimpleScene³();
        static void init_info();
        
    protected:
        void    snap(Scene³Snap&) const;
    };
}
