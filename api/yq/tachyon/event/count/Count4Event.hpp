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
    class Count⁴Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Count⁴Event, SpatialEvent)
    public:
        Count⁴Event(const Header&, const Vector4U&);
    
        const Vector4U&   count() const  { return m_count; }
        
        static void init_meta();
        
        Vector1U  x() const { return m_count.x; }
        Vector1U  y() const { return m_count.y; }
        Vector1U  z() const { return m_count.z; }
        Vector1U  w() const { return m_count.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Count⁴Event(const Header&);
        Count⁴Event(const Count⁴Event&, const Header&);
        ~Count⁴Event();

    private:
        Vector4U  m_count = ZERO;
        
        Count⁴Event(const Count⁴Event&) = delete;
        Count⁴Event(Count⁴Event&&) = delete;
        Count⁴Event& operator=(const Count⁴Event&) = delete;
        Count⁴Event& operator=(Count⁴Event&&) = delete;
    };
}
