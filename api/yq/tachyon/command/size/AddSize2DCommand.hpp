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
    class AddSize²DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize²DCommand, SizeCommand)
    public:
        AddSize²DCommand(const Header&, const Size2D&);
    
        const Size2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddSize²DCommand(const AddSize²DCommand&, const Header&);
        AddSize²DCommand(const Header&);
        ~AddSize²DCommand();

    private:
        Size2D  m_Δ = ZERO;
        
        AddSize²DCommand(const AddSize²DCommand&) = delete;
        AddSize²DCommand(AddSize²DCommand&&) = delete;
        AddSize²DCommand& operator=(const AddSize²DCommand&) = delete;
        AddSize²DCommand& operator=(AddSize²DCommand&&) = delete;
    };
}
