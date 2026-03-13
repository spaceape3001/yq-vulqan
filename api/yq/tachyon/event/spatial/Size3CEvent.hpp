////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Source resized in 3-Dimensions
    class Size³CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size³CEvent, SpatialEvent)
    public:
        Size³CEvent(const Header&, const Size3CM&);
    
        const Size3CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size³CEvent(const Header&);
        Size³CEvent(const Size³CEvent&, const Header&);
        ~Size³CEvent();

    private:
        Size3CM  m_size = ZERO;
        
        Size³CEvent(const Size³CEvent&) = delete;
        Size³CEvent(Size³CEvent&&) = delete;
        Size³CEvent& operator=(const Size³CEvent&) = delete;
        Size³CEvent& operator=(Size³CEvent&&) = delete;
    };
}
