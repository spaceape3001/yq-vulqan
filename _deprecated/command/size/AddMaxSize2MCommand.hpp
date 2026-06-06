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
    class AddMaxSize²MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize²MCommand, SizeCommand)
    public:
        AddMaxSize²MCommand(const Header&, const Size2M&);
    
        const Size2M&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddMaxSize²MCommand(const AddMaxSize²MCommand&, const Header&);
        AddMaxSize²MCommand(const Header&);
        ~AddMaxSize²MCommand();

    private:
        Size2M  m_Δ = ZERO;
        
        AddMaxSize²MCommand(const AddMaxSize²MCommand&) = delete;
        AddMaxSize²MCommand(AddMaxSize²MCommand&&) = delete;
        AddMaxSize²MCommand& operator=(const AddMaxSize²MCommand&) = delete;
        AddMaxSize²MCommand& operator=(AddMaxSize²MCommand&&) = delete;
    };
}
