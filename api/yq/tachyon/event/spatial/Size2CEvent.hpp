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
    class Size²CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size²CEvent, SpatialEvent)
    public:
        Size²CEvent(const Header&, const Size2CM&);
    
        const Size2CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size²CEvent(const Size²CEvent&, const Header&);
        Size²CEvent(const Header&);
        ~Size²CEvent();

    private:
        Size2CM  m_size = ZERO;
        
        Size²CEvent(const Size²CEvent&) = delete;
        Size²CEvent(Size²CEvent&&) = delete;
        Size²CEvent& operator=(const Size²CEvent&) = delete;
        Size²CEvent& operator=(Size²CEvent&&) = delete;
    };
}
