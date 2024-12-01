////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Desktop.hpp>

namespace yq::tachyon {
    struct AppCreateInfo;

    class DesktopGLFW : public Desktop {
        YQ_TACHYON_DECLARE(DesktopGLFW, Desktop);
    public:
    
        DesktopGLFW(const AppCreateInfo&, const Param& p={});
        ~DesktopGLFW();
        
        virtual Execution tick(Context&) override;

        static void init_info();
        
    private:
        enum class Stage {
            Uninit      = 0,
            Running,
            Dead
        };
        
        Stage       m_stage = Stage::Uninit;
        
        static DesktopGLFW*     s_desktop;
    };
}
