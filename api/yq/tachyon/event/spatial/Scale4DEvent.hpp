////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Source rescaled in 3-Dimensions
    class Scale⁴DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Scale⁴DEvent, SpatialEvent)
    public:
        Scale⁴DEvent(const Header&, const Vector4D&);
    
        const Vector4D&   scale() const  { return m_scale; }
        
        static void init_meta();
        
        double  w() const { return m_scale.w; }
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        double  z() const { return m_scale.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Scale⁴DEvent(const Header&);
        Scale⁴DEvent(const Scale⁴DEvent&, const Header&);
        ~Scale⁴DEvent();

    private:
        Vector4D  m_scale   = ZERO;
        
        Scale⁴DEvent(const Scale⁴DEvent&) = delete;
        Scale⁴DEvent(Scale⁴DEvent&&) = delete;
        Scale⁴DEvent& operator=(const Scale⁴DEvent&) = delete;
        Scale⁴DEvent& operator=(Scale⁴DEvent&&) = delete;
    };
}
