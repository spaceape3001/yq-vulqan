////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/TessellationEvent.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetOuterTessellation⁴Event : public TessellationEvent {
        YQ_OBJECT_DECLARE(SetOuterTessellation⁴Event, TessellationEvent)
    public:
        SetOuterTessellation⁴Event(const Header&, const Vector4D&);
    
        const Vector4D&   outer_tessellation() const  { return m_outerTessellation; }
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetOuterTessellation⁴Event();
        SetOuterTessellation⁴Event(const SetOuterTessellation⁴Event&, const Header&);
    
    private:
        Vector4D  m_outerTessellation;
        
        SetOuterTessellation⁴Event(const SetOuterTessellation⁴Event&) = delete;
        SetOuterTessellation⁴Event(SetOuterTessellation⁴Event&&) = delete;
        SetOuterTessellation⁴Event& operator=(const SetOuterTessellation⁴Event&) = delete;
        SetOuterTessellation⁴Event& operator=(SetOuterTessellation⁴Event&&) = delete;
    };
}
