////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Source rescaled in 2-Dimensions
    class Scale²DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Scale²DEvent, SpatialEvent)
    public:
        Scale²DEvent(const Header&, const Vector2D&);
    
        const Vector2D&   scale() const  { return m_scale; }
        
        static void init_meta();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Scale²DEvent(const Header&);
        Scale²DEvent(const Scale²DEvent&, const Header&);
        ~Scale²DEvent();

    private:
        Vector2D    m_scale = ZERO;
        
        Scale²DEvent(const Scale²DEvent&) = delete;
        Scale²DEvent(Scale²DEvent&&) = delete;
        Scale²DEvent& operator=(const Scale²DEvent&) = delete;
        Scale²DEvent& operator=(Scale²DEvent&&) = delete;
    };
}
