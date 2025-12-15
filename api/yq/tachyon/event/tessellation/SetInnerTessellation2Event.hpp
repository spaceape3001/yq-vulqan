////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/TessellationEvent.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetInnerTessellation²Event : public TessellationEvent {
        YQ_OBJECT_DECLARE(SetInnerTessellation²Event, TessellationEvent)
    public:
        SetInnerTessellation²Event(const Header&, const Vector2D&);
    
        const Vector2D&   inner_tessellation() const  { return m_innerTessellation; }
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetInnerTessellation²Event();
        SetInnerTessellation²Event(const SetInnerTessellation²Event&, const Header&);
        
    private:
        Vector2D   m_innerTessellation;
        SetInnerTessellation²Event(const SetInnerTessellation²Event&) = delete;
        SetInnerTessellation²Event(SetInnerTessellation²Event&&) = delete;
        SetInnerTessellation²Event& operator=(const SetInnerTessellation²Event&) = delete;
        SetInnerTessellation²Event& operator=(SetInnerTessellation²Event&&) = delete;
    };
}
