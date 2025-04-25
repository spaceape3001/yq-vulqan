////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Source rescaled in 2-Dimensions
    class Scale²Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Scale²Event, SpatialEvent)
    public:
        Scale²Event(const Header&, const Vector2D&);
    
        const Vector2D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Scale²Event(const Header&);
        Scale²Event(const Scale²Event&, const Header&);
        ~Scale²Event();

    private:
        Vector2D    m_scale = ZERO;
        
        Scale²Event(const Scale²Event&) = delete;
        Scale²Event(Scale²Event&&) = delete;
        Scale²Event& operator=(const Scale²Event&) = delete;
        Scale²Event& operator=(Scale²Event&&) = delete;
    };
}
