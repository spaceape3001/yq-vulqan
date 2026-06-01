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
    class AddMinSize²MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize²MCommand, SizeCommand)
    public:
        AddMinSize²MCommand(const Header&, const Size2M&);
    
        const Size2M&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddMinSize²MCommand(const AddMinSize²MCommand&, const Header&);
        AddMinSize²MCommand(const Header&);
        ~AddMinSize²MCommand();

    private:
        Size2M  m_Δ = ZERO;
        
        AddMinSize²MCommand(const AddMinSize²MCommand&) = delete;
        AddMinSize²MCommand(AddMinSize²MCommand&&) = delete;
        AddMinSize²MCommand& operator=(const AddMinSize²MCommand&) = delete;
        AddMinSize²MCommand& operator=(AddMinSize²MCommand&&) = delete;
    };
}
