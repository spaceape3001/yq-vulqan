////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Source resized in 3-Dimensions
    class MinSize³CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize³CEvent, SpatialEvent)
    public:
        MinSize³CEvent(const Header&, const Size3CM&);
    
        const Size3CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize³CEvent(const Header&);
        MinSize³CEvent(const MinSize³CEvent&, const Header&);
        ~MinSize³CEvent();

    private:
        Size3CM  m_size = ZERO;
        
        MinSize³CEvent(const MinSize³CEvent&) = delete;
        MinSize³CEvent(MinSize³CEvent&&) = delete;
        MinSize³CEvent& operator=(const MinSize³CEvent&) = delete;
        MinSize³CEvent& operator=(MinSize³CEvent&&) = delete;
    };
}
