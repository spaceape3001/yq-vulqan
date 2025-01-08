////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/SpatialEvent.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Source rescaled in 1-Dimension
    class Scale¹Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Scale¹Event, SpatialEvent)
    public:
        Scale¹Event(const Header&, const Vector1D&);
    
        const Vector1D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Scale¹Event(const Scale¹Event&, const Header&);
        ~Scale¹Event();

    private:
        Vector1D const  m_scale;
        
        Scale¹Event(const Scale¹Event&) = delete;
        Scale¹Event(Scale¹Event&&) = delete;
        Scale¹Event& operator=(const Scale¹Event&) = delete;
        Scale¹Event& operator=(Scale¹Event&&) = delete;
    };
}
