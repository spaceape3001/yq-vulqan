////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>
#include <cstdint>

namespace yq { 
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Tachyon;
    class TachyonInfo;
    using TachyonPtr    = Ref<Tachyon>;
    using TachyonCPtr   = Ref<const Tachyon>;

    template <class E>
    concept SomeTachyon = std::derived_from<E,Tachyon>;

    template <class> class ID;
    
    using TachyonID = ID<Tachyon>;

    //! Utiltity to bind a tachyon to the whatever...
    class TachyonBind {
    public:
        Tachyon* tachyon() const { return m_tachyon; }
        
    protected:
        TachyonBind(Tachyon* v) : m_tachyon(v) {}
        virtual ~TachyonBind(){}
        Tachyon* const   m_tachyon;
    };
}
