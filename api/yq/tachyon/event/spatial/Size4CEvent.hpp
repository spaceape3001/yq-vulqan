////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Source resized in 4-Dimensions
    class Size⁴CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size⁴CEvent, SpatialEvent)
    public:
        Size⁴CEvent(const Header&, const Size4CM&);
    
        const Size4CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }
        Centimeter  w() const { return m_size.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size⁴CEvent(const Header&);
        Size⁴CEvent(const Size⁴CEvent&, const Header&);
        ~Size⁴CEvent();

    private:
        Size4CM  m_size = ZERO;
        
        Size⁴CEvent(const Size⁴CEvent&) = delete;
        Size⁴CEvent(Size⁴CEvent&&) = delete;
        Size⁴CEvent& operator=(const Size⁴CEvent&) = delete;
        Size⁴CEvent& operator=(Size⁴CEvent&&) = delete;
    };
}
