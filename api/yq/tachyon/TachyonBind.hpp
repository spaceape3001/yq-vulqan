////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    class Tachyon;

    //! Utiltity to bind a viewer to the whatever...
    class TachyonBind {
    public:
        Tachyon* tachyon() const { return m_tachyon; }
        
    protected:
        TachyonBind(Tachyon* v) : m_tachyon(v) {}
        virtual ~TachyonBind(){}
        Tachyon* const   m_tachyon;
    };
}
