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
    class AddSize²CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize²CMCommand, SizeCommand)
    public:
        AddSize²CMCommand(const Header&, const Size2CM&);
    
        const Size2CM&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddSize²CMCommand(const AddSize²CMCommand&, const Header&);
        AddSize²CMCommand(const Header&);
        ~AddSize²CMCommand();

    private:
        Size2CM  m_Δ = ZERO;
        
        AddSize²CMCommand(const AddSize²CMCommand&) = delete;
        AddSize²CMCommand(AddSize²CMCommand&&) = delete;
        AddSize²CMCommand& operator=(const AddSize²CMCommand&) = delete;
        AddSize²CMCommand& operator=(AddSize²CMCommand&&) = delete;
    };
}
