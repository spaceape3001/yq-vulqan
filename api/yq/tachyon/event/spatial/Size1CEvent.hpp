////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Source resized in 1-Dimension
    class Size¹CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size¹CEvent, SpatialEvent)
    public:
        Size¹CEvent(const Header&, const Size1CM&);
    
        const Size1CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size¹CEvent(const Header&);
        Size¹CEvent(const Size¹CEvent&, const Header&);
        ~Size¹CEvent();

    private:
        Size1CM  m_size = ZERO;
        
        Size¹CEvent(const Size¹CEvent&) = delete;
        Size¹CEvent(Size¹CEvent&&) = delete;
        Size¹CEvent& operator=(const Size¹CEvent&) = delete;
        Size¹CEvent& operator=(Size¹CEvent&&) = delete;
    };
}
