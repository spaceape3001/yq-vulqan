////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Source resized in 4-Dimensions
    class Size⁴DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size⁴DEvent, SpatialEvent)
    public:
        Size⁴DEvent(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size⁴DEvent(const Header&);
        Size⁴DEvent(const Size⁴DEvent&, const Header&);
        ~Size⁴DEvent();

    private:
        Size4D  m_size = ZERO;
        
        Size⁴DEvent(const Size⁴DEvent&) = delete;
        Size⁴DEvent(Size⁴DEvent&&) = delete;
        Size⁴DEvent& operator=(const Size⁴DEvent&) = delete;
        Size⁴DEvent& operator=(Size⁴DEvent&&) = delete;
    };
}
