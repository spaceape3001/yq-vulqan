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
    class Size²CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size²CMEvent, SpatialEvent)
    public:
        Size²CMEvent(const Header&, const Size2CM&);
    
        const Size2CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size²CMEvent(const Size²CMEvent&, const Header&);
        Size²CMEvent(const Header&);
        ~Size²CMEvent();

    private:
        Size2CM  m_size = ZERO;
        
        Size²CMEvent(const Size²CMEvent&) = delete;
        Size²CMEvent(Size²CMEvent&&) = delete;
        Size²CMEvent& operator=(const Size²CMEvent&) = delete;
        Size²CMEvent& operator=(Size²CMEvent&&) = delete;
    };
}
