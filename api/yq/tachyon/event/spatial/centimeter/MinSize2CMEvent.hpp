////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Source resized in 2-Dimensions
    class MinSize²CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize²CMEvent, SpatialEvent)
    public:
        MinSize²CMEvent(const Header&, const Size2CM&);
    
        const Size2CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize²CMEvent(const MinSize²CMEvent&, const Header&);
        MinSize²CMEvent(const Header&);
        ~MinSize²CMEvent();

    private:
        Size2CM  m_size = ZERO;
        
        MinSize²CMEvent(const MinSize²CMEvent&) = delete;
        MinSize²CMEvent(MinSize²CMEvent&&) = delete;
        MinSize²CMEvent& operator=(const MinSize²CMEvent&) = delete;
        MinSize²CMEvent& operator=(MinSize²CMEvent&&) = delete;
    };
}
