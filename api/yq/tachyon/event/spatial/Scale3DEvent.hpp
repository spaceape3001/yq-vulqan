////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Source rescaled in 3-Dimensions
    class Scale³DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Scale³DEvent, SpatialEvent)
    public:
        Scale³DEvent(const Header&, const Vector3D&);
    
        const Vector3D&   scale() const  { return m_scale; }
        
        static void init_meta();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        double  z() const { return m_scale.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Scale³DEvent(const Header&);
        Scale³DEvent(const Scale³DEvent&, const Header&);
        ~Scale³DEvent();

    private:
        Vector3D  m_scale   = ZERO;
        
        Scale³DEvent(const Scale³DEvent&) = delete;
        Scale³DEvent(Scale³DEvent&&) = delete;
        Scale³DEvent& operator=(const Scale³DEvent&) = delete;
        Scale³DEvent& operator=(Scale³DEvent&&) = delete;
    };
}
