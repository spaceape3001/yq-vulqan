////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/unit/declare.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize¹MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize¹MCommand, SizeCommand)
    public:
        AddMinSize¹MCommand(const Header&, const Size1D&);
    
        const Size1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddMinSize¹MCommand();
        AddMinSize¹MCommand(const AddMinSize¹MCommand&, const Header&);
        AddMinSize¹MCommand(const Header&);

    private:
        Size1D  m_Δ = ZERO;
        
        AddMinSize¹MCommand(const AddMinSize¹MCommand&) = delete;
        AddMinSize¹MCommand(AddMinSize¹MCommand&&) = delete;
        AddMinSize¹MCommand& operator=(const AddMinSize¹MCommand&) = delete;
        AddMinSize¹MCommand& operator=(AddMinSize¹MCommand&&) = delete;
    };
}
