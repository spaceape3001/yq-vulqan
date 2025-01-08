////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class MultiplyScale² : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyScale², SpatialCommand)
    public:
        MultiplyScale²(const Header&, const Vector2D&);
    
        const Vector2D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MultiplyScale²(const MultiplyScale²&, const Header&);
        ~MultiplyScale²();

    private:
        Vector2D const  m_scale;
        
        MultiplyScale²(const MultiplyScale²&) = delete;
        MultiplyScale²(MultiplyScale²&&) = delete;
        MultiplyScale²& operator=(const MultiplyScale²&) = delete;
        MultiplyScale²& operator=(MultiplyScale²&&) = delete;
    };
}
