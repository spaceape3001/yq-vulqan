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
    class MaxSize³CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize³CMEvent, SpatialEvent)
    public:
        MaxSize³CMEvent(const Header&, const Size3CM&);
    
        const Size3CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize³CMEvent(const Header&);
        MaxSize³CMEvent(const MaxSize³CMEvent&, const Header&);
        ~MaxSize³CMEvent();

    private:
        Size3CM  m_size = ZERO;
        
        MaxSize³CMEvent(const MaxSize³CMEvent&) = delete;
        MaxSize³CMEvent(MaxSize³CMEvent&&) = delete;
        MaxSize³CMEvent& operator=(const MaxSize³CMEvent&) = delete;
        MaxSize³CMEvent& operator=(MaxSize³CMEvent&&) = delete;
    };
}
