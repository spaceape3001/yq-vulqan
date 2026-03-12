////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMaxSize³DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize³DCommand, SizeCommand)
    public:
        AddMaxSize³DCommand(const Header&, const Size3D&);
    
        const Size3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSize³DCommand(const AddMaxSize³DCommand&, const Header&);
        AddMaxSize³DCommand(const Header&);
        ~AddMaxSize³DCommand();

    private:
        Size3D  m_Δ = ZERO;
        
        AddMaxSize³DCommand(const AddMaxSize³DCommand&) = delete;
        AddMaxSize³DCommand(AddMaxSize³DCommand&&) = delete;
        AddMaxSize³DCommand& operator=(const AddMaxSize³DCommand&) = delete;
        AddMaxSize³DCommand& operator=(AddMaxSize³DCommand&&) = delete;
    };
}
