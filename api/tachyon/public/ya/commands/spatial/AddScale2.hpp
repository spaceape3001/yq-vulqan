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
    class AddScale² : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddScale², SpatialCommand)
    public:
        AddScale²(const Header&, const Vector2D&);
    
        const Vector2D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddScale²(const AddScale²&, const Header&);
        ~AddScale²();

    private:
        Vector2D const  m_scale;
        
        AddScale²(const AddScale²&) = delete;
        AddScale²(AddScale²&&) = delete;
        AddScale²& operator=(const AddScale²&) = delete;
        AddScale²& operator=(AddScale²&&) = delete;
    };
}
