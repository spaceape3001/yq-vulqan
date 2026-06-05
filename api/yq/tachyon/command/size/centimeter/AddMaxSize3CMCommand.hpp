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
    class AddMaxSize³CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize³CMCommand, SizeCommand)
    public:
        AddMaxSize³CMCommand(const Header&, const Size3CM&);
    
        const Size3CM&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }
        Centimeter  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSize³CMCommand(const AddMaxSize³CMCommand&, const Header&);
        AddMaxSize³CMCommand(const Header&);
        ~AddMaxSize³CMCommand();

    private:
        Size3CM  m_Δ = ZERO;
        
        AddMaxSize³CMCommand(const AddMaxSize³CMCommand&) = delete;
        AddMaxSize³CMCommand(AddMaxSize³CMCommand&&) = delete;
        AddMaxSize³CMCommand& operator=(const AddMaxSize³CMCommand&) = delete;
        AddMaxSize³CMCommand& operator=(AddMaxSize³CMCommand&&) = delete;
    };
}
