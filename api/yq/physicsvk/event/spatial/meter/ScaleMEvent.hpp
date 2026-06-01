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
    class ScaleMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(ScaleMEvent, SpatialEvent)
    public:
        ScaleMEvent(const Header&, const Meter&);
    
        const Meter&   scale() const  { return m_scale; }
        
        static void init_meta();
        
        Meter  x() const { return m_scale; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ScaleMEvent(const Header&);
        ScaleMEvent(const ScaleMEvent&, const Header&);
        ~ScaleMEvent();

    private:
        Meter    m_scale = ONE;
        
        ScaleMEvent(const ScaleMEvent&) = delete;
        ScaleMEvent(ScaleMEvent&&) = delete;
        ScaleMEvent& operator=(const ScaleMEvent&) = delete;
        ScaleMEvent& operator=(ScaleMEvent&&) = delete;
    };
}
