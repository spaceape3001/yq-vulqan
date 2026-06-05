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
    class MaxSize²CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize²CMEvent, SpatialEvent)
    public:
        MaxSize²CMEvent(const Header&, const Size2CM&);
    
        const Size2CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize²CMEvent(const MaxSize²CMEvent&, const Header&);
        MaxSize²CMEvent(const Header&);
        ~MaxSize²CMEvent();

    private:
        Size2CM  m_size = ZERO;
        
        MaxSize²CMEvent(const MaxSize²CMEvent&) = delete;
        MaxSize²CMEvent(MaxSize²CMEvent&&) = delete;
        MaxSize²CMEvent& operator=(const MaxSize²CMEvent&) = delete;
        MaxSize²CMEvent& operator=(MaxSize²CMEvent&&) = delete;
    };
}
