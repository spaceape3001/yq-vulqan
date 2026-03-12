////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize³DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize³DCommand, SizeCommand)
    public:
        AddMinSize³DCommand(const Header&, const Vector3D&);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSize³DCommand(const AddMinSize³DCommand&, const Header&);
        AddMinSize³DCommand(const Header&);
        ~AddMinSize³DCommand();

    private:
        Vector3D  m_Δ = ZERO;
        
        AddMinSize³DCommand(const AddMinSize³DCommand&) = delete;
        AddMinSize³DCommand(AddMinSize³DCommand&&) = delete;
        AddMinSize³DCommand& operator=(const AddMinSize³DCommand&) = delete;
        AddMinSize³DCommand& operator=(AddMinSize³DCommand&&) = delete;
    };
}
