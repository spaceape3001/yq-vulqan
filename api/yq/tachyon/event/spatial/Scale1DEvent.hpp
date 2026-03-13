////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Source rescaled in 1-Dimension
    class Scale¹DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Scale¹DEvent, SpatialEvent)
    public:
        Scale¹DEvent(const Header&, const Vector1D&);
    
        const Vector1D&   scale() const  { return m_scale; }
        
        static void init_meta();
        
        double  x() const { return m_scale.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Scale¹DEvent(const Header&);
        Scale¹DEvent(const Scale¹DEvent&, const Header&);
        ~Scale¹DEvent();

    private:
        Vector1D    m_scale = ZERO;
        
        Scale¹DEvent(const Scale¹DEvent&) = delete;
        Scale¹DEvent(Scale¹DEvent&&) = delete;
        Scale¹DEvent& operator=(const Scale¹DEvent&) = delete;
        Scale¹DEvent& operator=(Scale¹DEvent&&) = delete;
    };
}
