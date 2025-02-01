////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/tachyon.hpp>


namespace yq::tachyon {
    struct TypedID;

    //! Utiltity to bind a tachyon to the whatever...
    class TachyonBind {
    public:
        TachyonID tachyon() const { return m_tachyon; }
        
    protected:
        constexpr TachyonBind(TachyonID v) noexcept : m_tachyon(v) {}
        TachyonBind(const Tachyon*);
        TachyonBind(TypedID);
        virtual ~TachyonBind(){}
        TachyonID const   m_tachyon;
    };
}
