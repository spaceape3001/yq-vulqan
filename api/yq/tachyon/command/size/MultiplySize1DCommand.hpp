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
    class MultiplySize¹DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySize¹DCommand, SizeCommand)
    public:
        MultiplySize¹DCommand(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplySize¹DCommand();
        MultiplySize¹DCommand(const MultiplySize¹DCommand&, const Header&);
        MultiplySize¹DCommand(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplySize¹DCommand(const MultiplySize¹DCommand&) = delete;
        MultiplySize¹DCommand(MultiplySize¹DCommand&&) = delete;
        MultiplySize¹DCommand& operator=(const MultiplySize¹DCommand&) = delete;
        MultiplySize¹DCommand& operator=(MultiplySize¹DCommand&&) = delete;
    };
}
