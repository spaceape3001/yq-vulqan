////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMaxSize²DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize²DCommand, SizeCommand)
    public:
        AddMaxSize²DCommand(const Header&, const Vector2D&);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddMaxSize²DCommand(const AddMaxSize²DCommand&, const Header&);
        AddMaxSize²DCommand(const Header&);
        ~AddMaxSize²DCommand();

    private:
        Vector2D  m_Δ = ZERO;
        
        AddMaxSize²DCommand(const AddMaxSize²DCommand&) = delete;
        AddMaxSize²DCommand(AddMaxSize²DCommand&&) = delete;
        AddMaxSize²DCommand& operator=(const AddMaxSize²DCommand&) = delete;
        AddMaxSize²DCommand& operator=(AddMaxSize²DCommand&&) = delete;
    };
}
