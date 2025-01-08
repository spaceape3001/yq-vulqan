////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddScale³ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddScale³, SpatialCommand)
    public:
        AddScale³(const Header&, const Vector3D&);
    
        const Vector3D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        double  z() const { return m_scale.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScale³(const AddScale³&, const Header&);
        ~AddScale³();

    private:
        Vector3D const  m_scale;
        
        AddScale³(const AddScale³&) = delete;
        AddScale³(AddScale³&&) = delete;
        AddScale³& operator=(const AddScale³&) = delete;
        AddScale³& operator=(AddScale³&&) = delete;
    };
}
