////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMaxSize²DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSize²DCommand, SizeCommand)
    public:
        MultiplyMaxSize²DCommand(const Header&, const Vector2D&);
    
        const Vector2D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MultiplyMaxSize²DCommand(const MultiplyMaxSize²DCommand&, const Header&);
        MultiplyMaxSize²DCommand(const Header&);
        ~MultiplyMaxSize²DCommand();

    private:
        Vector2D  m_δ;
        
        MultiplyMaxSize²DCommand(const MultiplyMaxSize²DCommand&) = delete;
        MultiplyMaxSize²DCommand(MultiplyMaxSize²DCommand&&) = delete;
        MultiplyMaxSize²DCommand& operator=(const MultiplyMaxSize²DCommand&) = delete;
        MultiplyMaxSize²DCommand& operator=(MultiplyMaxSize²DCommand&&) = delete;
    };
}
