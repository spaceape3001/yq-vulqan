////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Source moved in 4-Dimensions
    class Count⁴UEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Count⁴UEvent, SpatialEvent)
    public:
        Count⁴UEvent(const Header&, const Vector4U&);
    
        const Vector4U&   count() const  { return m_count; }
        
        static void init_meta();
        
        Vector1U  x() const { return m_count.x; }
        Vector1U  y() const { return m_count.y; }
        Vector1U  z() const { return m_count.z; }
        Vector1U  w() const { return m_count.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Count⁴UEvent(const Header&);
        Count⁴UEvent(const Count⁴UEvent&, const Header&);
        ~Count⁴UEvent();

    private:
        Vector4U  m_count = ZERO;
        
        Count⁴UEvent(const Count⁴UEvent&) = delete;
        Count⁴UEvent(Count⁴UEvent&&) = delete;
        Count⁴UEvent& operator=(const Count⁴UEvent&) = delete;
        Count⁴UEvent& operator=(Count⁴UEvent&&) = delete;
    };
}
