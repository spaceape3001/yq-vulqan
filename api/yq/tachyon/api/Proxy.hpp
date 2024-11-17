////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>
#include <functional>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/typedef/proxy.hpp>

namespace yq::tachyon {
    class AppFrame;
    class Tachyon;
    class InterfaceInfo;
    
    //! The proxy is a *buffer* to an interface
    class Proxy {
    public:
    
        Tachyon*                object() const { return m_tachyon; }
        uint64_t                revision() const { return m_revision; }
        const InterfaceInfo*    interface(info_t) const { return m_interface; }
    
    protected:
        Proxy();
        virtual ~Proxy();

        void            dispatch(ProxyFN&&);
    
    private:
        friend class Tachyon;
        
        Tachyon*                m_tachyon   = nullptr;
        uint64_t                m_revision  = 0;
        const InterfaceInfo*    m_interface = nullptr;
    };
}

