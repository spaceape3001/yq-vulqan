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
    class Size⁴CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size⁴CMEvent, SpatialEvent)
    public:
        Size⁴CMEvent(const Header&, const Size4CM&);
    
        const Size4CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }
        Centimeter  w() const { return m_size.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size⁴CMEvent(const Header&);
        Size⁴CMEvent(const Size⁴CMEvent&, const Header&);
        ~Size⁴CMEvent();

    private:
        Size4CM  m_size = ZERO;
        
        Size⁴CMEvent(const Size⁴CMEvent&) = delete;
        Size⁴CMEvent(Size⁴CMEvent&&) = delete;
        Size⁴CMEvent& operator=(const Size⁴CMEvent&) = delete;
        Size⁴CMEvent& operator=(Size⁴CMEvent&&) = delete;
    };
}
