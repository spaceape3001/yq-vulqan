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
    class MultiplyMaxSize²Command : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSize²Command, SizeCommand)
    public:
        MultiplyMaxSize²Command(const Header&, const Vector2D&);
    
        const Vector2D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MultiplyMaxSize²Command(const MultiplyMaxSize²Command&, const Header&);
        MultiplyMaxSize²Command(const Header&);
        ~MultiplyMaxSize²Command();

    private:
        Vector2D  m_δ;
        
        MultiplyMaxSize²Command(const MultiplyMaxSize²Command&) = delete;
        MultiplyMaxSize²Command(MultiplyMaxSize²Command&&) = delete;
        MultiplyMaxSize²Command& operator=(const MultiplyMaxSize²Command&) = delete;
        MultiplyMaxSize²Command& operator=(MultiplyMaxSize²Command&&) = delete;
    };
}
