////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>

namespace yq::tachyon {
    class Tachyon;
    

    //! The proxy is a *buffer* to an interface
    class Proxy {
    public:
    
        Tachyon*    object() const { return m_tachyon; }
        uint64_t    revision() const { return m_revision; }
    
    protected:
        Proxy(Tachyon*, uint64_t);
        ~Proxy();

        template <Pred pred>
        void        dispatch(pred);
    
    private:
        Tachyon*        m_tachyon;
        uint64_t        m_revision  = 0;
        unsigned        m_count     = 0;

        //! Checks & creates if different
        virtual Proxy*      reproxy() const = 0;
    };
}

