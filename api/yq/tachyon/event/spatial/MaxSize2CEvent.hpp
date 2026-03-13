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
    class MaxSize²CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize²CEvent, SpatialEvent)
    public:
        MaxSize²CEvent(const Header&, const Size2CM&);
    
        const Size2CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize²CEvent(const MaxSize²CEvent&, const Header&);
        MaxSize²CEvent(const Header&);
        ~MaxSize²CEvent();

    private:
        Size2CM  m_size = ZERO;
        
        MaxSize²CEvent(const MaxSize²CEvent&) = delete;
        MaxSize²CEvent(MaxSize²CEvent&&) = delete;
        MaxSize²CEvent& operator=(const MaxSize²CEvent&) = delete;
        MaxSize²CEvent& operator=(MaxSize²CEvent&&) = delete;
    };
}
