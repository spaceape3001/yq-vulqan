////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {

    //! Source rescaled in 1-Dimension
    class ScaleCMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(ScaleCMEvent, SpatialEvent)
    public:
        ScaleCMEvent(const Header&, const Centimeter&);
    
        const Centimeter&   scale() const  { return m_scale; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_scale; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ScaleCMEvent(const Header&);
        ScaleCMEvent(const ScaleCMEvent&, const Header&);
        ~ScaleCMEvent();

    private:
        Centimeter    m_scale = ONE;
        
        ScaleCMEvent(const ScaleCMEvent&) = delete;
        ScaleCMEvent(ScaleCMEvent&&) = delete;
        ScaleCMEvent& operator=(const ScaleCMEvent&) = delete;
        ScaleCMEvent& operator=(ScaleCMEvent&&) = delete;
    };
}
