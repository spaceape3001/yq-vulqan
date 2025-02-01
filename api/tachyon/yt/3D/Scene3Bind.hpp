////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/scene3.hpp>

namespace yq::tachyon {
    class Scene³;
    struct TypedID;

    //! Utiltity to bind a viewer to the whatever...
    class Scene³Bind {
    public:
        Scene³ID    scene³() const { return m_scene³; }
        
    protected:
        Scene³Bind(Scene³ID v) : m_scene³(v) {}
        Scene³Bind(const Scene³*);
        Scene³Bind(TypedID);
        virtual ~Scene³Bind() {}
        
        Scene³ID const m_scene³;
    };
}
