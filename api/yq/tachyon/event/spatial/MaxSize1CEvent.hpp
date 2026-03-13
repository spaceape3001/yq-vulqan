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
    class MaxSize¹CEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize¹CEvent, SpatialEvent)
    public:
        MaxSize¹CEvent(const Header&, const Size1CM&);
    
        const Size1CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize¹CEvent(const Header&);
        MaxSize¹CEvent(const MaxSize¹CEvent&, const Header&);
        ~MaxSize¹CEvent();

    private:
        Size1CM  m_size = ZERO;
        
        MaxSize¹CEvent(const MaxSize¹CEvent&) = delete;
        MaxSize¹CEvent(MaxSize¹CEvent&&) = delete;
        MaxSize¹CEvent& operator=(const MaxSize¹CEvent&) = delete;
        MaxSize¹CEvent& operator=(MaxSize¹CEvent&&) = delete;
    };
}
