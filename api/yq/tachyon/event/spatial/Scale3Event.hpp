////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Source rescaled in 3-Dimensions
    class Scale³Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Scale³Event, SpatialEvent)
    public:
        Scale³Event(const Header&, const Vector3D&);
    
        const Vector3D&   scale() const  { return m_scale; }
        
        static void init_meta();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        double  z() const { return m_scale.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Scale³Event(const Header&);
        Scale³Event(const Scale³Event&, const Header&);
        ~Scale³Event();

    private:
        Vector3D  m_scale   = ZERO;
        
        Scale³Event(const Scale³Event&) = delete;
        Scale³Event(Scale³Event&&) = delete;
        Scale³Event& operator=(const Scale³Event&) = delete;
        Scale³Event& operator=(Scale³Event&&) = delete;
    };
}
