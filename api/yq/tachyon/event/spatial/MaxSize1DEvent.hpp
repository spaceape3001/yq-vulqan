////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Source resized in 1-Dimension
    class MaxSize¹DEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize¹DEvent, SpatialEvent)
    public:
        MaxSize¹DEvent(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize¹DEvent(const Header&);
        MaxSize¹DEvent(const MaxSize¹DEvent&, const Header&);
        ~MaxSize¹DEvent();

    private:
        Size1D  m_size = ZERO;
        
        MaxSize¹DEvent(const MaxSize¹DEvent&) = delete;
        MaxSize¹DEvent(MaxSize¹DEvent&&) = delete;
        MaxSize¹DEvent& operator=(const MaxSize¹DEvent&) = delete;
        MaxSize¹DEvent& operator=(MaxSize¹DEvent&&) = delete;
    };
}
