////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Source resized in 2-Dimensions
    class Size²Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size²Event, SpatialEvent)
    public:
        Size²Event(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size²Event(const Size²Event&, const Header&);
        Size²Event(const Header&);
        ~Size²Event();

    private:
        Size2D  m_size = ZERO;
        
        Size²Event(const Size²Event&) = delete;
        Size²Event(Size²Event&&) = delete;
        Size²Event& operator=(const Size²Event&) = delete;
        Size²Event& operator=(Size²Event&&) = delete;
    };
}
