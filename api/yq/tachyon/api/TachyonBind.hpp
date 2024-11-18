////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>


namespace yq::tachyon {

    //! Utiltity to bind a tachyon to the whatever...
    class TachyonBind {
    public:
        TachyonID tachyon() const { return m_tachyon; }
        
    protected:
        TachyonBind(TachyonID v) : m_tachyon(v) {}
        TachyonBind(const Tachyon*);
        virtual ~TachyonBind(){}
        TachyonID const   m_tachyon;
    };
}
