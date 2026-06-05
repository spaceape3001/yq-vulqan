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
    class MinSize³CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MinSize³CMEvent, SpatialEvent)
    public:
        MinSize³CMEvent(const Header&, const Size3CM&);
    
        const Size3CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MinSize³CMEvent(const Header&);
        MinSize³CMEvent(const MinSize³CMEvent&, const Header&);
        ~MinSize³CMEvent();

    private:
        Size3CM  m_size = ZERO;
        
        MinSize³CMEvent(const MinSize³CMEvent&) = delete;
        MinSize³CMEvent(MinSize³CMEvent&&) = delete;
        MinSize³CMEvent& operator=(const MinSize³CMEvent&) = delete;
        MinSize³CMEvent& operator=(MinSize³CMEvent&&) = delete;
    };
}
