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
    class AddSize³CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize³CMCommand, SizeCommand)
    public:
        AddSize³CMCommand(const Header&, const Size3CM&);
    
        const Size3CM&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }
        Centimeter  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSize³CMCommand(const AddSize³CMCommand&, const Header&);
        AddSize³CMCommand(const Header&);
        ~AddSize³CMCommand();

    private:
        Size3CM  m_Δ = ZERO;
        
        AddSize³CMCommand(const AddSize³CMCommand&) = delete;
        AddSize³CMCommand(AddSize³CMCommand&&) = delete;
        AddSize³CMCommand& operator=(const AddSize³CMCommand&) = delete;
        AddSize³CMCommand& operator=(AddSize³CMCommand&&) = delete;
    };
}
