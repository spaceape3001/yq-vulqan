////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddScale³Command : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScale³Command, ScaleCommand)
    public:
        AddScale³Command(const Header&, const Vector3D&);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScale³Command(const AddScale³Command&, const Header&);
        AddScale³Command(const Header&);
        ~AddScale³Command();

    private:
        Vector3D  m_Δ = ZERO;
        
        AddScale³Command(const AddScale³Command&) = delete;
        AddScale³Command(AddScale³Command&&) = delete;
        AddScale³Command& operator=(const AddScale³Command&) = delete;
        AddScale³Command& operator=(AddScale³Command&&) = delete;
    };
}
