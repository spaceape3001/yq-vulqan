////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMaxSize² : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize², SizeCommand)
    public:
        AddMaxSize²(const Header&, const Vector2D&);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddMaxSize²(const AddMaxSize²&, const Header&);
        AddMaxSize²(const Header&);
        ~AddMaxSize²();

    private:
        Vector2D  m_Δ = ZERO;
        
        AddMaxSize²(const AddMaxSize²&) = delete;
        AddMaxSize²(AddMaxSize²&&) = delete;
        AddMaxSize²& operator=(const AddMaxSize²&) = delete;
        AddMaxSize²& operator=(AddMaxSize²&&) = delete;
    };
}
