////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize²DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize²DCommand, SizeCommand)
    public:
        AddMinSize²DCommand(const Header&, const Size2D&);
    
        const Size2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddMinSize²DCommand(const AddMinSize²DCommand&, const Header&);
        AddMinSize²DCommand(const Header&);
        ~AddMinSize²DCommand();

    private:
        Size2D  m_Δ = ZERO;
        
        AddMinSize²DCommand(const AddMinSize²DCommand&) = delete;
        AddMinSize²DCommand(AddMinSize²DCommand&&) = delete;
        AddMinSize²DCommand& operator=(const AddMinSize²DCommand&) = delete;
        AddMinSize²DCommand& operator=(AddMinSize²DCommand&&) = delete;
    };
}
