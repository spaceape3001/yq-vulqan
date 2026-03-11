////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Source resized in 2-Dimensions
    class Size²DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size²DEvent, SpatialEvent)
    public:
        Size²DEvent(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size²DEvent(const Size²DEvent&, const Header&);
        Size²DEvent(const Header&);
        ~Size²DEvent();

    private:
        Size2D  m_size = ZERO;
        
        Size²DEvent(const Size²DEvent&) = delete;
        Size²DEvent(Size²DEvent&&) = delete;
        Size²DEvent& operator=(const Size²DEvent&) = delete;
        Size²DEvent& operator=(Size²DEvent&&) = delete;
    };
}
