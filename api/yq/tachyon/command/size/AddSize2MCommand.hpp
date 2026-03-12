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
    class AddSize²MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize²MCommand, SizeCommand)
    public:
        AddSize²MCommand(const Header&, const Size2M&);
    
        const Size2M&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddSize²MCommand(const AddSize²MCommand&, const Header&);
        AddSize²MCommand(const Header&);
        ~AddSize²MCommand();

    private:
        Size2M  m_Δ = ZERO;
        
        AddSize²MCommand(const AddSize²MCommand&) = delete;
        AddSize²MCommand(AddSize²MCommand&&) = delete;
        AddSize²MCommand& operator=(const AddSize²MCommand&) = delete;
        AddSize²MCommand& operator=(AddSize²MCommand&&) = delete;
    };
}
