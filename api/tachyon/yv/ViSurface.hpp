////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <tachyon/typedef/vi_surface.hpp>
#include <yv/vulqan.hpp>

namespace yq::tachyon {

    /*
        Considering the "surface" for a window/monitor in a full screen, multiple
        monitor situation
    */

    class ViSurface : public RefCount {
    public:
    
        ViSurface(VkSurfaceKHR);
        ~ViSurface();
        
        VkSurfaceKHR    surface() const { return m_surface; }
        bool            valid() const;
    
    private:
        void    kill();
        VkSurfaceKHR    m_surface;
    };

}
