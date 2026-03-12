////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Source resized in 1-Dimension
    class Size¹DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size¹DEvent, SpatialEvent)
    public:
        Size¹DEvent(const Header&, const Size1M&);
    
        const Size1M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size¹DEvent(const Header&);
        Size¹DEvent(const Size¹DEvent&, const Header&);
        ~Size¹DEvent();

    private:
        Size1M  m_size = ZERO;
        
        Size¹DEvent(const Size¹DEvent&) = delete;
        Size¹DEvent(Size¹DEvent&&) = delete;
        Size¹DEvent& operator=(const Size¹DEvent&) = delete;
        Size¹DEvent& operator=(Size¹DEvent&&) = delete;
    };
}
