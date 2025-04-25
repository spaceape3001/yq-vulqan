////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMaxSize² : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSize², SizeCommand)
    public:
        MultiplyMaxSize²(const Header&, const Vector2D&);
    
        const Vector2D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MultiplyMaxSize²(const MultiplyMaxSize²&, const Header&);
        MultiplyMaxSize²(const Header&);
        ~MultiplyMaxSize²();

    private:
        Vector2D  m_δ;
        
        MultiplyMaxSize²(const MultiplyMaxSize²&) = delete;
        MultiplyMaxSize²(MultiplyMaxSize²&&) = delete;
        MultiplyMaxSize²& operator=(const MultiplyMaxSize²&) = delete;
        MultiplyMaxSize²& operator=(MultiplyMaxSize²&&) = delete;
    };
}
