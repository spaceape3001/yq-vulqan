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
    class MinSize²CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize²CEvent, SpatialEvent)
    public:
        MinSize²CEvent(const Header&, const Size2CM&);
    
        const Size2CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize²CEvent(const MinSize²CEvent&, const Header&);
        MinSize²CEvent(const Header&);
        ~MinSize²CEvent();

    private:
        Size2CM  m_size = ZERO;
        
        MinSize²CEvent(const MinSize²CEvent&) = delete;
        MinSize²CEvent(MinSize²CEvent&&) = delete;
        MinSize²CEvent& operator=(const MinSize²CEvent&) = delete;
        MinSize²CEvent& operator=(MinSize²CEvent&&) = delete;
    };
}
