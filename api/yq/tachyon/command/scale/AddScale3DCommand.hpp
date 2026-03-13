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
    class AddScale³DCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScale³DCommand, ScaleCommand)
    public:
        AddScale³DCommand(const Header&, const Vector3D&);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScale³DCommand(const AddScale³DCommand&, const Header&);
        AddScale³DCommand(const Header&);
        ~AddScale³DCommand();

    private:
        Vector3D  m_Δ = ZERO;
        
        AddScale³DCommand(const AddScale³DCommand&) = delete;
        AddScale³DCommand(AddScale³DCommand&&) = delete;
        AddScale³DCommand& operator=(const AddScale³DCommand&) = delete;
        AddScale³DCommand& operator=(AddScale³DCommand&&) = delete;
    };
}
