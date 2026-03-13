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
    class MaxSize³CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize³CEvent, SpatialEvent)
    public:
        MaxSize³CEvent(const Header&, const Size3CM&);
    
        const Size3CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize³CEvent(const Header&);
        MaxSize³CEvent(const MaxSize³CEvent&, const Header&);
        ~MaxSize³CEvent();

    private:
        Size3CM  m_size = ZERO;
        
        MaxSize³CEvent(const MaxSize³CEvent&) = delete;
        MaxSize³CEvent(MaxSize³CEvent&&) = delete;
        MaxSize³CEvent& operator=(const MaxSize³CEvent&) = delete;
        MaxSize³CEvent& operator=(MaxSize³CEvent&&) = delete;
    };
}
