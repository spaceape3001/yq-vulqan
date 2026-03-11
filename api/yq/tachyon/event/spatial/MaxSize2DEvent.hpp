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
    class MaxSize²DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize²DEvent, SpatialEvent)
    public:
        MaxSize²DEvent(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize²DEvent(const MaxSize²DEvent&, const Header&);
        MaxSize²DEvent(const Header&);
        ~MaxSize²DEvent();

    private:
        Size2D  m_size = ZERO;
        
        MaxSize²DEvent(const MaxSize²DEvent&) = delete;
        MaxSize²DEvent(MaxSize²DEvent&&) = delete;
        MaxSize²DEvent& operator=(const MaxSize²DEvent&) = delete;
        MaxSize²DEvent& operator=(MaxSize²DEvent&&) = delete;
    };
}
