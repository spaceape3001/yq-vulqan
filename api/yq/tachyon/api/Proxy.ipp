////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Proxy.hpp"
#include "Tachyon.hpp"

namespace yq::tachyon {
    Proxy::Proxy(Tachyon*t) : m_tachyon(t), m_revision(t->revision())
    {
    }
    
    Proxy::~Proxy()
    {
    }

    void    Proxy::dispatch(std::function<void()>&& fn)
    {
        //  Do the delayed command here...
    }
}
