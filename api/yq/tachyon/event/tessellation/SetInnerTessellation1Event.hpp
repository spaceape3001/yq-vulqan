////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/TessellationEvent.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetInnerTessellation¹Event : public TessellationEvent {
        YQ_OBJECT_DECLARE(SetInnerTessellation¹Event, TessellationEvent)
    public:
        SetInnerTessellation¹Event(const Header&, const Vector1D&);
    
        const Vector1D&   inner_tessellation() const  { return m_innerTessellation; }
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetInnerTessellation¹Event(const SetInnerTessellation¹Event&, const Header&);
        ~SetInnerTessellation¹Event();

    private:
        Vector1D   m_innerTessellation;
        
        SetInnerTessellation¹Event(const SetInnerTessellation¹Event&) = delete;
        SetInnerTessellation¹Event(SetInnerTessellation¹Event&&) = delete;
        SetInnerTessellation¹Event& operator=(const SetInnerTessellation¹Event&) = delete;
        SetInnerTessellation¹Event& operator=(SetInnerTessellation¹Event&&) = delete;
    };
}
