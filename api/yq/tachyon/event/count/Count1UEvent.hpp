////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Source moved in 1-Dimension
    class Count¹UEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Count¹UEvent, SpatialEvent)
    public:
        Count¹UEvent(const Header&, const Vector1U&);
    
        const Vector1U&   count() const  { return m_count; }
        
        static void init_meta();
        
        Vector1U  x() const { return m_count.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Count¹UEvent(const Header&);
        Count¹UEvent(const Count¹UEvent&, const Header&);
        ~Count¹UEvent();

    private:
        Vector1U   m_count = ZERO;
        
        Count¹UEvent(const Count¹UEvent&) = delete;
        Count¹UEvent(Count¹UEvent&&) = delete;
        Count¹UEvent& operator=(const Count¹UEvent&) = delete;
        Count¹UEvent& operator=(Count¹UEvent&&) = delete;
    };
}
