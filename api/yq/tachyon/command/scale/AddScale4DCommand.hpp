////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddScale⁴DCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScale⁴DCommand, ScaleCommand)
    public:
        AddScale⁴DCommand(const Header&, const Vector4D&);
    
        const Vector4D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δw() const { return m_Δ.w; }
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScale⁴DCommand(const AddScale⁴DCommand&, const Header&);
        AddScale⁴DCommand(const Header&);
        ~AddScale⁴DCommand();

    private:
        Vector4D  m_Δ = ZERO;
        
        AddScale⁴DCommand(const AddScale⁴DCommand&) = delete;
        AddScale⁴DCommand(AddScale⁴DCommand&&) = delete;
        AddScale⁴DCommand& operator=(const AddScale⁴DCommand&) = delete;
        AddScale⁴DCommand& operator=(AddScale⁴DCommand&&) = delete;
    };
}
