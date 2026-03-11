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
    class MinSize¹DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize¹DEvent, SpatialEvent)
    public:
        MinSize¹DEvent(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize¹DEvent(const Header&);
        MinSize¹DEvent(const MinSize¹DEvent&, const Header&);
        ~MinSize¹DEvent();

    private:
        Size1D  m_size = ZERO;
        
        MinSize¹DEvent(const MinSize¹DEvent&) = delete;
        MinSize¹DEvent(MinSize¹DEvent&&) = delete;
        MinSize¹DEvent& operator=(const MinSize¹DEvent&) = delete;
        MinSize¹DEvent& operator=(MinSize¹DEvent&&) = delete;
    };
}
