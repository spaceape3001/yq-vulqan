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
    class AddSize³DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize³DCommand, SizeCommand)
    public:
        AddSize³DCommand(const Header&, const Vector3D&);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSize³DCommand(const AddSize³DCommand&, const Header&);
        AddSize³DCommand(const Header&);
        ~AddSize³DCommand();

    private:
        Vector3D  m_Δ = ZERO;
        
        AddSize³DCommand(const AddSize³DCommand&) = delete;
        AddSize³DCommand(AddSize³DCommand&&) = delete;
        AddSize³DCommand& operator=(const AddSize³DCommand&) = delete;
        AddSize³DCommand& operator=(AddSize³DCommand&&) = delete;
    };
}
