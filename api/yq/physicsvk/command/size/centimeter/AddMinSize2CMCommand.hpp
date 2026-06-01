////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize²CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize²CMCommand, SizeCommand)
    public:
        AddMinSize²CMCommand(const Header&, const Size2CM&);
    
        const Size2CM&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddMinSize²CMCommand(const AddMinSize²CMCommand&, const Header&);
        AddMinSize²CMCommand(const Header&);
        ~AddMinSize²CMCommand();

    private:
        Size2CM  m_Δ = ZERO;
        
        AddMinSize²CMCommand(const AddMinSize²CMCommand&) = delete;
        AddMinSize²CMCommand(AddMinSize²CMCommand&&) = delete;
        AddMinSize²CMCommand& operator=(const AddMinSize²CMCommand&) = delete;
        AddMinSize²CMCommand& operator=(AddMinSize²CMCommand&&) = delete;
    };
}
