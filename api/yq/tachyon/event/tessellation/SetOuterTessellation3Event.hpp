////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/TessellationEvent.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetOuterTessellation³Event : public TessellationEvent {
        YQ_OBJECT_DECLARE(SetOuterTessellation³Event, TessellationEvent)
    public:
        SetOuterTessellation³Event(const Header&, const Vector3D&);
    
        const Vector3D&   outer_tessellation() const  { return m_outerTessellation; }
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetOuterTessellation³Event();
        SetOuterTessellation³Event(const SetOuterTessellation³Event&, const Header&);
    
    private:
        Vector3D  m_outerTessellation;
        
        SetOuterTessellation³Event(const SetOuterTessellation³Event&) = delete;
        SetOuterTessellation³Event(SetOuterTessellation³Event&&) = delete;
        SetOuterTessellation³Event& operator=(const SetOuterTessellation³Event&) = delete;
        SetOuterTessellation³Event& operator=(SetOuterTessellation³Event&&) = delete;
    };
}
