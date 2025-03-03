////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yv/ViSurface.hpp>
#include <yv/VulqanManager.hpp>

namespace yq::tachyon {
    ViSurface::ViSurface(VkSurfaceKHR khr) : m_surface(khr)
    {
    }
    
    ViSurface::~ViSurface()
    {
        kill();
    }

    void    ViSurface::kill()
    {
        if(!m_surface)
            return ;
        vkDestroySurfaceKHR(VulqanManager::instance(), m_surface, nullptr);
    }

    bool    ViSurface::valid() const
    {
        return static_cast<bool>(m_surface);
    }
}
