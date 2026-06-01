////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize³CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize³CMCommand, SizeCommand)
    public:
        AddMinSize³CMCommand(const Header&, const Size3CM&);
    
        const Size3CM&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }
        Centimeter  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSize³CMCommand(const AddMinSize³CMCommand&, const Header&);
        AddMinSize³CMCommand(const Header&);
        ~AddMinSize³CMCommand();

    private:
        Size3CM  m_Δ = ZERO;
        
        AddMinSize³CMCommand(const AddMinSize³CMCommand&) = delete;
        AddMinSize³CMCommand(AddMinSize³CMCommand&&) = delete;
        AddMinSize³CMCommand& operator=(const AddMinSize³CMCommand&) = delete;
        AddMinSize³CMCommand& operator=(AddMinSize³CMCommand&&) = delete;
    };
}
