////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMaxSize¹DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSize¹DCommand, SizeCommand)
    public:
        MultiplyMaxSize¹DCommand(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyMaxSize¹DCommand();
        MultiplyMaxSize¹DCommand(const MultiplyMaxSize¹DCommand&, const Header&);
        MultiplyMaxSize¹DCommand(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplyMaxSize¹DCommand(const MultiplyMaxSize¹DCommand&) = delete;
        MultiplyMaxSize¹DCommand(MultiplyMaxSize¹DCommand&&) = delete;
        MultiplyMaxSize¹DCommand& operator=(const MultiplyMaxSize¹DCommand&) = delete;
        MultiplyMaxSize¹DCommand& operator=(MultiplyMaxSize¹DCommand&&) = delete;
    };
}
