////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddScale²DCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScale²DCommand, ScaleCommand)
    public:
        AddScale²DCommand(const Header&, const Vector2D&);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddScale²DCommand(const AddScale²DCommand&, const Header&);
        AddScale²DCommand(const Header&);
        ~AddScale²DCommand();

    private:
        Vector2D  m_Δ = ZERO;
        
        AddScale²DCommand(const AddScale²DCommand&) = delete;
        AddScale²DCommand(AddScale²DCommand&&) = delete;
        AddScale²DCommand& operator=(const AddScale²DCommand&) = delete;
        AddScale²DCommand& operator=(AddScale²DCommand&&) = delete;
    };
}
