////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMaxSize²Command : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize²Command, SizeCommand)
    public:
        AddMaxSize²Command(const Header&, const Vector2D&);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddMaxSize²Command(const AddMaxSize²Command&, const Header&);
        AddMaxSize²Command(const Header&);
        ~AddMaxSize²Command();

    private:
        Vector2D  m_Δ = ZERO;
        
        AddMaxSize²Command(const AddMaxSize²Command&) = delete;
        AddMaxSize²Command(AddMaxSize²Command&&) = delete;
        AddMaxSize²Command& operator=(const AddMaxSize²Command&) = delete;
        AddMaxSize²Command& operator=(AddMaxSize²Command&&) = delete;
    };
}
